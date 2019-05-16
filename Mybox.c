#include<stdio.h>
#include<ncurses.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{

        initscr();
        noecho();
        cbreak();
//      nodelay();

        short a,b, c;
        int i=0;
        char s[2048]=" ";

        a=82;
        b=140;
        c=255;

        start_color();
        init_pair(1,COLOR_WHITE,COLOR_BLUE);
        WINDOW *hw=newwin(getmaxy(stdscr)/4,getmaxx(stdscr)/4,0,0);

        system("bin/cimg .myBox/info/.info");

        refresh();
        wattron(hw,COLOR_PAIR(1));
        box(hw,0,0);
        wattroff(hw,COLOR_PAIR(1));
        wrefresh(hw);


        wattron(hw,COLOR_PAIR(1));
        for(int a=1;a<getmaxy(hw)-1; a++)
        {
                for(int b=1;b<getmaxx(hw)-1;b++)
                        mvwprintw(hw,a,b," ");
        }

        mvwprintw(hw,0,(getmaxx(hw)-strlen("  MyBox v1.0 "))/2,"%cMyBox v1.0%c",(unsigned char)185,(unsigned char)204);
        mvwprintw(hw,2,1,"Type help for help");
        wrefresh(hw);
        wattroff(hw, COLOR_PAIR(1));
        echo();                                                                                                 

        i=20;
        while(1){
                mvprintw(0+i,0,"Cprog://> ");
                scanw("%s",s);
                if(strcmp(s,"help")==false)
                {
                        printw("HELP - ....... you just called this one\nexit - ...It's quite obvious\n---%cNo Other Commands Yet%c---",(unsigned char)185,(unsigned char)2$
                        i=i+3;

                }
                if(strcmp(s,"exit")==false)
                {
                        break;
                }else{
                        printw("Syntax Error:\"%s\"",s);
                        i=i+2;
                }

                if(strcmp(s,"clear")==false)
                {
                        i=0;
                        clear();
                }
        }


        noecho();
//      getch();
        endwin();
        return 0;
}
