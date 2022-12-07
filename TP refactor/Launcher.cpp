#include "Game.h"
#include "Morpion.h"
#include "Puissance4.h"

//classe qui va servir de point d'entrée pour le programme

void Start() {

	string choice = Inputs::InputGameChoice();
	
	if (choice == "1") {
		Puissance4 game;
		game.StartGame();
	}
	else if (choice == "2") {
		Morpion game;
		game.StartGame();
	}
	else if (choice == "3") {
		cout << "A bientot !" << endl << endl;
		exit(0);
	}
	else {
		system("cls");
		cout << "Choix incorrect" << endl << endl;
		Start();
	}
}

int main() {

	cout << "Bienvenue, a quoi souhaitez vous jouer ?" << endl;
	while (true) {
		Start();
		cout << "\nVoulez-vous rejouer ? Si oui choisissez un jeu, sinon tapez 3" << endl;
	}
	return 0;
}