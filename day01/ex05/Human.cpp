#include "Human.hpp"

Human::Human( void ) {
	brain = Brain();
	return ;
}

Human::~Human( void ) {
	return ;
}

std::string		Human::identify( void ) {
	return ( this->brain.identify() ); 
}

Brain			Human::getBrain( void ) {
	return (this->brain);
}
