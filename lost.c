#include<string.h>
#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>

void wpaint(WINDOW *, int , int , int);

int moveNotOk(int, int);

int main(void)
{

	initscr();
	noecho();
	cbreak();

	curs_set(0);

	start_color();

	int a=0;
	
	char plc=(unsigned char)178;	
	int px=getmaxx(stdscr)/2;
	int py=getmaxy(stdscr)/2;

	WINDOW *win=newwin(getmaxy(stdscr)/2,getmaxx(stdscr)/2,getmaxy(stdscr)/2-getmaxy(stdscr)/4,getmaxx(stdscr)/2-getmaxx(stdscr)/4);

	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_BLUE, COLOR_WHITE);
	init_pair(3, COLOR_BLACK, COLOR_RED);

	init_pair(4,COLOR_RED,COLOR_BLACK);
	init_pair(5,COLOR_CYAN,COLOR_BLUE);
	init_pair(6,COLOR_CYAN,COLOR_WHITE);
	init_pair(7,COLOR_MAGENTA,COLOR_RED);

	srand(time(NULL));

	a=rand()%4;


	int const b=rand()%getmaxx(stdscr);
        int const d=rand()%getmaxy(stdscr);


	int c=0;


start:
	attron(COLOR_PAIR(a));
        wpaint(stdscr,getmaxy(stdscr),getmaxx(stdscr),32);


	if(a == 0)
	{
		mvprintw(0,0,"DARK SKY|");
		mvprintw(1,0,"---------");
	}
	else if(a == 1)
	{
		mvprintw(0,0,"River|");
		mvprintw(1,0,"------");
	}
	else if(a == 2)
	{
		mvprintw(0,0,"Paper|");
		mvprintw(1,0,"------");
	}
	else{
		mvprintw(0,0,"Volcano Rim|");
		mvprintw(1,0,"------------");
	}
	
	attroff(COLOR_PAIR(a));
	
		
	attron(COLOR_PAIR(a));
	mvprintw(d,b,"X");
	attroff(COLOR_PAIR(a));
	
	refresh();
	delay_output(1000);

	attron(COLOR_PAIR(a));
	mvprintw(d,b," ");
	attroff(COLOR_PAIR(a));

	attron(COLOR_PAIR(a));
	px=getmaxx(stdscr)/2;
	py=getmaxy(stdscr)/2;

	mvprintw(py,px,"%c",plc);


	
	refresh();

	
	keypad(stdscr, true);

	while(1)
	{

		if(py == d && px == b)
			break;

		refresh();
	
		c=getch();
		switch(c)
		{
			case KEY_UP:
				if(moveNotOk(py-1,px)==TRUE)
				{

					py=py;
				}else{
					py=py-1;
				}
				
				break;
			case KEY_DOWN:
				if(moveNotOk(py+1,px)==TRUE)
				{
					py=py;
                                }else{
					py=py+1;
				}				

				break;
			case KEY_LEFT:
				if(moveNotOk(py,px-1)==TRUE)
				{
					px=px;
				}else{
					px=px-1;
				}
				
				break;
			case KEY_RIGHT:
				if(moveNotOk(py,px+1)==TRUE){
					px=px;
                                }else{
					px++;
				}
				break;
			

			case 'r':
				goto start;
			
			default:
				px=px;
				py=py;
				break;
		}

		
		mvprintw(py,px,"%c",plc);
	}
	attroff(COLOR_PAIR(a));

	refresh();
	wattron(win,A_REVERSE);

	wpaint(win,getmaxy(win),getmaxx(win),(unsigned char)176);
	box(win,0,0);


	wattroff(win,A_REVERSE);
	wrefresh(win);

	
	wattron(win,COLOR_PAIR(a=rand()%3));
	mvwprintw(win,getmaxy(win)/2,(getmaxx(win)-strlen("you made it, you opened the secret door!"))/2,"You Made It, You Opened The Secret Door!");
	wrefresh(win);
	wattroff(win,COLOR_PAIR(a));

	
	refresh();
	delay_output(3000);
	
	getch();
	endwin();
}

void wpaint(WINDOW *win, int a, int b, int c)
{
	int i=0,j=0;

	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
			mvwprintw(win,i,j,"%c",(unsigned char)c);
	}
}

int moveNotOk(int y, int x)
{
	int check=mvinch(y,x);

	return ((check == '|')||(check == '-')||(check == (unsigned char)178)||(check == (unsigned char)177)||(check == (unsigned char)176));

}

