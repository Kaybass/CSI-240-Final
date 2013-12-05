#include "item.h"
#include "snake.h"
#include "logger.h"

class Game
{
public:
	Game(const std::string logfile);
	~Game();

	virtual int runGame() = 0;
protected:
	logger * mLogger;
};

class OnePlayerGame: public Game
{
public:
	OnePlayerGame(const std::string logfile);
	~OnePlayerGame();

	virtual int runGame();
};