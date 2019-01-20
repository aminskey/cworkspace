#include<stdio.h>
#include<string.h>
#include<ncurses.h>

int main(int argc, char *argv[])
{
    int a=0;
    int b=0;
    int c=0;

    int ln=0;
    int j=5;
    int bound=0;

    float add=0;
    float a2=0;

    float cab=12.95;
    float cola=05.5;
    float chet=34;
    float chips=23.54;
    float schset=80;

    
    char in[20];

    initscr();
    noecho();
    cbreak();

    curs_set(0);

    a=getmaxy(stdscr);
    b=getmaxx(stdscr);

    echo();
    noecho();

    attron(A_STANDOUT);
    for(int i=0;i<a;i++){
        mvprintw(i,0,"%3d",i);
        
        
        
        
    }
    for(int j=0;j<b;j++)
        mvprintw(0,j," ");
    
    mvprintw(0,1,"C-MDAS");
    attroff(A_STANDOUT);
    
    c=getch();



    curs_set(1);
    echo();
    mvprintw(4,15,"ITEM");
    mvprintw(4,30,"COST");
    mvprintw(4,45,"ADDITION");
    while(strcmp(in,"STOP")!=TRUE){
        
        echo();
        mvscanw(j,15,"%s",in);
        
        if(strcmp(in,"CABBAGE")==false){
            mvprintw(j,30,"%f",cab);
            mvprintw(j,45,"%f",cab);
            add=cab+add;
            
            a2=add;
            j++;
        }else if(strcmp(in,"COLA")==false){
            mvprintw(j,30,"%f",cola);
            mvprintw(j,45,"%f",cola);
            add=cola+add;
           
            a2=add;
            j++;
        }else if(strcmp(in,"CHEETOS")==false){
            mvprintw(j,30,"%f",chet);
            mvprintw(j,45,"%f",chet);
            add=chet+add;
           
            a2=add;
            j++;
        }
        else if(strcmp(in,"CHIPS")==false){
            mvprintw(j,30,"%f",chips);
            mvprintw(j,45,"%f",chips);
            add=chips+add;
           
            a2=add;
            j++;
        }else if(strcmp(in,"SCHOOL-SET")==false){
            mvprintw(j,30,"%f",schset);
            mvprintw(j,45,"%f",schset);
            add=schset+add;
           
            a2=add;
            j++;
        }else{
            break;
        }
        ln=j;
        

    }   

 
    mvprintw(ln+1,45,"-----------");
    attron(A_REVERSE);
    mvprintw(ln+2,39,"TOTAL %f",a2);
    attroff(A_REVERSE);

    getch();
    endwin();
    return 0;
}