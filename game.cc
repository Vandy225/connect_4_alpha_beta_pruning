#include "game.h"
#define WIPE_SCREEN "\033[2J"


Game::Game(Player* player_one, Player* player_two, Configuration* initial_state){
	this->player_one = player_one;
	this-> player_two = player_two;
	this->state = initial_state;

	//need to define the =operator for states
	//this->state = initial_state;

}

void Game::play_game(){
	//start with player 1
	this->current_player = player_one;

	while(!player_turn()){
		std::cout << WIPE_SCREEN;

		

		if (current_player == player_one){
			current_player = player_two;
			std::cout << "Set to player two" << "\n";

		}
		else {
			std::cout << "Set to player one" << "\n";
			current_player = player_one;
		}

		

	}

	std::cout << WIPE_SCREEN;
	std::cout << "Player " << this->current_player->get_token() << " Won!\n";
	this->state->print_configuration();

return;

}

bool Game::player_turn(){


	char marker = this->current_player->get_token();

	printf("Player %c's turn\n", marker);

	this->state->print_configuration();


	int placement = this->current_player->make_move();

	while(!this->state->is_valid(placement)){
		printf("Position not allowed. Try again\n");
		placement = this->current_player->make_move();
	}

	this->state->modify_board(placement, marker);

	

	return this->state->game_over();
}

