#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <climits>

class Player {

public:

	//player constructor
	Player(char token);
	//move logic for the player
	virtual int make_move();

	virtual ~Player();

	char get_token();
	

private:
	char token;



};

#endif