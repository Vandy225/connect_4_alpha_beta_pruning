//-- Header file for the configuration object

#ifndef CONFIGURATION_H
#define CONFIGURATION_H


#include <iostream>


class Configuration {

//-- public members
public:
	//constructor
	Configuration();

	//function to add a token to the board
	void add_token();

	//destructor
	~Configuration();

	//function to print the current configuration
	void print_configuration();

	//overloaded =operator
	Configuration operator=(const Configuration&);

	//function to modify the board state
	void modify_board(int position, char token);
	//function to see if a board modification is valid
	bool is_valid(int position);

	//function to determine if the game is over
	bool game_over();

	//function that checks if the current token placement is out of bounds or not
	bool not_out_of_bounds(int x, int y);

	//getter function for the most recent placement's x value
	int get_most_recent_x();
	//getter function for the most recent placement's y value
	int get_most_recent_y();
	//getter function to get the token of the last played token
	char get_token();
	//function that calculates the utility of a terminal node
	int utility();
	//function to determine if the board is full
	bool full_board();
protected:
//-- private members
private:
	//array for the board size --> 6 rows, 7 columns
	char game_board[6][7];

	//ints for the position of the most recent modification to the board
	int most_recent_x;
	int most_recent_y;
	char most_recent_token;

};




#endif