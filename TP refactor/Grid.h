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
	Grid(const int& line, const int& column);

	/**
	 * Getters
	**/
	inline vector<Cell> GetGameGrid() const { return gameGrid; }
	inline pair<int, int> GetSizeGrid() const { return sizeGrid; }

	inline int GetLine() const { return sizeGrid.first; }
	inline int GetColumn() const { return sizeGrid.second; }

	Cell& GetCell(const int& idCell);
	Cell GetCell(const int& idCell) const;

	Cell& GetCell(const int& line, const int& column);
	Cell GetCell(const int& line, const int& column) const;

	/**
	 * Methodes
	**/
	void InitializeGameGrid(const int& line, const int& column);
	void InitializeSizeGrid(const int& line, const int& column);
	void DisplayGridMorpion() const;
	void DisplayGridPuissance4() const;

private:
	/**
	 * Attributs
	**/
	vector<Cell> gameGrid;
	pair<int, int> sizeGrid;
};

#endif