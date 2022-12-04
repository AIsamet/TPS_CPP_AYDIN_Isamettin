#ifndef Puissance4_h
#define Puissance4_h

#include "Game.h"

class Puissance4 : public Game
{

public:
	Puissance4();
	Puissance4(string player1Name, string player2Name);

	inline Player GetPlayer1() const { return player1; }
	inline Player GetPlayer2() const { return player2; }
	inline int GetGameMode() const { return gameMode; }
	inline void SetGameMode(const int& NewSetting) { gameMode = NewSetting; }

	void InitGrid(const int& line, const int& column) override;
	void DisplayPlate() const override;
	
	void InputPlayer(Player player) override;
	int BotRandomInputGenerator() override;
	void AskGameType() override;
	void AskPlayersName() override;
	
	Player PlayGame() override;
	void StartGame() override;
	
	bool CheckEquality() const override;
	bool CheckWin(const Player& player) const override;
	bool CheckWinByLine(const Player& player) const override;
	bool CheckWinByColumn(const Player& player) const override;
	bool CheckWinByDiagonal(const Player& player) const override;

private:
	vector<vector<Cell> > gameGrid;
	Player player1;
	Player player2;
	int gameMode; //0 = multijoueur, 1 = joueur vs ordinateur
};

#endif