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

    float cgum=17.5;
    float cab=12.95;
    float cola=05.5;
    float chet=34;
    float chips=23.54;
    float schset=80;  
    float floss=10.95;
    float choc=floss+0.1;
    float fcushion=27.15;
    float fish=26.0;
    float fishfood=12.95;
    float pistat=3.14;

    
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
    
    mvprintw(39,30,"ANYTHING - DISCARD ALL VALUES");
    mvprintw(39,64,"P - PAID");
    mvprintw(39,77,"E - PRINT RECIPT");
    mvprintw(0,1,"C-MDAS");
    attroff(A_STANDOUT);
    
    c=getch();

    
    int l=0;
    char p[11200];


    curs_set(1);
    echo();
    mvprintw(4,15,"ITEM");
    mvprintw(4,55,"COST");
    mvprintw(4,100,"ADDITION");
    while(strcmp(in,"STOP")!=TRUE || ln >=20){
        echo();
        mvscanw(j,15,"%s",in);
        ln=j;
        
        
        if(strcmp(in,"CABBAGE")==false){
            mvprintw(j,55,"%f$",cab);
            mvprintw(j,100,"%f$",cab);
            strcat(buff,in);
            add=cab+add;
            a2=add;
            j++;
        }else if(strcmp(in,"COLA")==false){
            mvprintw(j,55,"%f$",cola);
            mvprintw(j,100,"%f$",cola);
            strcat(buff,in);
            add=cola+add;
           
            a2=add;
            j++;
        }else if(strcmp(in,"CHEETOS")==false){
            mvprintw(j,55,"%f$",chet);
            mvprintw(j,100,"%f$",chet);
            strcat(buff,in);
            add=chet+add;
           
            a2=add;
            j++;
        }
        else if(strcmp(in,"CHIPS")==false){
            mvprintw(j,55,"%f$",chips);
            mvprintw(j,100,"%f$",chips);
            strcat(buff,in);
            add=chips+add;
           
            a2=add;
            j++;
        }else if(strcmp(in,"SCHOOL-SET")==false){
            mvprintw(j,55,"%f$",schset);
            mvprintw(j,100,"%f$",schset);
            strcat(buff,in);
            add=schset+add;
           
            a2=add;
            j++;
        }else if(strcmp(in,"CANDY-FLOSS")==false){
            mvprintw(j,55,"%f$",floss);
            mvprintw(j,100,"%f$",floss);
            strcat(buff,in);
            add=floss+add;
           
            a2=add;
            j++;
        }else if(strcmp(in,"CHOCOLATE")==false){
            mvprintw(j,55,"%f$",choc);
            mvprintw(j,100,"%f$",choc);
            strcat(buff,in);
            add=choc+add;
           
            a2=add;
            j++;
        }else if(strcmp(in,"MINOR-MATHBOOK")==false){
            mvprintw(j,55,"%f$",pistat);
            mvprintw(j,100,"%f$",pistat);
            strcat(buff,in);
            add=pistat+add;
           
            a2=add;
            j++;
        }else if(strcmp(in,"CHEWING-GUM")==false){
            mvprintw(j,55,"%f$",cgum);
            mvprintw(j,100,"%f$",cgum);
            strcat(buff,in);
            add=cgum+add;
           
            a2=add;
            j++;
        }else if(strcmp(in,"FARTING-CUSHION")==false){
            mvprintw(j,55,"%f$",fcushion);
            mvprintw(j,100,"%f$",fcushion);
            strcat(buff,in);
            add=fcushion+add;
           
            a2=add;
            j++;
        }else if(strcmp(in,"FISH")==false){
            mvprintw(j,55,"%f$",fish);
            mvprintw(j,100,"%f$",fish);
            strcat(buff,in);
            add=fish+add;
           
            a2=add;
            j++;
        }else if(strcmp(in,"FISH-FOOD")==false){
            mvprintw(j,55,"%f$",fishfood);
            mvprintw(j,100,"%f$",fishfood);
            strcat(buff,in);
            add=fishfood+add;
           
            a2=add;
            j++;
        }else{
            break;
        }
        
        

    }   

    

    curs_set(0);
    mvprintw(ln-1,98,"+ ");
    for(int i=97;i<97+21;i++)
        mvprintw(ln,i,"%c",(unsigned char)196);
    attron(A_REVERSE);
    mvprintw(ln+1,100,"TOTAL %f$",a2);
    mvprintw(ln+3,100,"ROUNDED - %2.0f$",a2);
    attroff(A_REVERSE);
    
    fprintf(fp,"%s\n",buff);
    fclose(fp);
    noecho();
    c=getch();
   
    

    if(c=='p'||c=='P'){
        attron(A_REVERSE);
        mvprintw(ln+5,55,"PAID");
        attron(A_REVERSE);
    }else if(c=='e'||c=='E'){
        
        system(com);
    
    }else{
        attron(A_REVERSE);
        mvprintw(ln+5,55,"DISCARDED VALUES");
        attron(A_REVERSE);
    }
    


    

    getch();
    endwin();

    

    return 0;
}