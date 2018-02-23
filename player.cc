//-- Implementation file for the Player class

#include "player.h"

//----------------------------------------------------------------------------------------------------------------------
//-- Function that constructs a Player object
//
//-- Arguments:
//
// 	 char token --> will set what token the player is using
//
//-- Return type:
//
//	 			 Player object
//----------------------------------------------------------------------------------------------------------------------
Player::Player(char token){
	//set the token member
	this->token = token;
}

//----------------------------------------------------------------------------------------------------------------------
//-- Destructor, does nothing
//----------------------------------------------------------------------------------------------------------------------
Player::~Player(){
	
}

//----------------------------------------------------------------------------------------------------------------------
//-- Function that asks a player to make a move, stops them if they enter something that is not a number
//
//-- Arguments:
//
//	 nothing
//
//-- Return type:
//
//	   	    	 int, representing where the player wants to play a token
//----------------------------------------------------------------------------------------------------------------------
int Player::make_move(){

	//initialize the position to 0
	int array_position = 0;
	//ask where they want the token
	printf("Enter a position that you want to place your token (0-6): ");
	//get the input
	std::cin >> array_position;
	//while the input was not good
	while(std::cin.fail()){
		//clear the input
		std::cin.clear();
		//ignore for INT_MAX
		std::cin.ignore(INT_MAX, '\n');
		//tell them to do it again
		std::cout << "Nice try. Do it again: ";
		//get the position again
		std::cin >> array_position;
	}	
	//return the position in the array that the 
	return array_position;
}
//----------------------------------------------------------------------------------------------------------------------
//-- Function to get the token member of the Player object
//
//-- Arguments:
//
//	 none
//
//-- Return type:
//
//	  	 	 	 char
//----------------------------------------------------------------------------------------------------------------------
char Player::get_token(){
	return this->token;
}
