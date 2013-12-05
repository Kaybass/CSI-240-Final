#include "game.h"

int main()
{
	Game * pGame = new OnePlayerGame("TheLog.txt");

	pGame->runGame();

	delete pGame;
}