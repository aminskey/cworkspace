#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "libs/node.h"

int main(void)
{
	char name[KB/2];
	char passwd[KB/2];

	initscr();
	cbreak();
	noecho();

	for(int i=0;i<getmaxy(stdscr);i++)
		for(int j=0;j<getmaxx(stdscr);j++)
			mvprintw(i,j," ");



	getch();
	endwin();
}
