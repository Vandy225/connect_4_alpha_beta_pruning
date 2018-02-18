#include "configuration.h"

Configuration::Configuration(char current_player){

	//int *game_board = new int[6];

	for (int i=0; i < 6; i++){
		this->game_board[i] = new int[7];
	}

	//initialize the 
	this->current_player = current_player;
	//this->game_board = game_board;

		//initialize the members of the game_board object
		for(int i =0; i < 6; i++){
			for(int j =0; j < 7; j++){
				this->game_board[i][j] = 0;
			}
		}
}

Configuration::~Configuration(){
	for (int i = 0; i < 6; i++){
		delete[] this->game_board[i];
	}
	delete[] this->game_board;
}
