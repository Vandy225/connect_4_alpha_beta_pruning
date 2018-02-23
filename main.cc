//-- Main program file

#include <iostream>
#include "configuration.h"
#include "game.h"
#include "player.h"
#include "computer.h"
#include <stdio.h>


//----------------------------------------------------------------------------------------------------------------------
//-- Main Program
//----------------------------------------------------------------------------------------------------------------------
int main () {
	
	//initialize the game_type to 1 to start
	int game_type=1;

	//make some pointers to fill later
	Game* game;
	Configuration* initial_state;
	Player* human_player_one;
	Player* human_player_two;
	Player* computer_player;

	//while the game_type is not 0 (i.e. ending the program)
	while (game_type){
	//ask what kind of game the player wants to play
	printf("What kind of game do you want to play?\n\nEnter 1 for Human vs. Human\nEnter 2 for Human vs. AI\nEnter 0 to exit\n");
		//get the input
		scanf("%i", &game_type);
	//if the user entered the wrong game type
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
		//make the Player pointers for the humans
		human_player_one = new Player('A');
		human_player_two = new Player('B');
		//create the initial configuration object with the empty board and the maximizing player
		initial_state = new Configuration();
		//initialize the Game object
		game = new Game(human_player_one, human_player_two, initial_state);
		//play the game
		game->play_game();
		//delete pointers so no memory leaks
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
		
		//delete the pointers so no memory leaks
		delete human_player_one;
		delete computer_player;
		delete initial_state;
		delete game;
	}
}

	//exit the program
	return 0;
}
