#include "Player.h"

Player::Player() {
}

Player::Player(int id, string name) {
	this->id = id;
	this->name = name;
	this->points = 0;
}

int Player::GetId() const{
	return id;
}

string Player::GetName() const {
	return name;
}