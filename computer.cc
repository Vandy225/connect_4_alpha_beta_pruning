
//-- Implementation file for the computer player class object

#include "computer.h"





//constructor for the computer player
//takes a pointer to a game_board and a token as a parameters, calls the player constructor for other methods
Computer::Computer (Configuration* game_board, char token) : Player(token){

	
	//set the game_board member 
	this->game_board = game_board;



}


//destructor, does nothing because no dynamic memory
Computer::~Computer(){

}


//this function is for the computer player to decide what move to make
int Computer::make_move(){

	//need to use alph-beta and the utility function

	//declare an array that will hold the values of the possible moves
	int move_values[6];

	//increment the turn number to feed into alpha_beta
	turn_number+=1;


	//consider each move and run alpha-beta on that in order to determine what the score for each of the possible 6 moves is
	for (int i =0; i < 7; i++){
		//have a temporary board that will hold what the current move looks like
		Configuration temp_board = *(this->game_board);
		//if we had a valid move and the player was A:
		if(temp_board.is_valid(i) && this->token == 'A'){
			//make the move
			temp_board.modify_board(i, this->token);
			//set the value of the move in the move_values array to the recursive call to alpha_beta
			move_values[i] = alpha_beta(temp_board, turn_number, INT_MIN, INT_MAX, true); // maybe needs to be 42-turn_number
		}
		//do the same thing if the player was B
		else if (temp_board.is_valid(i) && this->token == 'B'){
			temp_board.modify_board(i, this->token);
			move_values[i] = alpha_beta(temp_board, turn_number, INT_MIN, INT_MAX, false);// maybe needs to be 42-turn_number

		}
		//invalid move
		else {
			move_values[i] = INT_MAX;
		}



	}
	if (this->token == 'A'){
		int max_value=INT_MIN;
		int max_index=0;
		for (int i = 0; i < 7; i++){
			if(move_values[i] > max_value && move_values[i] != INT_MAX){
				max_value = move_values[i];
				max_index = i;
			}

		}
		return max_index;

	}
	else if (this->token == 'B'){
		int min_value=INT_MAX;
		int min_index=0;
		for(int i =0; i < 7; i++){
			if(move_values[i] < min_value && move_values[i] != INT_MAX){
				min_value = move_values[i];
				min_index = i;
			}
		}
		return min_index;
	}
	else {
		std::cout << "token not read correctly";
		exit(0);
	}

}

//changed depth
int Computer::alpha_beta(Configuration game_board, int depth, int alpha, int beta, bool current_player){
	//check to see if we are terminal node or if we have reached max depth or the board is full
	if(depth == 42){
		std::cout << "depth trigger" << std::endl;
		return game_board.utility();
	}
	if (game_board.game_over() ){
		//if so, return the utility of that node
		std::cout << "game over trigger" << std::endl;
		return game_board.utility();
	}
	
	if (game_board.full_board()) {
		std::cout << "full board trigger" << std::endl;
		return game_board.utility();
	}
	//if we are the maximizing player
	if(current_player){
		//set value to worst possible value
		int value = INT_MIN;
		//for each possible move:
		for (int i =0; i < 7; i++){
			//make a temporary board to pass down for recursion
			Configuration temp_board = game_board;
			//check if the move is valid
			if(temp_board.is_valid(i)){
				//if the move was valid, make the move with the current token
				temp_board.modify_board(i, this->token);
				value = std::max(value, alpha_beta(temp_board, depth+1 ,alpha, beta, !current_player));
				alpha =  std::max(alpha, value);
			}
			if( value >= beta){
				break;
			}
			else {
				continue;
			}

		}
		return value;

	}
	//else we are the minimizing player
	else {
		int value = INT_MAX;
		//for each child of node
		for (int i =0; i < 7; i++){
			Configuration temp_board = game_board;
			if(temp_board.is_valid(i)){
				temp_board.modify_board(i, this->token);
				value = std::min(value, alpha_beta(temp_board, depth+1, alpha, beta, !current_player));
				beta =  std::min(beta, value);
			}
			if( value <= alpha){
				break;
			}
			else {
				continue;
			}
			
		

		}

		return value;

	}
}
