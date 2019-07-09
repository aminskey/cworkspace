<<<<<<< HEAD
#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "libs/node.h"

void wpaint(WINDOW *, int, char);


int main(void)
{

	char name[KB];
	char passswd[KB];
=======
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
>>>>>>> f2f87298c9b82f3788041aa32eb958ec04002fc2


	initscr();
	cbreak();
	noecho();

<<<<<<< HEAD
	//Creating Windows
	WINDOW *login=newwin(getmaxy(stdscr)/2, getmaxx(stdscr)/2, getmaxy(stdscr)/2 - getmaxy(stdscr)/4, getmaxx(stdscr)/2 - getmaxx(stdscr)/4);
	WINDOW *sublogn=subwin(login,getmaxy(login)-2,getmaxx(login)-2,1,1);


	//initiating pairs and color
=======
	WINDOW *login=newwin(getmaxy(stdscr)/2,getmaxx(stdscr)/2,getmaxy(stdscr)/2 - getmaxy(stdscr)/4, getmaxx(stdscr)/2 - getmaxx(stdscr)/4);


>>>>>>> f2f87298c9b82f3788041aa32eb958ec04002fc2
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_CYAN);
	init_pair(2, COLOR_WHITE, COLOR_BLUE);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);


<<<<<<< HEAD
	wpaint(stdscr,1,176);


	attron(COLOR_PAIR(3));


        for(int i=getbegy(login)+1;i<getmaxy(login)+(getmaxy(login)-11); ++i)
                for(int j=getbegx(login)+1;j<getmaxx(login)+(getmaxx(login)-41); ++j)
                        mvprintw(i, j, "%c", (unsigned char)176);

        attroff(COLOR_PAIR(3));


	wpaint(login, 2, 32);

=======
	wpaint(stdscr, 1, 176);

	wpaint(login, 2, 32);

	attron(COLOR_PAIR(3));
	for(int i=getbegy(login)+1;i<getmaxy(login)+11;i++)
		for(int j=getbegx(login)+1;j<getmaxx(login)+34;j++)
			mvprintw(i,j,"%c",(unsigned char)176);


	attroff(COLOR_PAIR(3));



>>>>>>> f2f87298c9b82f3788041aa32eb958ec04002fc2
	wattron(login, COLOR_PAIR(2));

	refresh();
	box(login,0,0);

<<<<<<< HEAD
	mvwprintw(login,4,2,"Login:");
	for(int i=9;i<getmaxx(login)-2;i++)
		mvwaddch(login,5,i,ACS_S1);




=======

	mvwprintw(login, 4, 5, "Login:");
	for(int i=11;i<getmaxx(login)-4;i++)
		mvwaddch(login,5,i,ACS_S1);


	mvwprintw(login, 7, 2, "Password:");
	for(int i=11;i<getmaxx(login)-4;i++)
		mvwaddch(login, 8,i,ACS_S1);
>>>>>>> f2f87298c9b82f3788041aa32eb958ec04002fc2






<<<<<<< HEAD
	wrefresh(login);
	wattroff(login, COLOR_PAIR(2));



=======
	wattroff(login, COLOR_PAIR(2));

	wrefresh(login);
>>>>>>> f2f87298c9b82f3788041aa32eb958ec04002fc2

	getch();
	endwin();

	return 0;
<<<<<<< HEAD

}
void wpaint(WINDOW *win, int pair, char ch){
	wattron(win, COLOR_PAIR(pair));

	for(int i=0;i<getmaxy(win);i++)
	{
		for(int j=0;j<getmaxx(win);j++)
		{
			mvwprintw(win,i,j,"%c",(unsigned char)ch);
		}
	}

=======
}

void wpaint(WINDOW *win, int pair, char chr)
{
	wattron(win, COLOR_PAIR(pair));
	for(int i=0;i<getmaxy(win);i++)
		for(int j=0;j<getmaxx(win);j++)
			mvwprintw(win,i,j,"%c",(unsigned char)chr);
>>>>>>> f2f87298c9b82f3788041aa32eb958ec04002fc2
	wattroff(win, COLOR_PAIR(pair));

}
