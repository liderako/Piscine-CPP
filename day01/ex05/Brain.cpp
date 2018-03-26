#include "Brain.hpp"

Brain::Brain( void ) {
	std::stringstream 	s;
	s << std::hex << this;
	this->memoryAddress = s.str();	
	return ;
}

Brain::~Brain( void ) {
	return ;
}

std::string		Brain::identify( void ) {
	return ( memoryAddress );
}

