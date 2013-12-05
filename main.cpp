/*
Author: Alexander Bean Apmann
Class: Dean Lawson's
Assignment: Final
Date Assigned: November
Due Date: December
Description: Snaaaaaaaaaaake
Certification of Authenticity:
I certify that this assignment is entirely my own work.
*/

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
