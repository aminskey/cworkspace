#include<stdio.h>
#include<ncurses.h>


int isMoveOk(int, int);

int ship[4][10]={
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,47,219,219,92,0},
    {0,0,219,254,219,219,254,219},
    {0,0,0,92,219,219,47,0},
};

int in=177;

static int num=0;


int main(int argc, char const *argv[])
{
    int c=0;
    
    unsigned int x,y;

    initscr();
    cbreak();
    noecho();
    curs_set(0);

    for(int i=0;i<15;i++){
        for(int j=0;j<76;j++){
            mvaddch(i,j,(unsigned char)176);
        }
    }
    for(int i=20;i<40;i++){
        for(int j=77;j<130;j++){
            mvaddch(i,j,(unsigned char)176);
        }
    }

    for(int i=0;i<15;i++){
        for(int j=77;j<87;j++){
            mvaddch(i,j,(unsigned char)178);
        }
    }
    for(int i=14;i<18;i++){
        for(int j=21;j<87;j++){
            mvaddch(i,j,(unsigned char)178);
        }
    }
    for(int i=14;i<33;i++){
        for(int j=21;j<30;j++){
            mvaddch(i,j,(unsigned char)178);
        }
    }
    for(int i=33;i<40;i++){
        for(int j=21;j<30;j++){
            mvaddch(i,j,' ');
        }
    }

    WINDOW *wp=newwin(5,11,20,65);
    
    

    refresh();
    
    keypad(wp,true);

    getbegyx(wp,y,x);

redraw:
    
    mvaddch(20,3,'X');

    for(int i=0;i<4;i++){
        
        for(int j = 0; j < 10; j++)
        {
            switch(ship[i][j]){
                case 0:
                    wattron(wp,A_INVIS);
		    wprintw(wp," ");
		    wattroff(wp,A_INVIS);
                    break;
                case 47:
                    wprintw(wp,"%c",47);
                    break;
                case 92:
                    wprintw(wp,"%c",92);
                    break;
                case 219:
                    wprintw(wp,"%c",(unsigned char)219);
                    break;
                case 254:
                    wprintw(wp,"%c",(unsigned char)254);
                    break;
                default:
                    
                    break;
            }
        }
        
        wprintw(wp,"\n");
    }
    c=wgetch(wp);


    while(c){
        mvprintw(0,115,"%dy %dx %dnum",y,x,num);
        refresh();
        
        if(c=='e')
            break;
        
            
                
        
        c=wgetch(wp);
        switch(c){
            case KEY_UP:
                if(y>0 && (isMoveOk(y-1,x)&&isMoveOk(y-1,x+11))==TRUE){
                    y--;
                    
                    mvwin(wp,y,x);
                     
                    break;
                }
                else{
                    break;
                }
            case KEY_DOWN:
                if(y<40 && (isMoveOk(y+6,x)&&isMoveOk(y+6,x+11))==TRUE){
                    y++;
                    mvwin(wp,y,x);
                     
                    break;
                }else{
                    break;
                }
                
            case KEY_LEFT:
                if(x>0 && (isMoveOk(y,x-3)&&isMoveOk(y+5,x-2))==TRUE){
                    x=x-2;
                    mvwin(wp,y,x);

                    break;
                }else {
                    break; 
                }
            case KEY_RIGHT:
                if(x<130 && (isMoveOk(y,x+12) && isMoveOk(y+5,x+12))==TRUE){
                    x=x+2; 
                    mvwin(wp,y,x);
                    break;
                }else{
                    break;
                }
            default:
                break;
        }
        if((y<25 && y>15)&&( x<=3 && x>=1)){
            num++;
            clear();
            for(int i=0;i<15;i++){
                for(int j=0;j<130;j++){
                    mvaddch(i,j,(unsigned char)176);
                }
            }
            for(int i=15;i<40;i++){
                for(int j=0;j<30;j++){
                    if((j>0 && j<28)&& i>15 && i<39)
                        mvaddch(i,j,' ');
                    else{
                        mvaddch(i,j,(unsigned char)178);
                        if((i % 1 == 0) && j >= 28){
                            mvaddch(i,j,(unsigned char)177);
                        }
                    }
                    
                }  
            }
            
            wclear(wp);
            y=20;
            x=65;
            goto redraw;
            continue;
        
        }else if(num==2){
            clear();
            num++;
            for(int i=0;i<30;i++){
                for(int j=55;j<65;j++){
                    mvaddch(i,j,(unsigned char)176);
                }
            }
            for(int i=0;i<55;i++){
                mvaddch(30,i,(unsigned char)254);
            }
            for(int k=22;k<40;k++){
                for(int l=0;l<10;l++)
                    mvaddch(k,l,(unsigned char)178);
            }
            for(int k=22;k>5;k--){
                for(int l=7;l<10;l++)
                    mvaddch(k,l,'k');
            }


            
            wclear(wp);
            y=20;
            x=65;
            goto redraw;
            continue;
            getch();
            break;
        }
        


    }
    
    wrefresh(wp);

    
    endwin();
    return 0;
}
int isMoveOk(int y, int x){
    int testch=mvinch(y,x);
    return ((testch==' ')||(testch==(unsigned char)177)||(testch=='X')||(testch=='k')||(testch==(unsigned char)254));
}
