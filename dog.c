#include<stdio.h>
#include<unistd.h>
#include<ncurses.h>

int main(int argc, char *argv[]){
    

    initscr();
    noecho();
    cbreak();        

    int d=0;

    int ln=0;

     char file;

     FILE *fp=fopen(argv[1],"r");

    WINDOW *win=newwin(9,70,10,50);

    if(fp==NULL){
        refresh();
        box(win,0,0);
        curs_set(0);

        wattron(win,A_REVERSE);

        mvwprintw(win,1,1,"\"%s\"::FILE NOT FOUND",argv[1]);

        wattroff(win,A_REVERSE);
        wrefresh(win);
    }else{
        while(!feof(fp))
        {
            ln++;
            file=fgetc(fp);
            printw("%c",file);
            if(ln % 699==0){
                getch();
                clear();
            }
        }
        printw("\b");

        curs_set(0);

        refresh();
        box(win,0,0);
        
        
        wattron(win,A_REVERSE);
        mvwprintw(win,2,15,"FILE :: %s",argv[1]);
        wattroff(win,A_REVERSE);
        
        wrefresh(win);
        
        
        
        
    }
    fclose(fp);
    getch();
    endwin();
    return 0;
}