//-- Implementation file for the Configuration class

#include "configuration.h"

//----------------------------------------------------------------------------------------------------------------------
//-- Configuration constructor. Makes a char arry of size 6 X 7 and fills it with ' '.
//
//-- Arguments:
//
//	 None, it is a constructor
//
//-- Return type:
//
//				 Configuration type object
//----------------------------------------------------------------------------------------------------------------------
Configuration::Configuration(){
		//initialize the members of the game_board object to all 0's
		for(int i =0; i < 6; i++){
			//std::cout << "working on row " << i <<"\n";
			for(int j =0; j < 7; j++){
				//std::cout << "working on column " << j << "\n";
				this->game_board[i][j] = ' ';
			}
		}
}

//----------------------------------------------------------------------------------------------------------------------
//-- Configuration destructor
//
//-- Arguments:
//
//	 None
//
//-- Return type:
//
//				 Nothing
//----------------------------------------------------------------------------------------------------------------------
Configuration::~Configuration(){
	/*
	for (int i = 0; i < 6; i++){
		delete[] this->game_board[i];
	}
	delete[] this->game_board;*/
}

//----------------------------------------------------------------------------------------------------------------------
//-- Function that modifies the placement of tokens in a configuration object based on a position and 
//	 the token passed in. Also modifies the private members of the board configuration object to indicate
//	 what the last move was.
//
//-- Arguments:
//
//	 int position --> denotes the y position of the token where it will be dropped
//
// 	 char token --> represents the token that should occupy the space
//
//-- Return type:
//
//	 			 void, only modifies the game board 
//----------------------------------------------------------------------------------------------------------------------
void Configuration::modify_board(int position, char token){
	//go through all of the rows
	for(int r = 5; r >=0; r--){
		if (this->game_board[r][position] == ' '){
			//set the position with the token
			this->game_board[r][position] = token;
			//set the members of the Configuration object to remember the last move
			this->most_recent_x = r;
			this->most_recent_y = position;
			this->most_recent_token = token;
			//once we have placed the token, stop
			break;
		}
	}



}

//----------------------------------------------------------------------------------------------------------------------
//-- Function that prints out the current board 
//
//-- Arguments:
//				
//	 None
//
//-- Return type:
//
//	 	 		void        
//----------------------------------------------------------------------------------------------------------------------
void Configuration::print_configuration(){
		//print the column number
		printf(" 0 1 2 3 4 5 6");
		//for each row
		for (int i =0; i < 6; i++){
			//make a space
			printf("\n");
			//for each column
			for(int j=0; j < 7; j++){
				//print a divider
				printf("|");
				//print the character that resides in game_board[i][j]
				printf("%c", this->game_board[i][j]);

			}
			//print a divider
			printf("|");
		}

		//make a space
		printf("\n");
		//close the bottom of the board
		printf("==============");
		//make a space
		printf("\n");
	}
//----------------------------------------------------------------------------------------------------------------------
//-- Function that checks to make sure that a token placement is within the bounds of the board and that the space is
//	 empty
//
//-- Arguments:
//
//	 int y_position --> the y position that the player wants to drop their token
//
//-- Return type:
//
//	 	         bool, indicating if the move was valid or not
//----------------------------------------------------------------------------------------------------------------------
bool Configuration::is_valid(int y_position){
	//if the highest element in a column is empty, the move is valid
	//also as long as the move is in range we are good
	if(this->game_board[0][y_position] == ' ' && y_position >=0 && y_position < 7){
		//if good, return true
		return true;

	} 
	else {
		//if not, it was not a valid move
		return false;
	}
}


//----------------------------------------------------------------------------------------------------------------------
//-- Function to set one Configuration object equal to another. Really only modifies the game_board member.
//
//-- Arguments:
//
//	 A reference to a Configuration object
//
//-- Return type:
//
//	 	         Configuration object
//----------------------------------------------------------------------------------------------------------------------
Configuration Configuration::operator=(const Configuration& right_operand){
	
	//temp to hold returned board	
	Configuration returned;

	//iterate through elements and set the contents of the game_board member
	for(int i=0; i < 6; i++){
		for (int j=0; j < 7; j++){
			returned.game_board[i][j] = right_operand.game_board[i][j];
		}
	}
	//hand back the new board
	return returned;
}

