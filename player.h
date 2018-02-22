//-- Header file for the Player object

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <climits>

class Player {
//-- public members
public:

	//player constructor
	Player(char token);
	//function that makes a move for a player.
	//overloaded in Computer derived class
	virtual int make_move();
	//destructor for player object
	virtual ~Player();
	//getter function to get the token protected member
	char get_token();
protected:
	//char representing the marker that a player is using on the board
	char token;
};

#endif