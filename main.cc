//-- Main program file

#include <iostream>
#include "configuration.h"
#include "game.h"
#include "player.h"
#include "computer.h"
#include <stdio.h>


//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
int main () {
	
	int game_type=1;

	Game* game;
	Configuration* initial_state;
	Player* human_player_one;
	Player* human_player_two;
	Player* computer_player;
	//Computer* computer_player;
	//what kind of game 

	while (game_type){

	printf("What kind of game do you want to play?\n\nEnter 1 for Human vs. Human\nEnter 2 for Human vs. AI\nEnter 0 to exit\n");
		scanf("%i", &game_type);


	while (game_type < 0 || game_type > 2){
		printf("Wrong game type\nWhat kind of game do you want to play?\n\nEnter 1 for Human vs. Human\nEnter 2 for Human vs. AI\nEnter 0 to exit\n");
		scanf("%i", &game_type);

	}
	//exit the game
	if(game_type == 0){
		break;

	}
	//check game type
	// if game_type  == 1, then it is a human vs. human game
	if (game_type == 1){

		human_player_one = new Player('A');

		human_player_two = new Player('B');
		//create the initial configuration object with the empty board and the maximizing player
		initial_state = new Configuration();
		//std::cout << "making game pointer" << std::endl;
		game = new Game(human_player_one, human_player_two, initial_state);
		game->play_game();
		delete human_player_one;
		delete human_player_two;
		delete initial_state;
		delete game;
	}
	//otherwise it is a human vs. computer game
	else {
		initial_state = new Configuration();
		human_player_one = new Player('A');
		Player* computer_player = new Computer(initial_state,'B');
		game = new Game(human_player_one, computer_player, initial_state);
		game->play_game();
		
		delete human_player_one;
		delete computer_player;
		delete initial_state;
		delete game;
	}
}


	return 0;
}
