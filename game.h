#ifndef GAME_H
#define GAME_H



#include "configuration.h"
#include "player.h"
#include <iostream>

class Game {
public:

	//constructor
	Game (Player* player_one, Player* player_two, Configuration* initial_state);
	bool player_turn();
	void play_game();



private:
	Configuration* state;
	Player* player_one;
	Player* player_two;
	Player* current_player;


};

#endif