#include "logger.h"

logger::logger(std::string logfile)
{
	mFile.open(logfile);
}

logger::~logger()
{
	mFile.close();
}

void logger::log(std::string logevent)
{
	if (mFile.good())
	{
		mFile << "GAME-EVENT: " << logevent << '\n';
	}
}