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
	
	inline int GetId() const { return id; }
	inline string GetName() const { return name; }
	inline void SetName(const string& NewName) { name = NewName; }

private:
	int id;
	string name;
};

#endif