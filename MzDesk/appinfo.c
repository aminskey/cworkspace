#include<ncurses.h>

extern void wpaint();
extern int more();
extern void Mzpause();

extern char home[];

void appinfo(WINDOW *src){
	int ln=0;
	char str[100];

	int col=0;
	int ch=0;
	short fs,ss;

	sprintf(str,"%s/.Mzdos/dat",home);

	FILE *fp=fopen(str,"r+");

	fscanf(fp,"%d %d %hd %hd",&ch,&col,&fs,&ss);

	start_color();
	init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLUE);
	init_pair(col,fs,ss);

	WINDOW *info=derwin(src,getmaxy(src)-2,getmaxx(src)-2,1,1);

	wattron(src,COLOR_PAIR(1));

	box(src,0,0);

	wattroff(src,COLOR_PAIR(1));
	wrefresh(src);

	wmove(info,0,0);

	sprintf(str,"%s/.Mzdos/appinfo.txt",home);



	ln=more(info,str,ln);
	if(ln == -1){
		wprintw(info,"[more] : Ooops Something Went Wrong!!");
	}

	wrefresh(info);

	Mzpause(info);

	wpaint(src, ch, col);
	wrefresh(src);
}
