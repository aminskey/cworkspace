#include<stdio.h>
#include<ncurses.h>


void printOps(WINDOW *);

int main(void){

	initscr();
	cbreak();
	noecho();

	curs_set(0);

	WINDOW *tbl=newwin(20,getmaxx(stdscr)/2,getmaxy(stdscr)/2 - getmaxy(stdscr)/4, getmaxx(stdscr)/2 - getmaxx(stdscr)/4);



	refresh();

	wborder(tbl,32,32,0,0,ACS_HLINE,ACS_HLINE,ACS_HLINE,ACS_HLINE);


	mvwprintw(tbl,0,getmaxx(tbl)/4 + getmaxx(tbl)/2,"%c",(unsigned char)210);

	for(int j=0;j<getmaxx(tbl);j++)
		mvwaddch(tbl, 3, j, ACS_HLINE);

	for(int i=1;i<getmaxy(tbl)-1;i++)
	{
		mvwprintw(tbl,i,getmaxx(tbl)/4 + getmaxx(tbl)/2,"%c",(unsigned char)186);
		if(i == 3)
			mvwprintw(tbl,i,getmaxx(tbl)/4 + getmaxx(tbl)/2,"%c",(unsigned char)215);
	}
	mvwprintw(tbl,getmaxy(tbl)-1,getmaxx(tbl)/4 + getmaxx(tbl)/2,"%c",(unsigned char)208);

	mvwprintw(tbl,2, getmaxx(tbl)/4,"Operators");
	mvwprintw(tbl,2, (getmaxx(tbl)/4 + getmaxx(tbl)/2)+3,"Associatibity");
	wrefresh(tbl);

	printOps(tbl);
        wrefresh(tbl);

	getch();
	endwin();

	return 0;
}
void printOps(WINDOW *win){

	char ops[15][40]={"()   []   ->   .","! ~ ++ -- + - * & (type) sizeof","*   /   %","+   -","<<   >>","<     <=   >   >=","==  !=","&","^","|","&&","||","?:","= += -= *= /= %= &= ^= |= <<= >>=",","};
	char lr[15][40]={"Left to Right","Right to Left"};

	for(int i=0;i<getmaxy(win)-1;i++)
		mvwprintw(win, i+4, 0,"%s",ops[i]);

 	for(int j=4;j<getmaxy(win)-1;++j){
                mvwprintw(win, j, (getmaxx(win)/4 + getmaxx(win)/2)+3,"%s",lr[0]);
		if(j == 5 || j == 16 || j == 17)
			mvwprintw(win, j, (getmaxx(win)/4 + getmaxx(win)/2)+3,"%s",lr[1]);
	}

	mvwaddch(win,getmaxy(win)-1,0,ACS_HLINE);

}
