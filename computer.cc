#include "computer.h"






Computer::Computer (Configuration* game_board, char token) : Player(token){

	
	
	this->game_board = game_board;



}


Computer::~Computer(){

}


int Computer::make_move(){

	//need to use alph-beta and the utility function


	int move_values[6];

	turn_number+=1;


	//consider each move and run minimax on that in order to get the 
	for (int i =0; i < 7; i++){
		Configuration temp_board = *(this->game_board);
		//we had a valid move
		if(temp_board.is_valid(i) && this->token == 'A'){
			temp_board.modify_board(i, this->token);

			move_values[i] = alpha_beta(temp_board, 42-turn_number , INT_MIN, INT_MAX, true);
		}
		else if (temp_board.is_valid(i) && this->token == 'B'){
			temp_board.modify_board(i, this->token);
			move_values[i] = alpha_beta(temp_board, 42-turn_number , INT_MIN, INT_MAX, false);

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


int Computer::alpha_beta(Configuration game_board, int depth, int alpha, int beta, bool maximizingPlayer){
	if (game_board.game_over() || depth == 42 || game_board.full_board()){
		return game_board.utility();
	}
	if(maximizingPlayer){
		int value = INT_MIN;
		//for each child of node
		for (int i =0; i < 7; i++){
			Configuration temp_board = game_board;
			if(temp_board.is_valid(i)){
				temp_board.modify_board(i, this->token);
				value = std::max(value, alpha_beta(temp_board, depth+1 ,alpha, beta, !maximizingPlayer));
				alpha =  std::max(alpha, value);
			}
			if( value > beta){
				break;
			}
			else {
				continue;
			}

		}
		return value;

	}
	else {
		int value = INT_MAX;
		//for each child of node
		for (int i =0; i < 7; i++){
			Configuration temp_board = game_board;
			if(temp_board.is_valid(i)){
				temp_board.modify_board(i, this->token);
				value = std::min(value, alpha_beta(temp_board, depth+1, alpha, beta, !maximizingPlayer));
				beta =  std::min(beta, value);
			}
			if( value < alpha){
				break;
			}
			else {
				continue;
			}
			
		

		}

		return value;

	}
}



/*

Pseudo Code

function alphabeta(node, depth, α, β, maximizingPlayer)
02      if depth = 0 or node is a terminal node
03          return the heuristic value of node
04      if maximizingPlayer
05          v := -∞
06          for each child of node
07              v := max(v, alphabeta(child, depth – 1, α, β, FALSE))
08              α := max(α, v)
09              if β ≤ α
10                  break (* β cut-off *)
11          return v
12      else
13          v := +∞
14          for each child of node
15              v := min(v, alphabeta(child, depth – 1, α, β, TRUE))
16              β := min(β, v)
17              if β ≤ α
18                  break (* α cut-off *)
19          return v
*/