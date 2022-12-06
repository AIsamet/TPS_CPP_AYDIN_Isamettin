#include "Input.h"

Input::Input()
{
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

		if (grid.GetGameGrid()[ligne][BotRandomInputGeneratorPuissance4(grid,player)].GetOwner() == 0) {

			grid.GetGameGrid()[ligne][BotRandomInputGeneratorPuissance4(grid, player)].SetOwner(player.GetId());
			break;
		}
	}
}

int Input::InputGameType()
{
	return 0;
}

string Input::InputPlayersName()
{
	return "";
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
	int randomPlay = rand() % 10;

	while (grid.GetCellPositionFromId(randomPlay).GetOwner() != 0) {
		randomPlay = rand() % 10;
	}

	return randomPlay;
}