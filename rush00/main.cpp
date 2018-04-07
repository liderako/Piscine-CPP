#include <iostream>
#include <ncurses.h>
#include "Window.hpp"
#include "Ncurses.hpp"

int 	main(void) {
	Ncurses n;
    Win 	window;

  	int i = 0;
  	int j = 0;
  	while (i < window.getWidth()){
  		printw("A");
  		j = 0;
  		while (j < window.getHeight()) {
  		  	printw("A");
  			j++;
   		}
   		i++;
   	}
  	n.updateWindow(window.getWINDOW());
  	n.getCh();
}