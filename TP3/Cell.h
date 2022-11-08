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

	string DisplayCellMorpion() const; //g�n�re un affichage de case pour le jeu morpion
	string DisplayCellPuissance4() const; //g�n�re un affichage de case pour le jeu puissance 4
	

private:
	static int idStatic; //variable static auto incr�ment� pour g�n�rer un idCell
	int idCell; //permet d'identifier une case
	int owner; //definit le propri�taire d'une case : 0 = free; 1 = player 1; 2 = player 2;
};

#endif