//----------------------------------------------------------------------------------------------------------------------
//-- Function to determine if the game has ended or not. Counts the number of tokens in all of the directions (up/down, left/right, 
//   left diagonal/right diagonal)
//
//-- Arguments:
//
//	 none, called implicitly on the Configuration object
//
//-- Return type:
//
//	 	         bool to indicate if the game si over or not
//----------------------------------------------------------------------------------------------------------------------
bool Configuration::game_over(){


	//declare some local variables derived from the Configuration object for iterating through lines
	//we want to know the location of the most recent move, denoted with last_x and last_y
	int last_x = this->most_recent_x;
	int last_y = this->most_recent_y;
	char token = this->most_recent_token;

	//first, lets search up/down, left, right

	//variables to iterate through lines
	int search_x = last_x;
	int search_y = last_y;

	//start with none in a row
	int num_in_a_row = 0;

	
	//search up first
	for(int i =0; i < 4; i++){
		//make sure that we have not gone out of bounds on the search and that we are looking at the same token
		if(not_out_of_bounds(search_x, search_y) && this->game_board[search_x][search_y] == token){
			num_in_a_row++;
			//going up
			search_x--;
			
		}
	}
	search_x = last_x+1;
	search_y = last_y;
	//now search down
	for(int i =0; i < 3; i++){
		if(not_out_of_bounds(search_x, search_y) && this->game_board[search_x][search_y] == token){
			num_in_a_row++;
			//going down
			search_x++;
		}
	}
	//if we found 4 in a row, return true because the game is over
	if(num_in_a_row >= 4){
		//std::cout << "win!\n";
		return true;
	}
	//start again, check left/right
	num_in_a_row =0;
	search_x = last_x;
	search_y = last_y;
	//check left
	for(int i =0; i < 4; i++){
		if(not_out_of_bounds(search_x, search_y) && this->game_board[search_x][search_y] == token){
			num_in_a_row++;
			//going left
			search_y--;
		}
	}
	search_x = last_x;
	search_y = last_y+1;
	//now search right
	for(int i =0; i < 3; i++){
		if(not_out_of_bounds(search_x, search_y) && this->game_board[search_x][search_y] == token){
			num_in_a_row++;
			//going right
			search_y++;
		}
	}
	if(num_in_a_row >= 4){
		return true;
	}
	//start again, check left diagonal
	num_in_a_row =0;
	search_x = last_x;
	search_y = last_y;

	for(int i =0; i < 4; i++){
		if(not_out_of_bounds(search_x, search_y) && this->game_board[search_x][search_y] == token){
			num_in_a_row++;
			//going up
			search_x--;
			search_y--;
		}
	}
	search_x = last_x+1;
	search_y = last_y+1;
	//now search down
	for(int i =0; i < 3; i++){
		if(not_out_of_bounds(search_x, search_y) && this->game_board[search_x][search_y] == token){
			num_in_a_row++;
			//going down
			search_x++;
			search_y++;
		}
	}
	if(num_in_a_row >= 4){
		return true;
	}

	//start again, check right diagonal
	num_in_a_row =0;
	search_x = last_x;
	search_y = last_y;


	for(int i =0; i < 4; i++){
		if(not_out_of_bounds(search_x, search_y) && this->game_board[search_x][search_y] == token){
			num_in_a_row++;
			//going up
			search_x--;
			search_y++;
		}
	}
	search_x = last_x+1;
	search_y = last_y-1;
	//now search down
	for(int i =0; i < 3; i++){
		if(not_out_of_bounds(search_x, search_y) && this->game_board[search_x][search_y] == token){
			num_in_a_row++;
			//going down
			search_x++;
			search_y--;
		}
	}
	if(num_in_a_row >= 4){
		return true;
	}

	//if we did not find 4 in a row, the game is not over
	return false;
}

//----------------------------------------------------------------------------------------------------------------------
//-- Function to make sure that when searching for a game over that we do not go out of bounds looking for tokens
//
//-- Arguments:
//
//	 int x --> represents the current x position of the search
//
//	 int y --> represents the current 7 position of the search
//
//-- Return type:
//
//	 	         bool to indicate if we went out of bounds
//----------------------------------------------------------------------------------------------------------------------
bool Configuration::not_out_of_bounds(int x, int y){
	//checks to make sure that we don't blow over on row or column search
	if(x < 0 || x > 5 || y < 0 || y > 6){
		//if any of those are true, this is out of bounds
		return false;

	}
	//otherwise it is in bounds
	else {
		return true;
	}
}
//----------------------------------------------------------------------------------------------------------------------
//-- Function to get the most_recent_x private member
//
//-- Arguments:
//
//	 none
//
//-- Return type:
//
//	 	 		 int        
//----------------------------------------------------------------------------------------------------------------------
int Configuration::get_most_recent_x(){
	//return member
	return this->most_recent_x;
}
//----------------------------------------------------------------------------------------------------------------------
//-- Function to get the most_recent_y
//
//-- Arguments:
//
//-- Return type:
//
//	 	         int
//----------------------------------------------------------------------------------------------------------------------
int Configuration::get_most_recent_y(){
	return this->most_recent_y;
}
//----------------------------------------------------------------------------------------------------------------------
//-- Function to get the current token
//
//-- Arguments:
//
//	 none
//
//-- Return type:
//
//	 	         char
//----------------------------------------------------------------------------------------------------------------------
char Configuration::get_token(){
	return this->most_recent_token;
}

//----------------------------------------------------------------------------------------------------------------------
//-- Function that determines the utility of a board based on whether A won or not
//
//-- Arguments:
//
//	 none, called on the Configuration object
//
//-- Return type:
//
//	 	         int, representing the value of this board to the minimizing/maximizing player
//----------------------------------------------------------------------------------------------------------------------
int Configuration::utility(){
	//if the first player won, return 1
	if(this->game_over() && this->most_recent_token == 'A'){
		return 1;
	}
	//if the second player won, return -1
	else if (this->game_over() && this->most_recent_token == 'B'){
		return -1;

	}
	//if it is a draw
	else if (this->full_board()){
		return 0;
	}
}
//----------------------------------------------------------------------------------------------------------------------
//-- Function to determine if the board is full. If this happens, the game is a draw
//
//-- Arguments:
//
//	 none, called on the Configuration object
//
//-- Return type:
//
//	 	         bool, indicating if the board is full or not
//----------------------------------------------------------------------------------------------------------------------
bool Configuration::full_board(){
//check top element of every column at row position 0
for (int i=0; i < 7; i++){
	//if the space is blank, the board is not full
	if(this->game_board[0][i] == ' '){
		//so return false
		return false;
	}
	//else{
	//	return true;
	//}
}	

//otherwise, the board is full, return true
return true;

}