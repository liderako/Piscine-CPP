#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "Window.hpp"
#include "Ncurses.hpp"

int 	main(void) {
	int 		key;
	Ncurses 	n;
    Win 		window;
    Player		p;


  	window.updatePositionPlayer(p, 'w');
  	window.render(p);
  	while (1) {
		p.recharge();
  		key = n.getCh();
  		if (key == '\e') {
  			n.end();
  			std::exit(-1);
  		}
   		if (key == 'w' || key == 's' || key == 'a' || key == 'd' || key == ' '){
  			window.updatePositionPlayer(p, key);
  		}
  		window.checkSize();
  		window.updatePositionObjcet(p);
  		if (p.getLife() == 0 || p.getScope() == window.getMaxScope()) {
  			break ;
  		}
  		p.setScope(p.getScope() + 1);
		clear();
  		window.render(p);
		refresh();
		usleep(1);
  	}
  	n.end();
  	if (p.getScope() >= window.getMaxScope()) {
  		std::cout << "You win!!!!\n";
  	}
  	else {
		std::cout << "Game Over\n";
	}
}