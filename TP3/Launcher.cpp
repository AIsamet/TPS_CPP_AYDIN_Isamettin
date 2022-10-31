#include "Launcher.h"
#include "Game.h"
#include "Morpion.h"
#include "Puissance4.h"

Launcher::Launcher() {
	
}

int main() {
	
	Launcher launcher;
	
	cout << "Bienvenue, a quoi souhaitez vous jouer ?" << endl;

	while (true) {
		launcher.Start();
		cout << "\nVoulez-vous rejouer ? Si oui choisissez un jeu, sinon tapez 3" << endl;
	}

	return 0;
}

void Launcher::Start() {

	int choice = 0;
	cout << "1. Puissance 4" << endl;
	cout << "2. Morpion" << endl;
	cout << "3. Quitter" << endl << endl;
	cout << "Choix : ";
	cin >> choice;

	if (choice == 1) {
		Puissance4 game;
		game.StartGame();
	}
	else if (choice == 2) {
		Morpion game;
		game.StartGame();
	}
	else if (choice == 3) {
		exit(0);
	}
	else {
		system("cls");
		cout << "Choix incorrect" << endl << endl;
		Start();
	}
}