#ifndef Player_h
#define Player_h

#include <iostream>
#include <vector>
using namespace std;

class Player
{
public:
	Player();
	Player(int id, string name);
	int GetId() const;
	string GetName()const ;

private:
	int id;
	string name;
	int points;
};

#endif