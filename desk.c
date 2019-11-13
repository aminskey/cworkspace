#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<ncurses.h>

#define MAXY getmaxy(stdscr)
#define MAXX getmaxx(stdscr)

#define IMAXY MAXY
#define IMAXX MAXX

extern const char drva[];
extern const char drvc[];
extern const char drvd[];
extern const char drve[];
extern const char drvz[];

int ststate=1;

int drvchck(void);
void bluescreen(char *s);
void wpaint(WINDOW *,char, short);
void paint(char , short);
char drives[6]="ACDEZ";

#define paint(ch, clr) wpaint(stdscr, ch, clr)


int main(void){

	int c=0;


	initscr();
	noecho();
	cbreak();

	curs_set(0);

	WINDOW *menu=newwin(3,getmaxx(stdscr),getmaxy(stdscr)-3,0);
	WINDOW *mb2=newwin(24,24,(getmaxy(stdscr)-getmaxy(menu)-24),0);

	MEVENT evnt;

	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);


	if(drvchck())
		bluescreen("DESKTOP HAS CRASHED, BECAUSE YOUR DRIVES ARE DOWN!!");

	start_color();
	init_pair(1,COLOR_WHITE, COLOR_CYAN);
	init_pair(2,COLOR_WHITE, COLOR_BLUE);
	init_pair(3,COLOR_WHITE, COLOR_BLACK);
	init_pair(4,COLOR_BLUE, COLOR_WHITE);


	paint(32,1);

	refresh();
	wpaint(menu,32,4);
	wrefresh(menu);

	wattron(menu,COLOR_PAIR(4));
	mvwprintw(menu,1,1,"start");
	wattroff(menu,COLOR_PAIR(4));

	wrefresh(menu);

	keypad(stdscr, true);

	while(1){
		c=getch();
		if(c==KEY_MOUSE){
			if(getmouse(&evnt) == OK){
				if(evnt.bstate >= BUTTON1_PRESSED){
					if((evnt.y >= (getmaxy(stdscr)-getmaxy(menu)) && evnt.y <= getmaxy(stdscr)) || (evnt.x >= 1 && evnt.x <= strlen("start"))){
						mvwprintw(menu,1,1,"start");
						ststate=0;
						wrefresh(menu);
					}
				}
			}else{
				bluescreen("DESKTOP HAS CRASHED, BECAUSE THERE IS NO MOUSE");
			}
		}
		if(ststate == 0){
			usleep(250);

			refresh();

			wpaint(mb2,32,4);
			wattron(mb2,COLOR_PAIR(4));

			box(mb2,0,0);

			wattroff(mb2,COLOR_PAIR(4));
			wrefresh(mb2);

			ststate=1;
		}else if(ststate==1){
			wpaint(mb2,32,1);

			wrefresh(mb2);

			wattron(menu,COLOR_PAIR(4));
			mvwprintw(menu,1,1,"start");
			wattron(menu,COLOR_PAIR(4));

			wrefresh(menu);

		}
		if(c==KEY_F(9))
			break;
	}

	endwin();
	return 0;

}

void wpaint(WINDOW *win, char ch, short clr){
	wattron(win,COLOR_PAIR(clr));

	for(int i=0;i<getmaxy(win);i++)
		for(int j=0;j<getmaxx(win);j++)
			mvwprintw(win,i,j,"%c",ch);

	wattroff(win, COLOR_PAIR(clr));
}

void bluescreen(char *s){
	curs_set(0);

	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	paint(32,1);

	mvprintw(MAXY/6,(MAXX-strlen(s))/2,"%s",s);

	for(int i=0;i<strlen(drives);i++){
		mvprintw(20+(i+1),40,"DRIVE %c:",drives[i]);
	}
	mvprintw(21,50,"%s",drva);
	mvprintw(22,50,"%s",drvc);
        mvprintw(23,50,"%s",drvd);
        mvprintw(24,50,"%s",drve);
        mvprintw(25,50,"%s",drvz);

	getch();
	endwin();

	perror("Something Went Wrong");
	exit(EOF);

}

int drvchck(void){
	int cd=0;


	extern const char drva[];
	extern const char drvc[];
	extern const char drvd[];
	extern const char drve[];
	extern const char drvz[];

	return ((cd=chdir(drva)) >= 0)? cd : EOF;
	return ((cd=chdir(drvc)) >= 0)? cd : EOF;
	return ((cd=chdir(drvd)) >= 0)? cd : EOF;
	return ((cd=chdir(drve)) >= 0)? cd : EOF;
	return ((cd=chdir(drvz)) >= 0)? cd : EOF;
}
