#include<stdio.h>
#include<ncurses.h>

int main(void){
	initscr();
	cbreak();
	noecho();

	for(int i=43;i<256;i++){
		if(i == 127)
			addch(' ');

		printw("%4d = ",i);
		addch(i | A_ALTCHARSET);
		addch(ACS_VLINE);
		addch(' ');
		if(i % 10 == 0){
			addch('\n');
		}
	}
	getch();
	endwin();
}
