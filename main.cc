#include <iostream>
#include "configuration.h"
#include "game.h"
#include "player.h"
#include "computer.h"
#include <stdio.h>



int main () {
	

	std::cout << "start" << std::endl;
	int game_type=1;

	Game* game;
	Configuration* initial_state;
	Player* human_player_one;
	Player* human_player_two;
	Player* computer_player;
	//Computer* computer_player;
	//what kind of game 

	printf("What kind of game do you want to play?\n\nEnter 1 for Human vs. Human\nEnter 2 for Human vs. AI\n");
		scanf("%i", &game_type);


	while (game_type < 1 || game_type > 2){
		printf("Wrong game type\nWhat kind of game do you want to play?\n\nEnter 1 for Human vs. Human\nEnter 2 for Human vs. AI\n");
		scanf("%i", &game_type);

	}



	if (game_type == 1){

		//std::cout << "making player one" << std::endl;
		human_player_one = new Player('A');
		//std::cout << "making player two" << std::endl;
		human_player_two = new Player('B');
		//create the initial configuration object with the empty board and the maximizing player
		//std::cout << "making state" << std::endl;
		initial_state = new Configuration();
		//std::cout << "making game pointer" << std::endl;
		game = new Game(human_player_one, human_player_two, initial_state);
		game->play_game();
		delete human_player_one;
		delete human_player_two;
		delete initial_state;
		delete game;
	}
	
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

	//initial_state->print_configuration();
	




	//declare the game pointer object


	









	




	

	//we want to make a move as the first player






	return 0;
}

/*

Pseudo Code

function alphabeta(node, depth, α, β, maximizingPlayer)
02      if depth = 0 or node is a terminal node
03          return the heuristic value of node
04      if maximizingPlayer
05          v := -∞
06          for each child of node
07              v := max(v, alphabeta(child, depth – 1, α, β, FALSE))
08              α := max(α, v)
09              if β ≤ α
10                  break (* β cut-off *)
11          return v
12      else
13          v := +∞
14          for each child of node
15              v := min(v, alphabeta(child, depth – 1, α, β, TRUE))
16              β := min(β, v)
17              if β ≤ α
18                  break (* α cut-off *)
19          return v
*/