//-- Header file for the Computer player objects

#ifndef COMPUTER_H
#define COMPUTER_H

//-- Need to use Configuration and Player objects for the Computer object
#include "configuration.h"
#include "player.h"
#include <limits.h>
#include <iostream>
#include <algorithm>


//-- Class Computer inherits publicly from the player object. The only differences between the objects are
//	 the constructor and the make_move() function
class Computer: public Player {

//-- public members
public:
	//constructor for Computer objects. Takes in a Configuration pointer that points to the current board state and
	//a token representing the marker that the computer player will use
	Computer(Configuration* game_board, char token);
	//destructor for the Computer object, doesn't do anything
	~Computer();
	//function that allows the computer to make a move based on the output of alpha_beta()
	int make_move();

//-- private members for the computer object
private:

	//private member that represents the current game state (i.e. placement of markers)
	Configuration* game_board;
	//counter that indicates what turn we are currently on
	int turn_number=1;
	//private helper function for the computer player, utilizes the minimax algorithm with alpha-beta pruning
	//in order to determine what spot to play a token
	int alpha_beta(Configuration game_board, int depth, int alpha, int beta, bool current_player);

};

#endif