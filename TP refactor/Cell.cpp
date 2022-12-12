#include "Cell.h"

/**
 * @brief   Construit une nouvelle case
 * @params  IdCell : identifiant de la case
**/
Cell::Cell(const int& IdCell) {
	idCell = IdCell;
	owner = 0;
}

/**
 * @brief   Permet de retourner du texte en rouge
 * @params  text : texte que l'on souhaite colorer
 * @return  le texte dans la bonne couleur
**/
string Cell::GetRedText(const string& text) const {
	return "\033[1;31m" + text + "\033[0m";
}

/**
 * @brief   Permet de retourner du texte en vert
 * @params  text : texte que l'on souhaite colorer
 * @return  le texte dans la bonne couleur
**/
string Cell::GetGreenText(const string& text) const {
	return "\033[1;32m" + text + "\033[0m";
}

/**
 * @brief   Genere l'affichage d'une case pour le jeu de morpion
 * @return  idCell par defaut sinon X pour le joueur 1, O pour le joueur 2
**/
string Cell::DisplayCellMorpion() const {
	string str = to_string(idCell);
	if (owner == 1) {
		str = GetRedText("X");
	}
	else if (owner == 2) {
		str = GetGreenText("O");
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
		str = GetRedText("O");
	}
	else if (owner == 2) {
		str = GetGreenText("O");
	}
	return str;
}
