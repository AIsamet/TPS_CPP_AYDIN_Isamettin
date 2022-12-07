#ifndef Grid_h
#define Grid_h

#include "Cell.h"

// Classe d'une grille de jeu
class Grid
{
public:
	/**
	 * Constructeur
	**/
	Grid();
	Grid(int line, int column);
	
	/**
	 * Getters
	**/
	vector<vector<Cell>> GetGameGrid() const { return gameGrid; }
	vector<vector<Cell>>& GetGameGridByReference() { return gameGrid; }
	Cell& GetCellPositionFromId(const int& idCell);
	
	/**
	 * Methodes
	**/
	void DisplayGridMorpion() const;
	void DisplayGridPuissance4() const;

private:
	/**
	 * Attributs
	**/
	vector<vector<Cell>> gameGrid;
};

#endif