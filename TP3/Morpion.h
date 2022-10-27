#pragma once
#include "Game.h"
#include "Grid.h"

class Morpion:Game
{
public:
	Morpion();
	~Morpion();

private:
	Grid grid;
};