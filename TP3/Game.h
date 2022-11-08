#ifndef Game_h
#define Game_h

#include "Player.h"
#include "Cell.h"

//classe abstraite dont vont heriter les differents jeux
class Game
{

public:
	Game();

	virtual void InitGrid(const int& line, const int& column) = 0; //génére une grille de jeu
	virtual void DisplayPlate() const = 0; //affiche la grille de jeu
	virtual void InputPlayer(Player player) = 0; //demande une entrée au joueur
	virtual void StartGame() = 0; //lance la partie
	virtual bool CheckEquality() const = 0; //verifie le cas d'une égalité
	virtual bool CheckWin(const Player& player) const = 0; //verifie s'il y a un gagnant
	virtual bool CheckWinByLine(const Player& player) const = 0; //verifie s'il y a un gagnant par ligne
	virtual bool CheckWinByColumn(const Player& player) const = 0; //verifie s'il y a un gagnant par colonne
	virtual bool CheckWinByDiagonal(const Player& player) const = 0; //verifie s'il y a un gagnant par diagonal

private:
	vector<vector<Cell> > gameGrid;
	Player player1;
	Player player2;
};

#endif