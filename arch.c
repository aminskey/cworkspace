#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>


#define KB 1000
#define MB KB*KB
#define GB MB*KB

char arch[16][172] = 
{
"               AAA                                                     hhhhhhh               iiii",
"              A:::A                                                    h:::::h              i::::i",                                          
"             A:::::A                                                   h:::::h               iiii",                                           
"            A:::::::A                                                  h:::::h",                                                 
"           A:::::::::A          rrrrr   rrrrrrrrr       cccccccccccccccch::::h hhhhh       iiiiiiivvvvvvv           vvvvvvv eeeeeeeeeeee",    
"          A:::::A:::::A         r::::rrr:::::::::r    cc:::::::::::::::ch::::hh:::::hhh    i:::::i v:::::v         v:::::vee::::::::::::ee",  
"         A:::::A A:::::A        r:::::::::::::::::r  c:::::::::::::::::ch::::::::::::::hh   i::::i  v:::::v       v:::::ve::::::eeeee:::::ee",
"        A:::::A   A:::::A       rr::::::rrrrr::::::rc:::::::cccccc:::::ch:::::::hhh::::::h  i::::i   v:::::v     v:::::ve::::::e     e:::::e",
"       A:::::A     A:::::A       r:::::r     r:::::rc::::::c     ccccccch::::::h   h::::::h i::::i    v:::::v   v:::::v e:::::::eeeee::::::e",
"      A:::::AAAAAAAAA:::::A      r:::::r     rrrrrrrc:::::c             h:::::h     h:::::h i::::i     v:::::v v:::::v  e:::::::::::::::::e", 
"     A:::::::::::::::::::::A     r:::::r            c:::::c             h:::::h     h:::::h i::::i      v:::::v:::::v   e::::::eeeeeeeeeee",  
"    A:::::AAAAAAAAAAAAA:::::A    r:::::r            c::::::c     ccccccch:::::h     h:::::h i::::i       v:::::::::v    e:::::::e",           
"   A:::::A             A:::::A   r:::::r            c:::::::cccccc:::::ch:::::h     h:::::hi::::::i       v:::::::v     e::::::::e",          
"  A:::::A               A:::::A  r:::::r             c:::::::::::::::::ch:::::h     h:::::hi::::::i        v:::::v       e::::::::eeeeeeee",  
" A:::::A                 A:::::A r:::::r              cc:::::::::::::::ch:::::h     h:::::hi::::::i         v:::v         ee:::::::::::::e",  
"AAAAAAA                   AAAAAAArrrrrrr                cccccccccccccccchhhhhhh     hhhhhhhiiiiiiii          vvv            eeeeeeeeeeeeee"  
};


int main(int argc, char *argv[])
{


	initscr();
	noecho();
	cbreak();

	start_color();

	curs_set(0);


	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_WHITE, COLOR_GREEN);
	init_pair(4, COLOR_WHITE, COLOR_RED);

	WINDOW *search=newwin(3,getmaxx(stdscr)/2 ,getmaxy(stdscr)/2 - 1,getmaxx(stdscr)/2 - getmaxx(stdscr)/3);
	WINDOW *err=newwin(8,50,getmaxy(stdscr)/2,(getmaxx(stdscr)-30)/2);

	char s[KB];

	int a=0;

	srand(time(NULL));

	a=rand()%3;

start:
	clear();
	attron(COLOR_PAIR(a));

	for(int i=0;i<getmaxy(stdscr);i++)
		for(int j=0;j<getmaxx(stdscr);j++)
			mvprintw(i,j," ");


	for(int i=0;i<16;i++)
		for(int j=0;j<172;j++)
			mvprintw(i,j+20,"%c",arch[i][j]);

	attroff(COLOR_PAIR(a));



	refresh();
	wattron(search,COLOR_PAIR(a));

	for(int i=0;i<getmaxy(search);i++)
		for(int j=0;j<getmaxx(search);j++)
			mvwprintw(search,i,j," ");


	box(search,0,0);

	wrefresh(search);

	char srch[KB];

	echo();
	while(1){
		sprintf(srch," ");


		mvwscanw(search,1,1,"%s",s);


		sprintf(srch,"/Users/Amin/.archive/%s",s);

		if(strcmp(s,"end")==false)
			break;
		else{
			FILE *fp=fopen(srch,"r");

			if(fp == NULL){
			        attron(COLOR_PAIR(a));

        			for(int i=0;i<getmaxy(stdscr);i++)
        	        		for(int j=0;j<getmaxx(stdscr);j++)
                        			mvprintw(i,j," ");

				attroff(COLOR_PAIR(a));

				wattron(err,COLOR_PAIR(4));
				for(int i=0;i<getmaxy(err);i++)
                                	for(int j=0;j<getmaxx(err);j++)
						mvwprintw(err,i,j," ");
				refresh();
				box(err,0,0);
				mvwprintw(err,getmaxy(err)/2,(getmaxx(err)-strlen("archive file not found!"))/2,"Archive File Not Found!");

				wattroff(err,COLOR_PAIR(4));
				wrefresh(err);

				getch();
				goto start;
			}

			char c=0;
			int ln=0;
			int col=0;
loop:
			clear();

                        attron(COLOR_PAIR(a));

                        for(int i=0;i<getmaxy(stdscr);i++)
                                for(int j=0;j<getmaxx(stdscr);j++)
                                        mvprintw(i,j," ");

			move(0,0);


			while(!feof(fp))
			{
				c=fgetc(fp);
				col++;

				if(c == 10)
				{
					ln++;
					col=-1;
				}
				if(c == 9)
				{
					ln=ln;
					col=col+4;
				}
				if(ln == getmaxy(stdscr)-1)
				{
					ln=0;
					keypad(stdscr,true);
					noecho();
					int d=getch();


					/*while(1){
						d=getch();
						if(d == KEY_UP){
							c=0;
							fseek(fp,0L,SEEK_SET);
							goto loop;
						}else if(d == KEY_DOWN){
							goto loop;
						}else if(d == 'q')
							break;
					}*/
					goto loop;

					echo();
				}else{
					mvprintw(ln,col,"%c",c);
				}
			}

			attroff(COLOR_PAIR(a));
			getch();
			goto start;
		}
	}
	noecho();

	wattroff(search,COLOR_PAIR(a));

	endwin();

	return 0;
}
