#ifndef Morpion_h
#define Morpion_h

#include "Game.h"
#include "Input.h"

class Morpion : public Game
{

public:
	Morpion();
	Morpion(string player1Name, string player2Name);
	
	inline Grid GetGameGridMorpion() const { return gameGridMorpion; }
	inline Grid& GetGameGridMorpionByReference() { return gameGridMorpion; }
	inline Player GetPlayer1() const { return player1; }
	inline Player GetPlayer2() const { return player2; }
	inline int GetGameMode() const { return gameMode; }
	inline void SetGameMode(const int& NewSetting) { gameMode = NewSetting; }
	
	void InputPlayer(Player player) override;
	int BotRandomInputGenerator() override;
	void AskGameType() override;
	void AskPlayersName() override;
	
	Player PlayRound() override;
	void StartGame() override;
	
	bool CheckEquality() const override;
	bool CheckWin(const Player& player) const override;
	bool CheckWinByLine(const Player& player) const override;
	bool CheckWinByColumn(const Player& player) const override;
	bool CheckWinByDiagonal(const Player& player) const override;

private:
	Grid gameGridMorpion;
	Player player1;
	Player player2;
	int gameMode; //0 = multijoueur, 1 = joueur vs ordinateur
};

#endif