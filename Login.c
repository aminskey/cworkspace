#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>


void wpaint(WINDOW *, int, char);

int main(void)
{

	char name[200];
	char passwd[200];


	initscr();
	cbreak();
	noecho();

	WINDOW *login=newwin(getmaxy(stdscr)/2,getmaxx(stdscr)/2,getmaxy(stdscr)/2 - getmaxy(stdscr)/4, getmaxx(stdscr)/2 - getmaxx(stdscr)/4);


	start_color();
	init_pair(1, COLOR_WHITE, COLOR_CYAN);
	init_pair(2, COLOR_WHITE, COLOR_BLUE);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);


	wpaint(stdscr, 1, 176);

	wpaint(login, 2, 32);

	attron(COLOR_PAIR(3));
	for(int i=getbegy(login)+1;i<getmaxy(login)+11;i++)
		for(int j=getbegx(login)+1;j<getmaxx(login)+34;j++)
			mvprintw(i,j,"%c",(unsigned char)176);


	attroff(COLOR_PAIR(3));



	wattron(login, COLOR_PAIR(2));

	refresh();
	box(login,0,0);


	mvwprintw(login, 4, 5, "Login:");
	for(int i=11;i<getmaxx(login)-4;i++)
		mvwaddch(login,5,i,ACS_S1);


	mvwprintw(login, 7, 2, "Password:");
	for(int i=11;i<getmaxx(login)-4;i++)
		mvwaddch(login, 8,i,ACS_S1);






	wattroff(login, COLOR_PAIR(2));

	wrefresh(login);

	getch();
	endwin();

	return 0;
}

void wpaint(WINDOW *win, int pair, char chr)
{
	wattron(win, COLOR_PAIR(pair));
	for(int i=0;i<getmaxy(win);i++)
		for(int j=0;j<getmaxx(win);j++)
			mvwprintw(win,i,j,"%c",(unsigned char)chr);
	wattroff(win, COLOR_PAIR(pair));

}
