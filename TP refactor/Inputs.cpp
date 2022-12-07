#include "Inputs.h"

Input::Input()
{
}


void Input::InputMorpion(Grid& grid, Player player) {
	if (player.GetIsBot() == 1) { Input::InputBotPlayerMorpion(grid, player); }
	else if (player.GetIsBot() == 0) { Input::InputPlayerMorpion(grid, player); }
}

void Input::InputPuissance4(Grid& grid, Player player) {
	if (player.GetIsBot() == 1) { Input::InputBotPlayerMPuissance4(grid, player); }
	else if (player.GetIsBot() == 0) { Input::InputPlayerPuissance4(grid, player); }
}

void Input::InputPlayerMorpion(Grid& grid, Player player)
{
	int input = 0;
	cin >> input;

	//verifie si l'entrée est un int
	while (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Veuillez entrer un chiffre valide" << endl;
		cin >> input;
	}

	//verifie si l'entrée est valide
	if (input < 10 && input > 0) {

		if (grid.GetCellPositionFromId(input - 1).GetOwner() == 0) {

			grid.GetCellPositionFromId(input - 1).SetOwner(player.GetId());
		}
		else {

			cout << "Case deja prise" << endl; InputPlayerMorpion(grid, player);
		}
	}
	else {
		cout << "Veuillez saisir un chiffre entre 1 et 9" << endl;
		InputPlayerMorpion(grid, player);
	}
}

void Input::InputPlayerPuissance4(Grid& grid, Player player)
{
	int input = 0;
	cin >> input;

	//verifie si l'entrée est un int
	while (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Veuillez entrer un chiffre valide" << endl;
		cin >> input;
	}

	//verifie si l'entrée est valide
	if (input < 8 && input > 0) {

		for (int ligne = 0; ligne < grid.GetGameGrid().size(); ligne++) {

			if (grid.GetGameGrid()[ligne][input - 1].GetOwner() == 0) {

				grid.GetGameGridByReference()[ligne][input - 1].SetOwner(player.GetId());
				break;
			}
			else if (ligne == grid.GetGameGrid().size() - 1) {
				cout << "La colonne est pleine, veuillez choisir une autre colonne" << endl;
				InputPlayerPuissance4(grid, player);
			}
		}
	}
	else {
		cout << "Veuillez saisir un chiffre entre 1 et 7" << endl;
		InputPlayerPuissance4(grid, player);
	}
}

void Input::InputBotPlayerMorpion(Grid& grid, Player player)
{
	grid.GetCellPositionFromId(BotRandomInputGeneratorMorpion(grid, player)).SetOwner(player.GetId());
}

void Input::InputBotPlayerMPuissance4(Grid& grid, Player player)
{
	for (int ligne = 0; ligne < grid.GetGameGrid().size(); ligne++) {

		if (grid.GetGameGrid()[ligne][BotRandomInputGeneratorPuissance4(grid, player)].GetOwner() == 0) {

			grid.GetGameGridByReference()[ligne][BotRandomInputGeneratorPuissance4(grid, player)].SetOwner(player.GetId());
			break;
		}
	}
}

//genere une case vide a jouer aléatoirement par le bot
int Input::BotRandomInputGeneratorPuissance4(Grid& grid, Player player) {
	srand(time(NULL));
	int randomPlay;

	while (true) {

		randomPlay = rand() % 7;
		for (int ligne = 0; ligne < grid.GetGameGrid().size(); ligne++) {

			if (grid.GetGameGrid()[ligne][randomPlay].GetOwner() == 0) {
				return randomPlay;
			}
		}
	}
}

//genere une case vide a jouer aléatoirement par le bot
int Input::BotRandomInputGeneratorMorpion(Grid& grid, Player player) {
	srand(time(NULL));
	int randomPlay = rand() % 9;

	while (grid.GetCellPositionFromId(randomPlay).GetOwner() != 0) {
		randomPlay = rand() % 9;
	}

	return randomPlay;
}

int Input::InputGameMode()
{
	int input = 0;

	cout << "\nA quelle mode de jeu voulez vous jouer ? " << endl;
	cout << "1 - Joueur contre Joueur" << endl;
	cout << "2 - Joueur contre IA" << endl << endl;
	cout << "Choix : ";
	cin >> input;

	//verifie si l'entrée est un int
	while (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\nVeuillez entrer un chiffre" << endl;
		cout << "Choix : ";
		cin >> input;
	}
	if (input < 3 && input > 0) {
		return input;
	}
	else {
		system("cls");
		cout << "Veuillez saisir un choix valide" << endl;
		InputGameMode();
	}
}

string Input::InputPlayersNames()
{
	string namePlayer;
	cin >> namePlayer;	
	return namePlayer;
}

