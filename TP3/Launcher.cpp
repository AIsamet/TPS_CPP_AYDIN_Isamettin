#include "Game.h"
#include "Morpion.h"
#include "Puissance4.h"

//classe qui va servir de point d'entrée pour le programme

void Start() {

	string choice;
	cout << "1. Puissance 4" << endl;
	cout << "2. Morpion" << endl;
	cout << "3. Quitter" << endl << endl;
	cout << "Choix : ";
	cin >> choice;

	if (choice == "1") {
		Puissance4 game;
		game.StartGame();
	}
	else if (choice == "2") {
		Morpion game;
		game.StartGame();
	}
	else if (choice == "3") {
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