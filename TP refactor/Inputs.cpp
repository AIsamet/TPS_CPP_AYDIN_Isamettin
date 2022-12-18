#include "Inputs.h"

/**
 * @brief   Appelle les methodes appropriees en fonction du type de joueur (morpion)
 * @params  grid : grille de jeu, player : joueur actuel
 * @return  void
**/
void Inputs::InputByCell(Grid& grid, Player& player, const int& maxInput) {
	if (player.GetIsBot() == 1) { Inputs::InputBotPlayerMorpion(grid, player); }
	else if (player.GetIsBot() == 0) { Inputs::InputByCellPlayer(grid, player, maxInput); }
}

/**
 * @brief   Appelle les methodes appropriees en fonction du type de joueur (puissance 4)
 * @params  grid : grille de jeu, player : joueur actuel
 * @return  void
**/
void Inputs::InputByColumn(Grid& grid, Player& player, const int& maxInput) {
	if (player.GetIsBot() == 1) { Inputs::InputBotPlayerMPuissance4(grid, player); }
	else if (player.GetIsBot() == 0) { Inputs::InputByColumnPlayer(grid, player, maxInput); }
}

/**
 * @brief   Verifie si une entr�e est un nombre
 * @params  input : l'entr�e a v�rifier
 * @return  bool
**/
bool Inputs::IsNumericInput(const int& input) {
	if (!std::cin.good()) {
		return false;
	}
	return true;
}

/**
 * @brief   Demande une entr�e de type int et la retourne
 * @return  int
**/
int Inputs::GetNumericInput() {
	int input = 0;
	cin >> input;

	while (!IsNumericInput(input)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		Outputs::DisplayInputIsNotNumericErrorMessage();
		cin >> input;
	}
	return input;
}

string Inputs::GetStringInput() {
	string input;
	cin >> input;
	return input;
}

/**
 * @brief   Verifie si l'entr�e est valide pour un jeu de morpion
 * @params  input : l'entr�e a v�rifier
 * @return  bool
**/
bool Inputs::IsInputByCellValid(const int& input, const int& maxInput) {
	if (input <= maxInput && input > 0) {
		return true;
	}
	return false;
}

/**
 * @brief   Verifie si l'entr�e est valide pour un jeu de puissance 4
 * @params  input : l'entr�e a v�rifier
 * @return  bool
**/
bool Inputs::IsInputByColumnValid(const int& input, const int& maxInput) {
	if (input <= maxInput && input > 0) {
		return true;
	}
	return false;
}

bool Inputs::IsInputValidGameModes(const int& input) {
	if (input < 4 && input > 0) {
		return true;
	}
	return false;
}

/**
 * @brief   Traite la saisie du joueur en appellant SetInputByCell
 * @params  grid : grille de jeu, player : joueur actuel
 * @return  void
**/
void Inputs::InputByCellPlayer(Grid& grid, Player& player, const int& maxInput) {
	int input = Inputs::GetNumericInput();
	Inputs::SetInputByCell(grid, player, input, maxInput);
}

/**
 * @brief   Si l'entr�e est valide il appelle SetInputCellMorpion afin de changer l'Owner du Cell demand� sinon demande une ressaisie
 * @params  grid : grille de jeu, player : joueur actuel, input : l'entr�e du joueur
 * @return  void
**/
void Inputs::SetInputByCell(Grid& grid, Player& player, const int& input, const int& maxInput) {
	if (Inputs::IsInputByCellValid(input, maxInput)) {
		Inputs::SetInputtedCell(grid, player, input, maxInput);
	}
	else {
		Outputs::DisplayInputtedCellIsNotValid(maxInput);
		InputByCellPlayer(grid, player, maxInput);
	}
}

/**
 * @brief   Si le Cell n'a pas deja un Owner il effectue le changement d'Owner, sinon demande une ressaisie
 * @params  grid : grille de jeu, player : joueur actuel, input : l'entr�e du joueur
 * @return  void
**/
void Inputs::SetInputtedCell(Grid& grid, Player& player, const int& input, const int& maxInput) {
	if (!grid.SetCellOwnerIfEmpty(input - 1, player.GetId())) {
		Outputs::DisplayCellIsNotEmptyErrorMessageMorpion();
		InputByCellPlayer(grid, player, maxInput);
	}
}

