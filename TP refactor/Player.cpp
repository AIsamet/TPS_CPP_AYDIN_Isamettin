#include "Player.h"

Player::Player() {
}

Player::Player(int id, string name) {
	this->id = id;
	this->name = name;
	this->isBot = 0;
}
void Player::DisplayPlayersMorpion(Player player1, Player player2)
{
	cout << "\033[1;31mJoueur " << player1.GetName() << " (X)\033[0m  -  \033[1;32mJoueur " << player2.GetName() << " (O)\033[0m" << endl << endl;

}

void Player::DisplayPlayersPuissance4(Player player1, Player player2)
{
	cout << "\033[1;31mJoueur " << player1.GetName() << "\033[0m  -  \033[1;32mJoueur " << player2.GetName() << "\033[0m" << endl << endl;

}