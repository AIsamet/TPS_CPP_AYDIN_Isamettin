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
	Player(int id, string name);
	
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
	
	/**
	 * Methodes
	**/
	static void DisplayPlayersMorpion(Player player1, Player player2);
	static void DisplayPlayersPuissance4(Player player1, Player player2);

private:
	/**
	 * Attributs
	**/
	int id;
	string name;
	int isBot; // 0 = Player ; 1 = Bot
};

#endif