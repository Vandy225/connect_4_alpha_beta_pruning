//-- Game object header file

#ifndef GAME_H
#define GAME_H



//-- need to use configuration and player objects in the Game objects
#include "configuration.h"
#include "player.h"
#include <iostream>



class Game {

	//-- public member functions
public:

	//-- Constructor for the game object, takes in player pointers and an initial state
	Game (Player* player_one, Player* player_two, Configuration* initial_state);
	//-- function that makes a player take a turn
	bool take_turn();
	//-- main wrapper function that makes the game play
	void play_game();


//-- private members
private:
	//-- a configuration object that represents the state of the board at a particular time
	Configuration* state;
	//-- player pointer for the first player
	Player* player_one;
	//-- player pointer for the second player
	Player* player_two;
	//-- player pointer that represents the current player, used by the alpha_beta function
	//	 to determine if it is MIN or MAX playing at a current level
	Player* current_player;


};

#endif