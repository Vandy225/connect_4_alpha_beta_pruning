#include <iostream>
#include "configuration.h"




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




int main () {


	//main objects that we will need:

	//nodes

	//connect 4 board - char**

	//create an initial configuration




	char human_player = 'h';
	char computer_player = 'c';



	//create the initial configuration object with the empty board and the maximizing player
	Configuration initial_state(human_player);

	//we want to make a move as the first player

	printf("The");





	return 0;
}