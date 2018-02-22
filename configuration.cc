//-- Implementation file for the Configuration class

#include "configuration.h"

//----------------------------------------------------------------------------------------------------------------------
//configuration constructor
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
//configuration destructor
//----------------------------------------------------------------------------------------------------------------------
Configuration::~Configuration(){
	/*
	for (int i = 0; i < 6; i++){
		delete[] this->game_board[i];
	}
	delete[] this->game_board;*/
}

//----------------------------------------------------------------------------------------------------------------------
//function that makes a move
//----------------------------------------------------------------------------------------------------------------------
void Configuration::modify_board(int position, char token){
	for(int r = 5; r >=0; r--){
		if (this->game_board[r][position] == ' '){
			//std::cout << "Placing at r= " << r << " c= " << position << std::endl;
			this->game_board[r][position] = token;
			this->most_recent_x = r;
			this->most_recent_y = position;
			this->most_recent_token = token;
			break;
		}
	}



}

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
void Configuration::print_configuration(){

		printf(" 0 1 2 3 4 5 6");

		for (int i =0; i < 6; i++){
			printf("\n");
			
			for(int j=0; j < 7; j++){
				printf("|");
				printf("%c", this->game_board[i][j]);

			}
			printf("|");
		}


		printf("\n");

		printf("==============");

		printf("\n");


	}
//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
bool Configuration::is_valid(int y_position){
	//if the highest element in a column is empty, the move is valid
	//also as long as the move is in range we are good
	if(this->game_board[0][y_position] == ' ' && y_position >=0 && y_position < 7){
		return true;

	} 
	else {
		return false;
	}
}


//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
Configuration Configuration::operator=(const Configuration& right_operand){
	
	//temp to hold returned board	
	Configuration returned;

	//iterate through elements and set
	for(int i=0; i < 6; i++){
		for (int j=0; j < 7; j++){
			returned.game_board[i][j] = right_operand.game_board[i][j];
		}
	}
	//hand back the new board
	return returned;
}

//----------------------------------------------------------------------------------------------------------------------
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

	
	return false;
}

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
bool Configuration::not_out_of_bounds(int x, int y){
	if(x < 0 || x > 5 || y < 0 || y > 6){
		return false;

	}
	else {
		return true;
	}
}
//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
int Configuration::get_most_recent_x(){
	return this->most_recent_x;
}
//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
int Configuration::get_most_recent_y(){
	return this->most_recent_y;
}
//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
char Configuration::get_token(){
	return this->most_recent_token;
}

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
int Configuration::utility(){
	//if the first player won, return 1
	if(this->game_over() && this->most_recent_token == 'A'){
		//std::cout << "returned 1" << std::endl;
		return 1;
	}
	//if the second player won, return -1
	else if (this->game_over() && this->most_recent_token == 'B'){
		//std::cout << "returned -1" << std::endl;
		return -1;

	}
	//if it is a draw
	else if (this->full_board()){
		//std::cout << "returned 0" << std::endl;
		return 0;
	}
}
//----------------------------------------------------------------------------------------------------------------------
//function that checks to see if 
//----------------------------------------------------------------------------------------------------------------------
bool Configuration::full_board(){


for (int i=0; i < 7; i++){
	if(this->game_board[0][i] == ' '){
		return false;
	}
	//else{
	//	return true;
	//}
}	

return true;

}