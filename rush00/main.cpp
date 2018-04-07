#include <iostream>
#include <ncurses.h>
#include "Window.hpp"
#include "Ncurses.hpp"

int 	main(void) {
	Ncurses 	n;
    Win 		window;

  	// window.updateDisplay();
  	// n.updateWindow(window.getWINDOW());
  	while (1) {
  		window.updateDisplay();
  		n.updateWindow(window.getWINDOW());
  		n.getCh();
  		// wrefresh();
  	}
}