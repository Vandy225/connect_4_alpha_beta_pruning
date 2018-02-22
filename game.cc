//--Implementation for the Game objects


#include "game.h"

//-- Defining a custom string that is used to clear the screen so that the board
//	 appears to stay in one place and moves are made on it
#define WIPE_SCREEN "\033[2J"

//----------------------------------------------------------------------------------------------------------------------
//-- Constructor for the Game object
//
//-- Arguments:
//
//	 Player* player_one --> pointer to a player object representing the first player
//
//   Player* player_two --> pointer to a player object representing the second player
//
//	 Configuration* initial_state --> pointer to a Configuration object that represents the initially empty board
//
//	 The current_player member is left uninitialized in the constructor as we don't know who the current player is yet
//
//-- Return type: 
//					Game object
//----------------------------------------------------------------------------------------------------------------------

Game::Game(Player* player_one, Player* player_two, Configuration* initial_state){
	//initialize members of "this" to arguments passed in 
	this->player_one = player_one;
	this-> player_two = player_two;
	this->state = initial_state;

}
//----------------------------------------------------------------------------------------------------------------------
//-- Function that makes players take a turn
//
//-- Arguments:
//
//	 None, this function is called on a Game object
//
//-- Return type:
//					bool, telling whether the player won after the placement of their marker
//----------------------------------------------------------------------------------------------------------------------

bool Game::take_turn(){

	//grab the current player's marker/token
	char marker = this->current_player->get_token();

	//print statement to say whose turn it is
	printf("Player %c's turn\n", marker);

	//print out the current board
	this->state->print_configuration();

	//call the make move to make the player choose a placement for their marker
	int placement = this->current_player->make_move();

	//trap the player in a while loop that stops them from making an invalid placement of their marker
	while(!this->state->is_valid(placement)){
		//is the placement was not valid, make them do it again
		printf("Position not allowed. Try again\n");
		//call the make_move() function to make them make another (hopefully valid) move
		placement = this->current_player->make_move();
	}

	//the move has been made successfully, now we need to modify the state member of the
	//game object to reflect the placement of their marker/token at the specified location
	this->state->modify_board(placement, marker);

	
	//return the result of the game_over() function
	//returns true if the player's placement resulted in a win for them
	//returns false otherwise
	return this->state->game_over();
}

//-- Function that plays the 
void Game::play_game(){
	//start with player 1
	this->current_player = player_one;
	// while the game has not been won
	while(!take_turn()){
		//wipe the screen so the board appears to be not moving
		std::cout << WIPE_SCREEN;
		//if the current player is player one, switch to player two so they can have their turn
		if (current_player == player_one){
			//change player one to player two
			current_player = player_two;
		}
		//otherwise it was player twos turn, switch over to player one
		else {
			//change the current player to player one
			current_player = player_one;
		}
	}
	//if we got here, it means someone won the game

	//wipe the screen
	std::cout << WIPE_SCREEN;
	//print out who won the game
	std::cout << "Player " << this->current_player->get_token() << " Won!\n";
	//print the final board out to show the winning game
	this->state->print_configuration();

return;

}

