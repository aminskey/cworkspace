#include<stdio.h>
#include<ncurses.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>

extern void wpaint();
extern int more();
extern void Mzpause();
extern int dir();

extern const char home[];

int mdir(WINDOW *, char *, int, int);

void apphelp(WINDOW *src){
	char str[200];
	char input[50]=" ";
	char page[50]=" ";
	char site[50];

	int ln=0;

	int ch, col;
	short fg, bg;

	ch=col=0;
	fg=bg=0;

	sprintf(str,"%s/.Mzdos/dat",home);
	sprintf(site,"%s/.Mzdos/apphelp",home);

	cbreak();
	curs_set(1);
	echo();

	WINDOW *sub=derwin(src,getmaxy(src)-2,getmaxx(src)-5,1,1);
	WINDOW *srch=derwin(src,3,getmaxx(sub),getmaxy(sub)+1,0);
	FILE *fp=fopen(str,"r+");

	fscanf(fp,"%d %d %hd %hd",&ch, &col, &fg, &bg);
	fclose(fp);

	start_color();
	init_pair(col,fg,bg);
	init_pair(1,COLOR_WHITE,COLOR_BLACK);


	wpaint(src,32,1);

	wattron(src,COLOR_PAIR(col));

	refresh();
	box(src,0,0);
	mvwprintw(src,0,(getmaxx(src)-strlen("App Reference"))/2,"App Reference");

	wattroff(src,COLOR_PAIR(col));
	wrefresh(src);

	wattron(srch,COLOR_PAIR(1));

	refresh();
	box(srch,0,0);
	mvwprintw(srch,0,(getmaxx(srch)-strlen("Search"))/2,"Search");

	wattroff(srch,COLOR_PAIR(1));
	wrefresh(srch);

	refresh();

	while(1){

	  /*	  wattron(srch,COLOR_PAIR(1));

	  refresh();
	  box(srch,0,0);
	  mvwprintw(srch,0,(getmaxx(srch)-strlen("Search"))/2,"Search");

	  wattroff(srch,COLOR_PAIR(1));
	  */

	  ln=mdir(sub,site,ln,10);
	  if(ln<=-1){
	    wprintw(sub,"Something Went Wrong!! Fatal State!! %d",ln);
	    break;
	  }else{
	    wmove(sub,ln,0);
	  }


 	  wprintw(sub,"Ok Ready\n");
	  wscanw(sub,"%s",input);


	  ln++;

	  if(!strcmp(input,"exit")||!strcmp(input,"EXIT")){
	    wprintw(sub,"Ending Search");
	    for(int i=0;i<=3;i++){
	      wprintw(sub,".");
	      delay_output(500);
	      wrefresh(sub);
	    }

	    break;
	  }


	  sprintf(page,"%s/.Mzdos/apphelp/%s",home,input);

	  wclear(sub);


	  ln=more(sub,page,ln);
	  if(ln==-1){
	    wprintw(sub,"\"%s\" Cannot Be Opened: %d\n",page, ln);
	    usleep(500);
	    wclear(sub);
	  }
	  else{
	    wclear(sub);
	  }

	  sprintf(page," ");
	  sprintf(input," ");
	}
       
	wpaint(src,ch,col);
	wrefresh(src);

	delwin(sub);
	delwin(srch);
}
int mdir(WINDOW *src, char *str, int ln, int indent){
  DIR *dp;
  struct dirent *dir;

  if((dp=opendir(str))==NULL){
    return -1;
  }
  while((dir=readdir(dp))!=NULL){
    ln++;
    mvwprintw(src,0,0,"%s",dir->d_name);
    mvwprintw(src,ln,indent,"%s",dir->d_name);

  }
  return ln;
}
