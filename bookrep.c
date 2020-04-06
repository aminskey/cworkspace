#include<stdio.h>
#include<ncurses.h>
#include<string.h>

void draw(void);
void paint(WINDOW *,int, char);
void outline(WINDOW *,int, char *);
void wmake(WINDOW *, int, int, char, char *);
char newbie(void);

int main(int argc, char const *argv[])
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);

    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    init_pair(2,COLOR_WHITE,COLOR_RED);
    init_pair(3,COLOR_WHITE,COLOR_BLACK);


    int d=0;

    char bkrp[getmaxy(stdscr)][getmaxx(stdscr)];

    echo();
    curs_set(1);

    draw();

    mvprintw(39,0,":");

    int y,x,in;

    MEVENT evnt;
    mousemask(ALL_MOUSE_EVENTS,NULL);

    keypad(stdscr,true);

    while((d=getch())){
      if(d==KEY_MOUSE){
	      if(getmouse(&evnt)==OK){
	        move(y=evnt.y,x=evnt.x);
	      }
      }

      if(d==KEY_F(1)){
        break;
      }
      if(d==KEY_F(2)){
        break;
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
      draw();
      move(y,x);
    }
    curs_set(0);
    for(int i=0; i<getmaxy(stdscr);i++){
      for(int j=0;j<getmaxx(stdscr);j++){
        bkrp[i][j]=mvinch(i,j);
      }
    }

    if(d==KEY_F(1)){
      endwin();
      return 0;
    }
    if(d==KEY_F(2)){
      newbie();
      attron(COLOR_PAIR(2));
      for(int i=0;i<getmaxy(stdscr);i++){
        for(int j=0;j<getmaxx(stdscr);j++){
          mvaddch(i,j,bkrp[i][j]);
        }
      }
      draw();
      attroff(COLOR_PAIR(2));
      getch();
    }


    endwin();
    return 0;
}
void draw(){
    move(0,0);
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
}
void paint(WINDOW *win, int pair, char ch){
  wattron(win,COLOR_PAIR(pair));
  for(int i=0;i<getmaxy(win);i++){
    for(int j=0;j<getmaxx(win);j++){
      mvwprintw(win,i,j,"%c",ch);
    }
  }
  wattroff(win,COLOR_PAIR(pair));
  wrefresh(win);
}
void outline(WINDOW *win, int pair, char *s){
  refresh();

  wattron(win,COLOR_PAIR(pair));
  box(win,0,0);
  mvwprintw(win,0,(getmaxx(win)-strlen(s))/2,"%s",s);
  wattroff(win,COLOR_PAIR(pair));

  wrefresh(win);
}
void wmake(WINDOW *win, int p1, int p2, char ch, char *s){

  paint(win,p1,ch);
  outline(win,p2,s);

}
void newbie(void){
    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    init_pair(2,COLOR_WHITE,COLOR_RED);
    init_pair(3,COLOR_WHITE,COLOR_BLACK);
    init_pair(4,COLOR_BLACK,COLOR_MAGENTA);

    int c=0,x=0,y=0,len;

    WINDOW *nf=newwin(11,60,getmaxy(stdscr)/2-getmaxy(stdscr)/4,getmaxx(stdscr)/2-getmaxx(stdscr)/4);
    WINDOW *sub=derwin(nf,getmaxy(nf)-1,getmaxx(nf)-1,1,1);
    WINDOW *shdw=newwin(getmaxy(nf),getmaxx(nf),getbegy(nf)+1,getbegx(nf)+2);


    paint(stdscr,1,32);
    paint(shdw,3,32);
    wmake(nf,2,2,32,"\xb9 New Bookreport \xcc");

    char attr[getmaxy(sub)][getmaxx(sub)];




    curs_set(1);
    keypad(stdscr, false);
    keypad(sub, true);

    while(1){
      wmove(sub,0,0);
      wattron(sub,COLOR_PAIR(2));

      mvwprintw(sub,1,1,"E-mail address:");
      for(int i=1+strlen("e-mail address:");i<getmaxx(sub)-5;i++)
        mvwaddch(sub,2,i,ACS_S1);

      mvwprintw(sub,3,1,"Book report name:");
      for(int i=1+strlen("book report name:");i<getmaxx(sub)-5;i++)
        mvwaddch(sub,4,i,ACS_S1);

      mvwprintw(sub,5,1,"Phone number:");
      for(int i=strlen("Phone number:")+1;i<getmaxx(sub)-5;i++)
        mvwaddch(sub,6,i,ACS_S1);

      mvwprintw(sub,7,1,"Library name:");
      for(int i=strlen("Library name:")+1;i<getmaxx(sub)-5;i++)
        mvwaddch(sub,8,i,ACS_S1);

      wmove(sub,y,x);
      c=wgetch(sub);

      MEVENT ms;

      mousemask(ALL_MOUSE_EVENTS,NULL);

      if(c == KEY_UP){
        y--;
      }else if(c == KEY_DOWN){
        y++;
      }else if(c == KEY_LEFT){
        x--;
      }else if(c == KEY_RIGHT){
        x++;
      }else if(c == KEY_MOUSE){
	if(getmouse(&ms) == OK){
	  y=ms.y;
	  x=ms.x;
	}else{
	  endwin();
	  printf("You don\'t have a mouse");
	  exit(0);
	}
      }else if(c == KEY_ENTER || c == 10){
        y++;
      }else if(c == KEY_BACKSPACE){
        x--;
        mvwaddch(sub,y,x,' ');
      }else if(c == KEY_F(1)||c == KEY_F(2)){
        break;
      }else{
        mvwprintw(sub,y,x,"%c",(char)c);
        x++;
      }
      wrefresh(sub);
    }
    if(c==KEY_F(1)){
      return 0;
    }

    int mx=getmaxx(sub);
    int my=getmaxy(sub);
    int t=0;
    
    for(int i=0;i<my;i++){
      for(int j=0;j<mx;j++){
	t=mvwinch(sub,i,j);
	attr[i][j]=t;
      }
    }


    wattroff(sub,COLOR_PAIR(2));
    wrefresh(sub);
    wrefresh(nf);
    clear();

    for(int i=0;i<my-1;i++){
      for(int j=0;j<mx-1;j++){
	mvaddch(i,j,attr[i][j]);	
      }
    }
    mvprintw(1,1,"E-mail address:");
    for(int i=1+strlen("e-mail address:");i<getmaxx(sub)-5;i++)                                                                                                                       
      mvaddch(2,i,ACS_S1);

    mvprintw(3,1,"Book report name:");                                                                                                                                           
    for(int i=1+strlen("book report name:");i<getmaxx(sub)-5;i++)
      mvaddch(4,i,ACS_S1);

    mvprintw(5,1,"Phone number:");
    for(int i=strlen("Phone number:")+1;i<getmaxx(sub)-5;i++)                                                                                                                         
      mvaddch(6,i,ACS_S1);

    mvprintw(7,1,"Library name:");
    for(int i=strlen("Library name:")+1;i<getmaxx(sub)-5;i++)
      mvaddch(8,i,ACS_S1);
    getch();
}
