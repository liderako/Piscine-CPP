#include "Logger.hpp"

void	Logger::logToConsole(std::string const & message) {
	std::cout << this->makeLogEntry(message) << '\n';
}

void	Logger::logToFile(std::string const & message) {
	std::fstream file;
	
	file.open("logFile", std::fstream::in | std::fstream::out | std::fstream::app);
	file << this->makeLogEntry(message) << '\n';
}

std::string	Logger::makeLogEntry(std::string const & message) {
	time_t t = time(0);
	struct tm * now = localtime( & t );
	std::stringstream 	s;
	s << "[" << now->tm_year + 1900; // year
	// mon
	if (now->tm_mon < 10)
		s << '0' << now->tm_mon;
	else
		s << now->tm_mon;
	// day
	if (now->tm_mday < 10)
		s << '0' << now->tm_mday << '_';
	else
		s << now->tm_mday << "_";
	// hour
	if (now->tm_hour < 10)
		s << '0' << now->tm_hour;
	else
		s << now->tm_hour;
	// min
	if (now->tm_min < 10)
		s << '0' << now->tm_min;
	else
		s << now->tm_min;
	// sec
	if (now->tm_sec < 10)
		s << '0' << now->tm_sec;
	else
		s << now->tm_sec;
	s << "] ";
	s << message;
	std::string copy = s.str();
	return copy;
}

void	Logger::log(std::string const & dest, std::string const & message) {
	typedef void (Logger::*dest_t)(std::string const &message);

	dest_t list_action[] = {&Logger::logToFile, &Logger::logToConsole};
	std::string list_dest[] = {"logToFile", "logToConsole"};

	for (size_t i = 0; i < 2; ++i) {
		if ((list_dest[i].compare(dest)) == 0){
			(this->*list_action[i])(message);
		}
	}
}