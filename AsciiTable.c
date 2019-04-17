#include<stdio.h>
#include<ncurses.h>

int x,y,c;

int main(void){
    initscr();
    cbreak();

    getmaxyx(stdscr,y,x);

    WINDOW *ea=newwin(y-y/2,x/2,0,85);

    start_color();
    init_pair(1,COLOR_WHITE,COLOR_RED);
    init_pair(2,COLOR_WHITE,COLOR_BLUE);

 

    keypad(ea,true);

    attron(COLOR_PAIR(1));
    printw("ASCII TABLE");
    attroff(COLOR_PAIR(1));
    
    printw("\n\n0 - \n");
    for(int i=1;i<=31; i++){
        printw("%d - %c\n",i,(char)i);
        if(i == 13){
            printw("%d - \n",i);
        }
    }
    for(int i=32;i<=63; i++){
        mvprintw(i-29,10+5,"%d - %c\n",i,(char)i);
    }
    for(int i=64;i<=95; i++){
        mvprintw(i-61,19+10,"%d - %c\n",i,(char)i);
    }
    for(int i=96;i<=127; i++){
        mvprintw(i-93,28+15,"%d - %c\n",i,(char)i);
    }
    refresh();
    c=wgetch(ea);
    if(c==KEY_F(10)){
        wattron(ea,COLOR_PAIR(2));
        for(int i=0;i<getmaxy(ea);i++){
            for(int j=0;j<getmaxx(ea);j++){
                mvwprintw(ea,i,j," ");
            }
        }
        
        for(int i=128;i<=143;i++){
            mvwprintw(ea,i-126,2,"%d - %c",i,(unsigned char)i);
        }
        for(int i=144;i<159;i++){
            mvwprintw(ea,i-141,12,"%d - %c",i,(unsigned char)i);
        }
        for(int i=159;i<=173;i++){
            mvwprintw(ea,i-156,22,"%d - %c",i,(unsigned char)i);
        }
        for(int i=174;i<=188;i++){
            mvwprintw(ea,i-171,32,"%d - %c",i,(unsigned char)i);
        }
        for(int i=189;i<=203;i++){
            mvwprintw(ea,i-186,42,"%d - %c",i,(unsigned char)i);
        }
        for(int i=204;i<=218;i++){
            mvwprintw(ea,i-201,42,"%d - %c",i,(unsigned char)i);
        }
        for(int i=219;i<=233;i++){
            mvwprintw(ea,i-216,52,"%d - %c",i,(unsigned char)i);
        }
        for(int i=234;i<=248;i++){
            mvwprintw(ea,i-231,62,"%d - %c",i,(unsigned char)i);
        }
        for(int i=249;i<=255;i++){
            mvwprintw(ea,i-246,72,"%d - %c",i,(unsigned char)i);
        }


        box(ea,0,0);
        

        mvwprintw(ea,1,1,"EXTENDED ASCII-TABLE");
        mvwprintw(ea,getmaxy(ea)-3,1,"LATIN-US \"DOS\"");
        wattroff(ea,COLOR_PAIR(2));
        wrefresh(ea);
    }else{
        c=wgetch(ea);
    }
    getch();
    endwin();
    return 0;
}
