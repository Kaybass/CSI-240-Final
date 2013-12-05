#include <fstream>
#include <string>

class logger
{
public:
	logger(std::string logfile);
	~logger();

	void log(std::string logevent);
private:
	std::ofstream mFile;
};