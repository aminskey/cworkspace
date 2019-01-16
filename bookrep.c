#include<stdio.h>
#include<ncurses.h>

int main(int argc, char const *argv[])
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    
    int d=0;

    printw("BOOK REPORT %c",(unsigned char)178);

    mvprintw(0,55,"%s %s",__DATE__,__TIME__);

    mvprintw(2,16,"Title:");

    for(int i=23;i<53;i++){
        mvprintw(2,i,"_");
    }

    mvprintw(4,16,"Author:");

    for(int i=23;i<53;i++){
        mvprintw(4,i,"_");
    }

    mvprintw(6,16,"THIS BOOK IS ABOUT:");
    for(int i=7;i<20;i++){
        for(int j=16;j<100;j++){
            mvprintw(i,j,"_");
        }
    }


    mvprintw(22,16,"My Favourite part of the book was:");
    for(int i=23;i<28;i++){
        for(int j=16;j<100;j++){
            mvprintw(i,j,"_");
        }
    }

    mvprintw(29,16,"Why I Liked/Disliked This Book:");
    for(int i=30;i<38;i++){
        for(int j=16;j<100;j++){
            mvprintw(i,j,"_");
        }
    }

    refresh();

    echo();
    curs_set(1);

    mvprintw(39,0,":");
    d=getch();
    

    noecho();

    while(d!='q'){
        d=getch();
    }

    endwin();
    return 0;
}
