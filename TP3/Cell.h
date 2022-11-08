#ifndef Cell_h
#define Cell_h

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Cell
{
	
public:
	Cell();

	inline int GetIdCell() const { return idCell; }
	inline int GetOwner() const { return owner; }
	inline void SetOwner(const int& NewOwner) { owner = NewOwner; }
	inline void static SetIdStatic(const int& NewIdStatic) { idStatic = NewIdStatic; }

	string DisplayCellMorpion() const; //génére un affichage de case pour le jeu morpion
	string DisplayCellPuissance4() const; //génére un affichage de case pour le jeu puissance 4
	

private:
	static int idStatic; //variable static auto incrémenté pour générer un idCell
	int idCell; //permet d'identifier une case
	int owner; //definit le propriétaire d'une case : 0 = free; 1 = player 1; 2 = player 2;
};

#endif