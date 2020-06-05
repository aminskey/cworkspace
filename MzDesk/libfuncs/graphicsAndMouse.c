#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

void wpaint(WINDOW *win, char ch, short clr){
        wattron(win,COLOR_PAIR(clr));

        for(int i=0;i<getmaxy(win);i++)
                for(int j=0;j<getmaxx(win);j++)
                        mvwprintw(win,i,j,"%c",ch);

        wattroff(win, COLOR_PAIR(clr));
}

int chprint(WINDOW *win, char *fname){
	FILE *fp=fopen(fname,"r+");
	wmove(win,0,0);
	if(fp==NULL)
		return -1;
	while(!feof(fp)){
		wprintw(win,"%c",fgetc(fp));
	}
	fclose(fp);

	return 0;
}

int touch(int y, int x, int y1, int x1, MEVENT evnt){
        return ((evnt.y > y && evnt.y < y1) && (evnt.x > x && evnt. x < x1));
}
// int mtouchwin(WINDOW *win, MEVENT evnt){
//         return touch(getbegy(win),getbegx(win),getmaxy(win),getmaxx(win),evnt);
// }

