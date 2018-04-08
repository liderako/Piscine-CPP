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
  	window.render();
  	start_color();
  	init_color(5, 233, 51, 55);
  	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, 5, COLOR_BLACK);
  	while (1) {//p.endGame() == false) {
		p.recharge();
  		key = n.getCh();
   		if (key == 'w' || key == 's' || key == 'a' || key == 'd' || key == ' '){
  			window.updatePositionPlayer(p, key);
  		}

  		
  		// int x = 0;
  		// int y = 0;
		//getmaxyx(stdscr, y, x);
		
		// if (window.getHeight() != y || window.getWidth() != x) {
		// 	 n.end();
		// 	 std::cout << "Don't touch window! Pidor\n";
		// 	 std::exit(-1);
		// }


  		window.updatePositionObjcet(p);
  		// if (p.getHp() == 0) {
  		// 	break ;
  		// }
		clear();
  		window.render();
		refresh();
		usleep(1);
  	}
  	n.end();
	std::cout << "Game Over\n";
}