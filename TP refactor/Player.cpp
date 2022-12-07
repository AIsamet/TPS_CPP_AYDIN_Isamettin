#include "Player.h"

/**
 * @brief   Construit un nouveau joueur
 * @params  id : id du joueur, name : nom du joueur
**/
Player::Player() {
}
Player::Player(int id, string name) {
	this->id = id;
	this->name = name;
	this->isBot = 0;
}

/**
 * @brief   Affiche les joueurs (morpion)
 * @params  player1 : joueur 1, player2 : joueur 2 ou IA
 * @return  void
**/
void Player::DisplayPlayersMorpion(Player player1, Player player2)
{
	cout << "\033[1;31mJoueur " << player1.GetName() << " (X)\033[0m  -  \033[1;32mJoueur " << player2.GetName() << " (O)\033[0m" << endl << endl;

}

/**
 * @brief   Affiche les joueurs (puissance 4)
 * @params  player1 : joueur 1, player2 : joueur 2 ou IA
 * @return  void
**/
void Player::DisplayPlayersPuissance4(Player player1, Player player2)
{
	cout << "\033[1;31mJoueur " << player1.GetName() << "\033[0m  -  \033[1;32mJoueur " << player2.GetName() << "\033[0m" << endl << endl;

}