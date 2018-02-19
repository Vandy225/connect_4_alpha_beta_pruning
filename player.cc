#include "player.h"

Player::Player(char token){
	this->token = token;
}

Player::~Player(){
	
}


//return a position that the player wants to 
int Player::make_move(){

	int array_position = 0;
	printf("Enter a position that you want to place your token (0-6): ");
	//scanf("%i", &array_position);
	std::cin >> array_position;

	while(std::cin.fail()){
		
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Nice try. Do it again: ";
		std::cin >> array_position;
	}



	
	//return the position in the array that the 
	return array_position;
}

char Player::get_token(){
	return this->token;
}
