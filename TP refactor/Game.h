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
	
	virtual void InputPlayer(Player player) = 0; //demande une entr�e au joueur
	virtual int BotRandomInputGenerator() = 0; //genere une case vide a jouer al�atoirement par le bot
	virtual void AskGameType() = 0; //fonction qui demande au joueur le type de jeu a lancer
	virtual void AskPlayersName() = 0; //fonction qui demande aux joueurs leur pseudonyme
	
	virtual Player PlayRound() = 0; //fait jouer les tours des joueurs jusqu'a ce qu'il y ait un gagnant ou �galit�
	virtual void StartGame() = 0; //lance la partie
	
	virtual bool CheckEquality() const = 0; //verifie le cas d'une �galit�
	virtual bool CheckWin(const Player& player) const = 0; //verifie s'il y a un gagnant
	virtual bool CheckWinByLine(const Player& player) const = 0; //verifie s'il y a un gagnant par ligne
	virtual bool CheckWinByColumn(const Player& player) const = 0; //verifie s'il y a un gagnant par colonne
	virtual bool CheckWinByDiagonal(const Player& player) const = 0; //verifie s'il y a un gagnant par diagonal
	
private:

};

#endif