/**
 * @brief   Traite la saisie du joueur en appellant SetInputByColumn (puissance 4)
 * @params  grid : grille de jeu, player : joueur actuel
 * @return  void
**/
void Inputs::InputByColumnPlayer(Grid& grid, Player& player, const int& maxInput) {
	int input = Inputs::GetNumericInput();
	Inputs::SetInputByColumn(grid, player, input, maxInput);
}

/**
 * @brief   Si l'entr�e est valide il appelle SetInputCellPuissance4 afin de changer l'Owner du Cell demand� sinon demande une ressaisie
 * @params  grid : grille de jeu, player : joueur actuel, input : l'entr�e du joueur
 * @return  void
**/
void Inputs::SetInputByColumn(Grid& grid, Player& player, const int& input, const int& maxInput) {
	if (Inputs::IsInputByColumnValid(input, maxInput)) {
		Inputs::SetInputtedColumn(grid, player, input, maxInput);
	}
	else {
		Outputs::DisplayInputtedCellIsNotValid(maxInput);
		InputByColumnPlayer(grid, player, maxInput);
	}
}

/**
 * @brief   Si le Cell le plus bas de la colonne n'a pas deja un Owner il effectue le changement d'Owner, sinon demande une ressaisie
 * @params  grid : grille de jeu, player : joueur actuel, input : l'entr�e du joueur
 * @return  void
**/
void Inputs::SetInputtedColumn(Grid& grid, Player& player, const int& input, const int& maxInput) {
	for (int ligne = 0; ligne < grid.GetLine(); ligne++) {
		if (grid.IsCellFree(ligne, input - 1)) {
			grid.SetCellOwnerIfEmpty(ligne, input - 1, player.GetId());
			break;
		}
		else if (ligne == grid.GetLine() - 1) {
			Outputs::DisplayColumnIsFullErrorMessagePuissance4();
			InputByColumnPlayer(grid, player, maxInput);
		}
	}
}

/**
 * @brief   Attribue la propriete d'une case a un bot (morpion)
 * @params  grid : grille de jeu, player : bot
 * @return  void
**/
void Inputs::InputBotPlayerMorpion(Grid& grid, Player& player) {
	grid.GetCell(BotRandomInputGeneratorMorpion(grid)).SetOwner(player.GetId());
}

/**
 * @brief   Attribue la propriete d'une case a un bot (puissance 4)
 * @params  grid : grille de jeu, player : bot
 * @return  void
**/
void Inputs::InputBotPlayerMPuissance4(Grid& grid, Player& player) {
	for (int ligne = 0; ligne < grid.GetLine(); ligne++) {

		if (grid.IsCellFree(ligne, BotRandomInputGeneratorPuissance4(grid))) {

			grid.SetCellOwnerIfEmpty(ligne, BotRandomInputGeneratorPuissance4(grid), player.GetId());
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
		for (int ligne = 0; ligne < grid.GetLine(); ligne++) {

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
string Inputs::InputGameChoice() {
	Outputs::DisplayGameChoices();
	string choice;
	cin >> choice;
	return choice;
}

/**
 * @brief   Traite la saisie pour le mode de jeu
 * @return  mode de jeu
**/
int Inputs::InputGameMode() {
	Outputs::DisplayGameModes();
	int input = Inputs::GetNumericInput();

	if (!Inputs::IsInputValidGameModes(input)) {
		Outputs::DisplayInputIsNotValidErrorMessageGameModes();
		InputGameMode();
	}

	return input;
}

/**
 * @brief   Traite la saisie pour les noms des joueurs
 * @return  nom du joueur actuel
**/
void Inputs::InputPlayersNames(Player& player1, Player& player2) {
	Inputs::InputPlayer1Name(player1);
	Inputs::InputPlayer2Name(player2);
}

void Inputs::InputPlayer1Name(Player& player1) {
	Outputs::DisplayInputMessagePlayer1Name();
	string namePlayer = Inputs::GetStringInput();
	player1.SetName(namePlayer);
}

void Inputs::InputPlayer2Name(Player& player2) {
	if (!player2.GetIsBot()) {
		Outputs::DisplayInputMessagePlayer2Name();
		string namePlayer = Inputs::GetStringInput();
		player2.SetName(namePlayer);
	}
}

