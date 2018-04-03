#include <iostream>
#include "Logger.hpp"

int main(){
	Logger log;

	log.log("logToFile", "Yoy bro, this message for file.=)");
	log.log("logToConsole", "Hello, this message for console.+_+)");
}