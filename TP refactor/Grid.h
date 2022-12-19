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
	inline int GetSize() const { return GetLine() * GetColumn(); }

	Cell& GetCell(const int& idCell);
	Cell GetCell(const int& idCell) const;

	Cell& GetCell(const int& line, const int& column);
	Cell GetCell(const int& line, const int& column) const;

	int GetCellColumnCoordinate(const int& idCell) const;
	int GetCellLineCoordinate(const int& idCell) const;

	int GetCellOwner(const int& idCell);
	int GetCellOwner(const int& idCell) const;

	int GetCellOwner(const int& line, const int& column);
	int GetCellOwner(const int& line, const int& column) const;

	bool IsCellFree(const int& idCell) const;
	bool IsCellFree(const int& line, const int& column) const;

	vector<Cell> GetAdjacentCell(const int& idCell) const;
	bool IsPositionInRange(const int& positionLine, const int& positionColumn) const;

	bool SetCellOwnerIfEmpty(const int& idCell, const int& value);
	bool SetCellOwnerIfEmpty(const int& line, const int& column, const int& value);

	/**
	 * Methodes
	**/
	void InitializeGameGrid(const int& line, const int& column);
	void InitializeSizeGrid(const int& line, const int& column);

private:
	/**
	 * Attributs
	**/
	vector<Cell> gameGrid;
	pair<int, int> sizeGrid;
};

#endif