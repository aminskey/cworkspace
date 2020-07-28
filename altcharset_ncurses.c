#include<ncurses.h>
#include<stdio.h>

int main(void){
	initscr();
	cbreak();
	noecho();

	curs_set(0);

	for(int i=43;i<255;i++){
		printw("%5d - ",i);
		addch(i|A_ALTCHARSET);
		addch(120|A_ALTCHARSET);
		//printw("");

		if(i % 20 == 0)
			printw("\n");
		if(i == 127)
			addch(32);
	}

	getch();
	endwin();

	return 0;
}
