#include<stdio.h>
#include<ncurses.h>

int main(int argc, char const *argv[])
{

    char buff;
    int ln=0;

    initscr();
    noecho();
    cbreak();


    FILE *fp=fopen(argv[1],"r");
    if(fp==NULL){
        curs_set(0);
        attron(A_REVERSE);
        mvprintw(10,50,"FILE NOT FOUND");
        attroff(A_REVERSE);
        
    }
    else{
        while(!feof(fp)){
            buff=fgetc(fp);
            printw("%c",buff);
            getch();
            ln++;
            if(ln % 800 == 0){
                clear();
                refresh();
            }
        }
    }
    
    getch();
    endwin();
    return 0;
}
