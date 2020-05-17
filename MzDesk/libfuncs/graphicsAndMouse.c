#include <ncurses.h>

void wpaint(WINDOW *win, char ch, short clr){
        wattron(win,COLOR_PAIR(clr));

        for(int i=0;i<getmaxy(win);i++)
                for(int j=0;j<getmaxx(win);j++)
                        mvwprintw(win,i,j,"%c",ch);

        wattroff(win, COLOR_PAIR(clr));
}

int touch(int y, int x, int y1, int x1, MEVENT evnt){
        return ((evnt.y > y && evnt.y < y1) && (evnt.x > x && evnt. x < x1));
}
// int mtouchwin(WINDOW *win, MEVENT evnt){
//         return touch(getbegy(win),getbegx(win),getmaxy(win),getmaxx(win),evnt);
// }

