#include<stdio.h>
#include<ncurses.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<unistd.h>

void wpaint(WINDOW *,int, int, short);


int a[]={176,177,178};


char p[8][20]={
"##########",
"#         #",
"#         #",
"#        #",
"#########",
"#",
"#",
"#\to l a r\t\tB l o c k",
};


int main(void)
{
	initscr();
	cbreak();
	noecho();
	start_color();

	init_pair(1, COLOR_WHITE,COLOR_CYAN);
	

	MEVENT mv;

	mousemask(ALL_MOUSE_EVENTS, NULL);

	WINDOW *lg=newwin(getmaxy(stdscr)/2,getmaxx(stdscr)/2,(getmaxy(stdscr)/2-getmaxy(stdscr)/4),(getmaxx(stdscr)/2-getmaxx(stdscr)/4));

	WINDOW *men = newwin(3,getmaxx(stdscr),getmaxy(stdscr)-3,0);


	int c=0;

	keypad(stdscr,true);
	keypad(men,true);

	wpaint(stdscr,getmaxy(stdscr),getmaxx(stdscr), COLOR_PAIR(1));
	
	refresh();

	wattron(lg, COLOR_PAIR(1));
	box(lg,0,0);

	wattroff(lg,COLOR_PAIR(1));	
	wrefresh(lg);

	wmove(lg, 1,getmaxx(lg)/4);


	wpaint(lg,getmaxy(lg),getmaxx(stdscr),COLOR_PAIR(1));
	
	wattron(lg,COLOR_PAIR(1));

	for(int i=1;i<getmaxy(lg)-1;i++)
		for(int j=getmaxx(lg)/4;j<(getmaxx(lg)/2)-1;j++)
			mvwprintw(lg,i,j,"%c",(unsigned char)a[rand()%3]);

	for(int i=0;i<strlen(p[2]);i++)
		mvwprintw(lg,i,getmaxx(lg)/2,"%s",p[i]);


	wattroff(lg, COLOR_PAIR(1));

	wrefresh(lg);


	wattron(men, A_REVERSE);
        refresh();
        box(men,0,0);                
	wpaint(men,getmaxy(men),getmaxx(men),COLOR_PAIR(1));
	mvwprintw(men,1,1,"Start");
	wrefresh(men);
        wattroff(men, A_REVERSE);

	while(1)
	{
		c=getch();

		if(c == KEY_F(12)){
			break;	
		}
		if(c == KEY_MOUSE)
		{
			if(getmouse(&mv) == OK)
			{
				if((mv.y > 1 && mv.y < getmaxy(men)) && (mv.x > 1 && mv.x < 7))
					printw("Start!!");
			}

			
		}
	}

	
	endwin();
	return 0;
}
void wpaint(WINDOW *win, int i, int j,short COLOR_NUM)
{
	wattron(win, COLOR_NUM);

	for(i=0;i<getmaxy(win);i++)
		for(j=0;j<getmaxx(win);j++)
			mvwprintw(win,i,j," ");

	wattroff(win, COLOR_NUM);
}
