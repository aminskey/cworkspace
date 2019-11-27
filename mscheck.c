#include<ncurses.h>
#include<stdio.h>

int main(void){
	int c=0;

	initscr();
	noecho();
	cbreak();

	MEVENT me;

	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

	keypad(stdscr,true);

	printf("\033[?1003h");
	while(1){
		c=getch();
		if(c == KEY_MOUSE){
			move(me.y, me.x);
			if(getmouse(&me) == OK){
				mouse_trafo(&me.y, &me.x, true);
//				mvprintw(1,1,"y:%d x:%d",me.y, me.x);
			}
			else{
				printw("cat killed the mouse");
			}
		}else if(c == KEY_F(5))
			break;
	}

	printf("\033[?1003l");

	endwin();
	return 0;
}
