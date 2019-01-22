#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ncurses.h>

char com[]="lp rcp.txt";

int main(int argc, char *argv[])
{
    FILE *fp=fopen("rcp.txt","w+");
    
    int a=0;
    int b=0;
    int c=0;
    int k=0;

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
    float floss=10.95;
    float choc=floss+0.1;
    double pistat=3.141592;

    
    char in[20];
    char buff[10000];

    
    FILE *dv=fopen("/dev/tty","w");

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
        k=i-4;
        mvprintw(i,0,"   ");
        if(i>=4){
            mvprintw(i,0,"%3d",k);
            k++;
        }
        
        
        
        
    }
    for(int j=0;j<b;j++)
        mvprintw(0,j," ");
    
    mvprintw(39,58,"E - PRINT RECIPT");
    mvprintw(0,1,"C-MDAS");
    attroff(A_STANDOUT);
    
    c=getch();

    
    int l=0;
    char p[11200];


    curs_set(1);
    echo();
    mvprintw(4,15,"ITEM");
    mvprintw(4,30,"COST");
    mvprintw(4,45,"ADDITION");
    while(strcmp(in,"STOP")!=TRUE || ln >=20){
        echo();
        mvscanw(j,15,"%s",in);
        ln=j;
        
        
        if(strcmp(in,"CABBAGE")==false){
            mvprintw(j,30,"%f$",cab);
            mvprintw(j,45,"%f$",cab);
            strcat(buff,in);
            add=cab+add;
            a2=add;
            j++;
        }else if(strcmp(in,"COLA")==false){
            mvprintw(j,30,"%f$",cola);
            mvprintw(j,45,"%f$",cola);
            strcat(buff,in);
            add=cola+add;
           
            a2=add;
            j++;
        }else if(strcmp(in,"CHEETOS")==false){
            mvprintw(j,30,"%f$",chet);
            mvprintw(j,45,"%f$",chet);
            strcat(buff,in);
            add=chet+add;
           
            a2=add;
            j++;
        }
        else if(strcmp(in,"CHIPS")==false){
            mvprintw(j,30,"%f$",chips);
            mvprintw(j,45,"%f$",chips);
            strcat(buff,in);
            add=chips+add;
           
            a2=add;
            j++;
        }else if(strcmp(in,"SCHOOL-SET")==false){
            mvprintw(j,30,"%f$",schset);
            mvprintw(j,45,"%f$",schset);
            strcat(buff,in);
            add=schset+add;
           
            a2=add;
            j++;
        }else if(strcmp(in,"CANDY-FLOSS")==false){
            mvprintw(j,30,"%f$",floss);
            mvprintw(j,45,"%f$",floss);
            strcat(buff,in);
            add=floss+add;
           
            a2=add;
            j++;
        }else if(strcmp(in,"CHOCOLATE")==false){
            mvprintw(j,30,"%f$",choc);
            mvprintw(j,45,"%f$",choc);
            strcat(buff,in);
            add=choc+add;
           
            a2=add;
            j++;
        }else if(strcmp(in,"MINOR-MATHBOOK")==false){
            mvprintw(j,30,"%f$",pistat);
            mvprintw(j,45,"%f$",pistat);
            strcat(buff,in);
            add=pistat+add;
           
            a2=add;
            j++;
        }else{
            break;
        }
        
        

    }   

    

    curs_set(0);
    mvprintw(ln-1,40,"+ ");
    mvprintw(ln,38,"---------------------");
    attron(A_REVERSE);
    mvprintw(ln+1,39,"TOTAL %f$",a2);
    mvprintw(ln+3,39,"ROUNDED - %2.0f$",a2);
    attroff(A_REVERSE);
    
    fprintf(fp,"%s",buff);
    fclose(fp);
    noecho();
    c=getch();
   
    

    if(c=='p'||c=='P'){
        attron(A_REVERSE);
        mvprintw(ln+5,50,"PAID");
        attron(A_REVERSE);
    }else if(c=='e'||c=='E'){
        
        system(com);
    
    }else{
        attron(A_REVERSE);
        mvprintw(ln+5,50,"DISCARDED VALUES");
        attron(A_REVERSE);
    }
    


    

    getch();
    endwin();

    

    return 0;
}