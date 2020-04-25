#include<stdio.h>
#include<stdlib.h>
#include<curl/curl.h>
#include<ncurses.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[]){
    
  char top[50];
  
  CURL *curl=curl_easy_init();
  CURLcode res;

  if(argc <= 0){
    perror("[[Protocol://]website] [output file]");
    exit(0);
  }

  FILE *fp=fopen(argv[2],"r+");

  initscr();
  cbreak();
  noecho();

  start_color();
  init_pair(1,COLOR_WHITE, COLOR_BLUE);
  init_pair(2,COLOR_WHITE, COLOR_RED);

  WINDOW *state=newwin(7,60,getmaxy(stdscr)/2-getmaxy(stdscr)/4,getmaxx(stdscr)/2-getmaxx(stdscr)/4);
  WINDOW *sub=derwin(state,getmaxy(state)-2,getmaxx(state)-2,1,1);
  WINDOW *shdw=newwin(getmaxy(state),getmaxx(state),getbegy(state)+2,getbegx(state)+2);

  attron(COLOR_PAIR(1));
  
  for(int i=0;i<getmaxy(stdscr);i++)
    for(int j=0;j<getmaxx(stdscr);j++)
      mvprintw(i,j," ");
  attroff(COLOR_PAIR(1));
  refresh();
  
  for(int i=0;i<getmaxy(shdw);i++)
    for(int j=0;j<getmaxx(shdw);j++)
      mvwprintw(shdw,i,j," ");
  wrefresh(shdw);
  

  wattron(state,COLOR_PAIR(2));
  for(int i=0;i<getmaxy(state);i++)
    for(int j=0;j<getmaxx(state);j++)
      mvwprintw(state,i,j," ");

  box(state,0,0);

  sprintf(top,"\xb9 %s - %s \xcc",argv[1], argv[2]);
  
  mvwprintw(state,0,(getmaxx(state)-strlen(top))/2,"%s",top);
  
  wrefresh(state);

  
  if(curl){
    curl_easy_setopt(curl,CURLOPT_URL,argv[1]);
    curl_easy_setopt(curl,CURLOPT_WRITEDATA,(void *)fp);

    res=curl_easy_perform(curl);
    for(int i=0;i<3;i++){
      if(res==CURLE_OK){
	mvwprintw(state,getmaxy(state)/2,(getmaxx(state)-strlen("Request Accepted"))/2,"Request Accepted");
	break;
      }else{
	mvwprintw(state,getmaxy(state)/2,(getmaxx(state)-strlen("Request Denied"))/2,"Request Denied");
	break;
      }
      printw(".");
    }
    curl_easy_cleanup(curl);
  }
  wattroff(state,COLOR_PAIR(2));

  wrefresh(shdw);
  wrefresh(state);

  fclose(fp);
  getch();
  clear();

  attron(COLOR_PAIR(1));

  FILE *frp=fopen(argv[2],"r+");

  for(int i=0;i<getmaxy(stdscr);i++)
     for(int j=0;j<getmaxx(stdscr);j++)
	mvprintw(i,j," ");

  int ln=0;
  char buff=0;
  move(0,0);

  while(!feof(frp)){
     buff=fgetc(frp);
     if(buff == '\n')
	ln++;
     printw("%c",buff);

     if(ln >= getmaxy(stdscr)-2)
     {
        for(int i=0;i<getmaxy(stdscr);i++){
          for(int j=0;j<getmaxx(stdscr);j++){
            mvprintw(i,j,"%c",(char)mvinch(i,j));
          }
        }

	getch();
	clear();
	move(0,0);
	ln=0;
     }
     refresh();

  }
  for(int i=0;i<getmaxy(stdscr);i++){
     for(int j=0;j<getmaxx(stdscr);j++){
        mvprintw(i,j,"%c",(char)mvinch(i,j));
     }
  }
  getch();
  clear();
  for(int i=0;i<getmaxy(stdscr);i++){
     for(int j=0;j<getmaxx(stdscr);j++){
        mvprintw(i,j,"%c",(char)mvinch(i,j));
     }
  }



  mvprintw(getmaxy(stdscr)/2,(getmaxx(stdscr)-strlen("END OF FILE: -1"))/2,"END OF FILE: -1");

  attroff(COLOR_PAIR(1));
  getch();

  fclose(frp);
  endwin();
  return 0;
}
