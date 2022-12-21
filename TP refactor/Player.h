#ifndef Player_h
#define Player_h

#include <iostream>
#include <vector>

using namespace std;

// Classe d'un joueur
class Player
{
public:
	/**
	 * Constructeur
	**/
	Player();
	Player(const int& id, const string& name);

	/**
	 * Getters
	**/
	inline int GetId() const { return id; }
	inline string GetName() const { return name; }
	inline int GetIsBot() const { return isBot; }

	/**
	 * Setters
	**/
	inline void SetName(const string& NewName) { name = NewName; }
	inline void SetIsBot(const int& NewSetting) { isBot = NewSetting; }

private:
	/**
	 * Attributs
	**/
	int id;
	string name;
	int isBot; // 0 = Player ; 1 = Bot
};

#endif