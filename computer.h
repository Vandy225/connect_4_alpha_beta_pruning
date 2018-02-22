#ifndef COMPUTER_H
#define COMPUTER_H
#include "configuration.h"
#include "player.h"
#include <limits.h>
#include <iostream>
#include <algorithm>


class Computer: public Player {

public:
	Computer(Configuration* game_board, char token);
	~Computer();
	//lets the computer pick a spot
	int make_move();


private:

	//member 
	Configuration* game_board;

	int turn_number=1;
	//private helper function for 
	int alpha_beta(Configuration game_board, int depth, int alpha, int beta, bool current_player);




};

#endif