#include "Player.h"

/**
 * @brief   Construit un nouveau joueur
 * @params  id : id du joueur, name : nom du joueur
**/
Player::Player() {
}

Player::Player(const int& id, const string& name) {
	this->id = id;
	this->name = name;
	this->isBot = 0;
}