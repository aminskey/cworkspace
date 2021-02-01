#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>
#include<time.h>

struct Ship{
	int cargoMax;
	int passengers;
	int crew;
	char *weopons;
};

char *fighter[] = {
	"			   ",
	"		#########  ",
        "		      #### ",
	"	################## ",
	"######################### ",
        "	################## ",
	"		      #### ",
	"		#########  ",
	"			   ",
};
char *barge[] = {
	"#######################    ",
	"       ################    ",
	"       #################   ",
	"###########################",
	"###########################",
	"       #################   ",
	"       ################    ",
	"#######################    ",

};


char *elevator[]={
	"          ",
	"##########",
	"#   ##   #",
	"#   ##   #",
	"#   ##   #",
	"#   ##   #",
	"##########"
};


int main(void)
{
	initscr();
	cbreak();
	noecho();

	curs_set(0);

	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLUE);
	init_pair(3, COLOR_WHITE, COLOR_GREEN);

	paint(32,1);

	for(int j=0; j<100; j++){
		srand(time(NULL));

		for(int i=0;i<1000;i++){
			mvaddch(rand()%getmaxy(stdscr),rand()%getmaxx(stdscr), 96 | A_ALTCHARSET);
		}

		delay_output(50);
		refresh();

		clear();
	}
	paint(32,3);

	for(int k=0;k<450;k++){
		attron(COLOR_PAIR(1));
		for(int i=-1;i<getmaxy(stdscr);i++){
			for(int j=0;j<i*k;j++){
				mvaddch(i, j, 32);
				if(j % 20 == 0)
					mvaddch(i, j, 120 | A_ALTCHARSET);
			}
		}
		attroff(COLOR_PAIR(1));
		delay_output(100);
		refresh();
	}

	endwin();


}
