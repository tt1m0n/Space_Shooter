#include "Window.hpp"

int main() {



	Window game;

	Window game1;

	game1 = game;
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_RED);
	init_pair(7, COLOR_RED, COLOR_BLACK);
	init_pair(8, COLOR_WHITE, COLOR_WHITE);
	init_pair(9, COLOR_CYAN, COLOR_BLACK);
	
	game1.play ();
	return 0;
}
