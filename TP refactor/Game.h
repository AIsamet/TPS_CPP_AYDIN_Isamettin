#ifndef Game_h
#define Game_h

#include "Player.h"
#include "Grid.h"
#include <chrono>
#include <thread>

//classe abstraite dont vont heriter les differents jeux
class Game
{

public:
	Game();

	inline Grid GetGameGrid() const { return gameGrid; }
	inline Grid& GetGameGridByReference() { return gameGrid; }
	inline Player GetPlayer1() const { return player1; }
	inline Player GetPlayer2() const { return player2; }
	inline int GetGameMode() const { return gameMode; }
	inline void SetGameMode(const int& NewSetting) { gameMode = NewSetting; }
	
	virtual void AskGameMode(); //fonction qui demande au joueur le type de jeu a lancer
	virtual void AskPlayersName(); //fonction qui demande aux joueurs leur pseudonyme
	
	virtual Player PlayRound() = 0; //fait jouer les tours des joueurs jusqu'a ce qu'il y ait un gagnant ou égalité
	virtual void StartGame() = 0; //lance la partie
	
	virtual bool CheckEquality() const = 0; //verifie le cas d'une égalité
	virtual bool CheckWin(const Player& player) const = 0; //verifie s'il y a un gagnant
	virtual bool CheckWinByLine(const Player& player) const = 0; //verifie s'il y a un gagnant par ligne
	virtual bool CheckWinByColumn(const Player& player) const = 0; //verifie s'il y a un gagnant par colonne
	virtual bool CheckWinByDiagonal(const Player& player) const = 0; //verifie s'il y a un gagnant par diagonal
	
protected:
	Grid gameGrid;
	Player player1;
	Player player2;
	int gameMode; //0 = multijoueur, 1 = joueur vs ordinateur
};

#include "Input.h"
#endif