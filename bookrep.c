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

    mvprintw(0,55,"%s",__DATE__);

    mvprintw(2,16,"Title:");

    for(int i=23;i<53;i++){
	mvaddch(3,i,ACS_S1);
    }
    mvprintw(4,16,"Author:");

    for(int i=23;i<53;i++){
	mvaddch(5,i,ACS_S1);
    }

    mvprintw(6,16,"THIS BOOK IS ABOUT:");
    for(int i=7;i<20;i++){
        for(int j=16;j<100;j++){
	  if(i%2==0){
	    mvaddch(i+1,j,ACS_S1);
	  }
	}
    }


    mvprintw(22,16,"My Favourite part of the book was:");
    for(int i=23;i<28;i++){
        for(int j=16;j<100;j++){
	  if(i%2==0){
	    mvaddch(i+1,j,ACS_S1);
	  }
	}
    }

    mvprintw(29,16,"Why I Liked/Disliked This Book:");
    for(int i=30;i<38;i++){
        for(int j=16;j<100;j++){
	  if(i%2==0){
	    mvaddch(i+1,j,ACS_S1);
	  }
	}
    }

    refresh();

    echo();
    curs_set(1);

    mvprintw(39,0,":");

    int y,x;

    MEVENT evnt;
    mousemask(ALL_MOUSE_EVENTS,NULL);

    keypad(stdscr,true);
    
    while((d=getch())!=KEY_F(1)){
      if(d==KEY_MOUSE){
	if(getmouse(&evnt)==OK){
	  move(y=evnt.y,x=evnt.x);
	}
      }
      if(d==KEY_UP){
	y-=2;
      }
      else if(d==KEY_BACKSPACE){
	x--;
	mvaddch(y,x,' ');
      }
      else if(d==KEY_DOWN){
      	y+=2;
      }
      else if(d==KEY_RIGHT){
  	x++;
      }
      else if(d==KEY_LEFT){
	x--;
      }
      else if(d==KEY_ENTER||d==10){
	move(y+2,x);
	y+=2;
      }else{
	x++;
	mvprintw(39,1,"       ");
	mvprintw(39,1,"%d",d);
      }
      move(y,x);
    }



    endwin();
    return 0;
}
