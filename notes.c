#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<ncurses.h>

void wpaint(WINDOW *, int, int, short, char);

void wfill(WINDOW *win, short pair, char c){
	wpaint(win, getmaxy(win), getmaxx(win), );
}

void paint(int y, int x, short pair, char c){
	wpaint(stdscr, y, x, pair, c);
}


int main(void){
	initscr();
	cbreak();
	noecho();


	WINDOW *edit=newwin(getmaxy(stdscr)/2,getmaxx(stdscr),1,0);

	start_color();
	init_pair(1, COLOR_RED, COLOR_GREY);
	init_pair(2, COLOR_WHITE, COLOR_BLUE);

	

}
void wpaint(WINDOW *win, int y, int x, short pair, char c){
	wattron(win, COLOR_PAIR(pair));
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			mvwprintw(win,i,j,"%c");
		}
	}
	wattroff(win, COLOR_PAIR(pair));
	
}
