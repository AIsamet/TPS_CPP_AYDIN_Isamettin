#include "Game.h"

/**
 * @brief   Demande aux joueurs le type de jeu a lancer
 * @return  void
**/
void Game::AskGameMode() {
	int input = Inputs::InputGameMode();
	if (input == 1) { SetGameMode(0); }
	else if (input == 2) { SetGameMode(1); player2.SetName("IA"); player2.SetIsBot(1); }
}

Player Game::RoundGenerator(int round) {
	if (round % 2 == 0) {
		return player1;
	}
	else {
		return player2;
	}
}