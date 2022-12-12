#ifndef Game_h
#define Game_h

#include "Player.h"
#include "Grid.h"
#include "Inputs.h"
#include <chrono>
#include <thread>

// Classe mère des différents jeux
class Game
{
public:
	/**
	 * Getters
	**/
	inline Grid GetGrid() const { return grid; }
	inline Grid& GetGridByReference() { return grid; }
	inline Player GetPlayer1() const { return player1; }
	inline Player GetPlayer2() const { return player2; }
	inline int GetGameMode() const { return gameMode; }

	/**
	 * Setters
	**/
	inline void SetGameMode(const int& NewSetting) { gameMode = NewSetting; }

	/**
	 * Methodes
	**/
	virtual void AskGameMode();
	virtual void AskPlayersNames();

	virtual Player PlayRound() = 0;
	virtual void StartGame() = 0;

	virtual bool CheckEquality() const = 0;
	virtual bool CheckWin(const Player& player) const = 0;
	virtual bool CheckWinByLine(const Player& player) const = 0;
	virtual bool CheckWinByColumn(const Player& player) const = 0;
	virtual bool CheckWinByDiagonal(const Player& player) const = 0;

protected:
	/**
	 * Attributs
	**/
	Grid grid;
	Player player1;
	Player player2;
	int gameMode; // 0 = multijoueur, 1 = joueur vs IA
};

#endif