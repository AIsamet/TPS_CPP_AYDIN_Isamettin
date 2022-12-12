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

/**
 * @brief   Demande aux joueurs leurs noms
 * @return  void
**/
void Game::AskPlayersNames() {
	system("cls");
	string namePlayer;

	cout << "Entrez le nom du joueur 1" << endl;
	cout << "-> ";
	namePlayer = Inputs::InputPlayersNames();
	player1.SetName(namePlayer);

	if (!player2.GetIsBot()) {
		cout << "\nEntrez le nom du joueur 2" << endl;
		cout << "-> ";
		namePlayer = Inputs::InputPlayersNames();
		player2.SetName(namePlayer);
	}
}