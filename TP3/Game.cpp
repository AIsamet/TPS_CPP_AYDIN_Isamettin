#include "Game.h"
#include <string>

#include "Morpion.h"

Game::Game() {
	
}

int main() {
	Morpion newMorpion(3, 3);
	newMorpion.InitGame();


	return 0;
}
