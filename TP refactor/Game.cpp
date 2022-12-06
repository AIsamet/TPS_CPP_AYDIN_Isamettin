#include "Game.h"

Game::Game() {

}

//fonction qui demande au joueur le type de jeu a lancer
void Game::AskGameMode() {
	int input = Input::InputGameType();
	if (input == 1) { SetGameMode(0); }
	else if (input == 2) { SetGameMode(1); player2.SetName("IA"); player2.SetIsBot(1); }
}

//fonction qui demande aux joueurs leur pseudonyme
void Game::AskPlayersName() {
	system("cls");
	string namePlayer;

	cout << "Entrez le nom du joueur 1" << endl;
	namePlayer = Input::InputPlayersName();
	player1.SetName(namePlayer);

	if (!player2.GetIsBot()) {
		cout << "\nEntrez le nom du joueur 2" << endl;
		namePlayer = Input::InputPlayersName();
		player2.SetName(namePlayer);
	}
}