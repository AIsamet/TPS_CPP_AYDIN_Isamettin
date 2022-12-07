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
	Cell();

	/**
	 * Getters
	**/
	inline int GetIdCell() const { return idCell; }
	inline int GetOwner() const { return owner; }

	/**
	 * Setters
	**/
	inline void SetOwner(const int& NewOwner) { owner = NewOwner; }
	inline void static SetIdStatic(const int& NewIdStatic) { idStatic = NewIdStatic; }

	/**
	 * Methodes
	**/
	string DisplayCellMorpion() const;
	string DisplayCellPuissance4() const;
	
private:
	/**
	 * Attributs
	**/
	static int idStatic; // auto incrémenté pour générer un idCell
	int idCell;
	int owner; // 0 = case libre; 1 = player 1; 2 = player 2
};

#endif