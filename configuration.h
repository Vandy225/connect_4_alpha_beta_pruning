#ifndef CONFIGURATION_H
#define CONFIGURATION_H


#include <iostream>


class Configuration {

public:
	Configuration(char current_player);

	//function to make a move
	Configuration make_move();

	~Configuration();

	//function to print the current configuration
	void print_configuration(){

		printf("--------------------------------");
		printf("|\n|\n|\n|\n|\n|\n|\n");

		for (int i =0; i < 6; i++){
			printf("----------------------------------");
			for(int j=0; j < 7; j++){
				printf("| ");
				printf("%i", this->game_board[i][j]);
				printf(" |");



			}
		}


	}



protected:
private:
	//array for the board size
	int** game_board;

	//char to represent the current player
	char current_player;


};




#endif