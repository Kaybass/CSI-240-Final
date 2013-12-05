#include "game.h"

int main()
{
	Game * pGame = new OnePlayerGame("TheLog.txt");

	int i = 0;
	while(i != 1)
	{
		i = pGame->runGame();
	}
	delete pGame;
}