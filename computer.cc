
//-- Implementation file for the computer player class object

#include "computer.h"




//----------------------------------------------------------------------------------------------------------------------
//-- Constructor for the computer player
//
//-- Arguments:
//
//	 Configuration * game_board --> represents the current state of the game's board (placement of markers)
//
//	 char token --> represents the marker that will be displayed for the Computer player when making moves
//
// 	 The constructor for the Player object is called with the token argument to initialize this member in the derived
//	 Computer object
//----------------------------------------------------------------------------------------------------------------------
Computer::Computer (Configuration* game_board, char token) : Player(token){
	//set the game_board member of the Computer object to be the argument
	this->game_board = game_board;
}


//destructor, does nothing because no dynamic memory allocation here
Computer::~Computer(){
}

//----------------------------------------------------------------------------------------------------------------------
//-- Function for the computer player to decide what move to make. Considers all of the possible moves it can make from
//	 the current board configuration and (through recursive calls to alpha_beta()) decides on the optimal placement of
//	 its marker depending on whether it is the MIN player or the MAX player.
//
//-- Arguments:
//
//	 None, function called on Computer object
//
//-- Return type:
//
//				int, representing the place where it thinks it should place its token
//----------------------------------------------------------------------------------------------------------------------
int Computer::make_move(){
	//declare an array that will hold the values of the possible moves at this point
	int move_values[6];
	//increment the turn number to feed into alpha_beta
	turn_number+=1;
	//consider each move and run alpha-beta on that in order to determine what the score for each of the possible 6 moves is
	for (int i =0; i < 7; i++){
		//have a temporary board that will hold what the current possible move looks like
		Configuration temp_board = *(this->game_board);
		//if we had a valid move and the player was A:
		if(temp_board.is_valid(i) && this->token == 'A'){
			//make the move
			temp_board.modify_board(i, this->token);
			//set the value of the move in the move_values array to the recursive call to alpha_beta, gives value for that move
			//we want to know what the best move for this player is, so we will use true to get alpha-beta to do the MAX route
			move_values[i] += alpha_beta(temp_board, turn_number, INT_MIN, INT_MAX, true); //maybe true
		}
		//do the same thing if the player was B
		else if (temp_board.is_valid(i) && this->token == 'B'){
			temp_board.modify_board(i, this->token);
			//use the MIN route of alpha_beta
			move_values[i] -= alpha_beta(temp_board, turn_number, INT_MIN, INT_MAX, false); //maybe false
		}
		//invalid move
		else {
			//set the value of the score array to a flag value to indicate that a bad move happened, 
			//don't use this position when considering next possible moves
			move_values[i] = INT_MAX;
		}

	}
	//if we are the maximizing player (first player)
	if (this->token == 'A'){
		//initialize the value in the move array to be the worst thing for the MAX player
		int max_value=INT_MIN;
		//declare variable to hold the index of the best move
		int max_index=0;
		//for all possible moves given this configuration
		for (int i = 0; i < 7; i++){
			//check to see if there is move that was found that is better than the worst value (INT_MIN)
			//also make sure it is not the flag value
			if(move_values[i] > max_value && move_values[i] != INT_MAX){
				//set max_value to be this new found move
				max_value = move_values[i];
				//grab the index of this move
				max_index = i;
			}

		}
		//found the best move, return the index
		return max_index;
	}
	//do the same thing for the minimizing player
	else if (this->token == 'B'){
		//set the min value to the worst thing for the minimizing player (INT_MAX)
		int min_value=INT_MAX;
		//variable to hold the min_index
		int min_index=0;
		//check all the moves at this current configuration
		for(int i =0; i < 7; i++){
			//if a new move has a lower value than the worst posible thing (INT_MAX) and it is not the flag value
			if(move_values[i] < min_value && move_values[i] != INT_MAX){
				//set the new min value
				min_value = move_values[i];
				//grab the index of this min move
				min_index = i;
			}
		}
		//found the minimized move, return the index
		return min_index;
	}
	//safety condition to make sure that the token was read correctly
	else {
		std::cout << "token not read correctly";
		exit(1);
	}

}
//----------------------------------------------------------------------------------------------------------------------
//-- Function to use alpha-beta pruning to determine which move to make. Rather than splitting out the functionality
//	 into MAX and MIN functions, this function just uses a boolean value to change the behaviour of the function to be 
// 	 MIN or MAX
//
//-- Arguments:
//
//	 Configuration game_board --> Configuration object representing the current state of the game
//
//	 int depth --> represents what depth we are in the tree of moves. Should never be more than 42.
//
//	 int alpha --> represents the upper bound for a decision level
//
//	 int beta --> represents the lower bound for a decision level
//
//	 bool current_player --> tells us which player it is (player one or player two)
//
//-- Return type:
//
//				int, representing the value of a move (0, 1 ,-1) 
//----------------------------------------------------------------------------------------------------------------------
int Computer::alpha_beta(Configuration game_board, int depth, int alpha, int beta, bool current_player){
	//check to see if we are terminal node or if we have reached max depth or the board is full
	if(depth == 42){
		//return the utility of the game board
		return game_board.utility();
	}
	//check if the game is over
	if (game_board.game_over() ){
		//if so, return the utility of that node
		return game_board.utility();
	}
	//check if the board is full
	if (game_board.full_board()) {
		//return utility
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
				//get the value of the move here, which should be the max between the current value and any other moves
				value = std::max(value, alpha_beta(temp_board, depth+1 ,alpha, beta, !current_player));
				//set alpha to this new max
				alpha =  std::max(alpha, value);
			}
			//if value is greater than beta, min won't let us choose the move. Prune.
			if( value >= beta){
				return value;
				break;
			}
			//else keep going
			else {
				continue;
			}
		}
		//found the value of the node, return it
		return value;

	}
	//else we are the minimizing player
	else {
		int value = INT_MAX;
		//for each possible move at the current configuration
		for (int i =0; i < 7; i++){
			//make a temporary board to hold the new game state
			Configuration temp_board = game_board;
			//check if the move is valid
			if(temp_board.is_valid(i)){
				//if the move is valid, modify the temporary board
				temp_board.modify_board(i, this->token);
				//since we are the min player, we want the minimum value that comes out of the recursion
				value = std::min(value, alpha_beta(temp_board, depth+1, alpha, beta, !current_player));
				//set beta to this new minimum
				beta =  std::min(beta, value);
			}
			//if the value is less than alpha, max won't choose it. Prune
			if( value <= alpha){
				return value;
				break;
			}
			//else keep going
			else {
				continue;
			}
			
		}
		//found the min value, return it
		return value;

	}
}
