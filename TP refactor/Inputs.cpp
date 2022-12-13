#include "Inputs.h"

/**
 * @brief   Appelle les methodes appropriees en fonction du type de joueur (morpion)
 * @params  grid : grille de jeu, player : joueur actuel
 * @return  void
**/
void Inputs::InputMorpion(Grid& grid, Player& player) {
	if (player.GetIsBot() == 1) { Inputs::InputBotPlayerMorpion(grid, player); }
	else if (player.GetIsBot() == 0) { Inputs::InputPlayerMorpion(grid, player); }
}

/**
 * @brief   Appelle les methodes appropriees en fonction du type de joueur (puissance 4)
 * @params  grid : grille de jeu, player : joueur actuel
 * @return  void
**/
void Inputs::InputPuissance4(Grid& grid, Player& player) {
	if (player.GetIsBot() == 1) { Inputs::InputBotPlayerMPuissance4(grid, player); }
	else if (player.GetIsBot() == 0) { Inputs::InputPlayerPuissance4(grid, player); }
}

// verifie si une entr�e est un chiffre
bool Inputs::IsNumericInput(int input)
{
	if (!std::cin.good())
	{
		return false;
	}
	return true;
}

// fait saisir un chiffre
int Inputs::GetNumericInput()
{
	int input = 0;
	cin >> input;
	while (!IsNumericInput(input))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Veuillez entrer un chiffre valide" << endl;
		cin >> input;
	}
	return input;
}

bool Inputs::IsInputValidMorpion(int input)
{
	if (input < 10 && input > 0) {
		return true;
	}
	return false;
}

bool Inputs::IsInputValidPuissance4(int input)
{
	if (input < 8 && input > 0) {
		return true;
	}
	return false;
}

/**
 * @brief   Traite la saisie du joueur (morpion)
 * @params  grid : grille de jeu, player : joueur actuel
 * @return  void
**/
void Inputs::InputPlayerMorpion(Grid& grid, Player& player)
{
	int input = Inputs::GetNumericInput();

	// verifie si l'entree est valide
	if (Inputs::IsInputValidMorpion(input)) {

		if (grid.GetCell(input - 1).GetOwner() == 0) {

			grid.GetCell(input - 1).SetOwner(player.GetId());
		}
		else {
			cout << "Case deja prise" << endl;
			InputPlayerMorpion(grid, player);
		}
	}
	else {
		cout << "Veuillez saisir un chiffre entre 1 et 9" << endl;
		InputPlayerMorpion(grid, player);
	}
}

/**
 * @brief   Traite la saisie du joueur (puissance 4)
 * @params  grid : grille de jeu, player : joueur actuel
 * @return  void
**/
void Inputs::InputPlayerPuissance4(Grid& grid, Player& player)
{
	// fait saisir un chiffre
	int input = Inputs::GetNumericInput();

	// verifie si l'entr�e est valide
	if (Inputs::IsInputValidPuissance4(input)) {

		for (int ligne = 0; ligne < grid.GetLine(); ligne++) {

			if (grid.GetCell(ligne, input - 1).GetOwner() == 0) {

				grid.GetCell(ligne, input - 1).SetOwner(player.GetId());
				break;
			}
			else if (ligne == grid.GetLine() - 1) {
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

/**
 * @brief   Attribue la propriete d'une case a un bot (morpion)
 * @params  grid : grille de jeu, player : bot
 * @return  void
**/
void Inputs::InputBotPlayerMorpion(Grid& grid, Player& player)
{
	grid.GetCell(BotRandomInputGeneratorMorpion(grid)).SetOwner(player.GetId());
}

/**
 * @brief   Attribue la propriete d'une case a un bot (puissance 4)
 * @params  grid : grille de jeu, player : bot
 * @return  void
**/
void Inputs::InputBotPlayerMPuissance4(Grid& grid, Player& player)
{
	for (int ligne = 0; ligne < grid.GetGameGrid().size(); ligne++) {

		if (grid.GetCell(ligne, BotRandomInputGeneratorPuissance4(grid)).GetOwner() == 0) {

			grid.GetCell(ligne, BotRandomInputGeneratorPuissance4(grid)).SetOwner(player.GetId());
			break;
		}
	}
}

/**
 * @brief   Genere aleatoirement une case libre a jouer par le bot (puissance 4)
 * @params  grid : grille de jeu, player : bot
 * @return  void
**/
int Inputs::BotRandomInputGeneratorPuissance4(Grid& grid) {
	srand(time(NULL));
	int randomPlay;

	while (true) {

		randomPlay = rand() % 7;
		for (int ligne = 0; ligne < grid.GetGameGrid().size(); ligne++) {

			if (grid.GetCell(ligne, randomPlay).GetOwner() == 0) {
				return randomPlay;
			}
		}
	}
}

/**
 * @brief   Genere aleatoirement une case libre a jouer par le bot (morpion)
 * @params  grid : grille de jeu, player : bot
 * @return  void
**/
int Inputs::BotRandomInputGeneratorMorpion(Grid& grid) {
	srand(time(NULL));
	int randomPlay = rand() % 9;

	while (grid.GetCell(randomPlay).GetOwner() != 0) {
		randomPlay = rand() % 9;
	}

	return randomPlay;
}

/**
 * @brief   Traite la saisie pour le choix de jeu
 * @return  choix du jeu
**/
string Inputs::InputGameChoice()
{
	string choice;
	cout << "1. Puissance 4" << endl;
	cout << "2. Morpion" << endl;
	cout << "3. Quitter" << endl << endl;
	cout << "Choix : ";
	cin >> choice;
	return choice;
}

/**
 * @brief   Traite la saisie pour le mode de jeu
 * @return  mode de jeu
**/
int Inputs::InputGameMode()
{
	int input = 0;

	cout << "\nA quelle mode de jeu voulez vous jouer ? " << endl;
	cout << "1 - Joueur contre Joueur" << endl;
	cout << "2 - Joueur contre IA" << endl << endl;
	cout << "Choix : ";
	cin >> input;

	//verifie si l'entr�e est un int
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

/**
 * @brief   Traite la saisie pour les noms des joueurs
 * @return  nom du joueur actuel
**/
string Inputs::InputPlayersNames()
{
	string namePlayer;
	cin >> namePlayer;
	return namePlayer;
}

