#include "Cell.h"

int Cell::idStatic = 1;

/**
 * @brief   Construit une nouvelle case
**/
Cell::Cell() {
	owner = 0;
	idCell = Cell::idStatic++;
}

/**
 * @brief   Genere l'affichage d'une case pour le jeu de morpion
 * @return  idCell par defaut sinon X pour le joueur 1, O pour le joueur 2
**/
string Cell::DisplayCellMorpion() const{
	string str = to_string(idCell);
	if (owner == 1) {
		str = "\033[1;31mX\033[0m";
	}
	else if (owner == 2) {
		str = "\033[1;32mO\033[0m";
	}
	return str;
}

/**
 * @brief   Genere l'affichage d'une case pour le jeu de puissance 4
 * @return  chaîne vide par defaut sinon O rouge pour le joueur 1, O vert pour le joueur 2
**/
string Cell::DisplayCellPuissance4() const {
	string str = " ";
	if (owner == 1) {
		str = "\033[1;31mO\033[0m";
	}
	else if (owner == 2) {
		str = "\033[1;32mO\033[0m";
	}
	return str;
}
