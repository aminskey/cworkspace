#include<ncurses.h>

int main(void)
{
	initscr();
	cbreak();
	noecho();

	int y = getmaxy(stdscr);
	int x = getmaxx(stdscr);

	endwin();

	printf("y=%d x=%d\n",y,x);

	return 0;
}
