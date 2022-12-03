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
	inline int GetIsBot() const { return isBot; }
	inline void SetName(const string& NewName) { name = NewName; }
	inline void SetIsBot(const int& NewSetting) { isBot = NewSetting; }

private:
	int id;
	string name;
	int isBot; // 0 = Player ; 1 = Bot
};

#endif