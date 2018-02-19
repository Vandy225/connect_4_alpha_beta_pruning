#ifndef CONFIGURATION_H
#define CONFIGURATION_H


#include <iostream>


class Configuration {

public:
	Configuration();

	//function to add a token to the board
	void add_token();

	~Configuration();

	//function to print the current configuration
	void print_configuration();

	//overloaded =operator

	Configuration& operator=(const Configuration&);

	//function to modify the board state
	void modify_board(int position, char token);
	//function to see if a board modification is valid
	bool is_valid(int position);

	//function to determine if the game is over
	bool game_over();

	bool not_out_of_bounds(int x, int y);



protected:
private:
	//array for the board size
	char game_board[6][7];

	//char to represent the current player
	//char current_player;

	//ints for the position of the most recent modification to the board
	int most_recent_x;
	int most_recent_y;
	char most_recent_token;


};




#endif