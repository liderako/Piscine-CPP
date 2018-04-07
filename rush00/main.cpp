#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "Window.hpp"
#include "Ncurses.hpp"

int 	main(void) {
	Ncurses 	n;
    Win 		window;
    Player		p;


  	window.updatePositionPlayer(p, 0);
  	window.updateDisplay();
  	while (1) {
		p.setCountTime(p.getCountTime() + 1);
  		timeout(300);
  		int key = getch();
   		if (key == 'w' || key == 's' || key == 'a' || key == 'd' || key == ' '){
  			window.updatePositionPlayer(p, key);
  		}
  		window.updatePositionObjcet(p);
  		if (p.getHp() == 0) {
  			break ;
  		}
  		clear();
  		window.updateDisplay();
		refresh();
		usleep(1);
  		key = 0;
  	}
  	endwin();
  	clear();
	std::cout << "Game Over\n";
	std::exit(-1);
}