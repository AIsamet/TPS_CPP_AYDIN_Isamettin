#ifndef Cell_h
#define Cell_h

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Classe d'une case
class Cell
{
public:
	/**
	 * Constructeur
	**/
	Cell(const int& IdCell);

	/**
	 * Getters
	**/
	inline int GetIdCell() const { return idCell; }
	inline int GetOwner() const { return owner; }

	/**
	 * Setters
	**/
	inline void SetIdCell(const int& NewIdCell) { idCell = NewIdCell; }
	inline void SetOwner(const int& NewOwner) { owner = NewOwner; }

	/**
	 * Methodes
	**/
	string GetRedText(const string& text) const;
	string GetGreenText(const string& text) const;
	string DisplayCellMorpion() const;
	string DisplayCellPuissance4() const;

private:
	/**
	 * Attributs
	**/
	int idCell;
	int owner; // 0 = case libre; 1 = player 1; 2 = player 2
};

#endif