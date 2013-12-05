#include "game.h"
#include <Windows.h>
#include <time.h>
#include <iostream>
#include <string>
#include <sstream>


Game::Game(const std::string logfile)
{
	mLogger = new logger(logfile);
}

Game::~Game()
{
	delete mLogger;
}

OnePlayerGame::OnePlayerGame(const std::string logfile)
:Game(logfile)
{
}

OnePlayerGame::~OnePlayerGame()
{
	delete mLogger;
}

int OnePlayerGame::runGame()
{
	system("cls");

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	Snake * pSnake = new PlayerSnake(handle);

	int currentdirection = 1;

	pSnake->addHead(10,5,1);
	for(int i = 1; i < 6; i++)
	{
		pSnake->addTail(10 - i,5, 1);
	}

	Food * pFood = new Food(handle);

	do
	{
		if(GetAsyncKeyState(VK_UP) != 0)
		{
			if(currentdirection != 0)
				currentdirection--;
			else
				currentdirection = 3;
		}
		else if(GetAsyncKeyState(VK_DOWN) != 0)
		{
			if(currentdirection != 3)
				currentdirection++;
			else
				currentdirection = 0;
		}
		else if(GetAsyncKeyState(VK_ESCAPE) != 0)
		{
			delete pFood;
			delete pSnake;
			return 1;
		}
		pSnake->update(currentdirection);
		pFood->draw();
		Sleep(100);
		system("cls");

		if(pSnake->checkCollision(pFood->getX(),pFood->getY()))
		{
			pSnake->addFood(pFood);
			pFood = new Food(handle);
		}

	}while(pSnake->checkSelfCollision() == 0 && pSnake->checkWalls() == 0);
	
	std::cout << "Your score is " << pSnake->getLength() - 6 << '\n' << '\n';
	std::stringstream ss;

	system("pause");

	ss << " GAME LOST, SCORE: " << pSnake->getLength() - 6;

	mLogger->log(ss.str());

	delete pFood;
	delete pSnake;
	return 0;
}