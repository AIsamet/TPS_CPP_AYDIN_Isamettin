#include "Player.h"

Player::Player() {
}

Player::Player(int id, string name) {
	this->id = id;
	this->name = name;
	this->isBot = 0;
}