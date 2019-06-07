#include<ncurses.h>

int main(void)
{
	initscr();
	cbreak();
	noecho();

	int d = getmaxy(stdscr);

	endwin();

	printf("%d",d);

	return 0;
}
