#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<ncurses.h>
#include<time.h>
#include<unistd.h>
#include<dirent.h>

#define MAXY getmaxy(stdscr)
#define MAXX getmaxx(stdscr)

extern const char drva[];
extern const char drvc[];
extern const char drvd[];
extern const char drve[];
extern const char drvz[];
extern const char home[];

char quote[]="YOUR DRIVES ARE DOWN, EDIT THE \'drvConf\' C FILE AND BUILD AGAIN";
char drives[6]="ACDEZ";

int term(WINDOW *, char *username);
int touch(int y, int x, int y1, int x1, MEVENT);
int mtouchwin(WINDOW *,MEVENT);

void drvchck(void);
void bluescreen(char *s);
void wpaint(WINDOW *,char, short);
void paint(char , short);
void mzclock(WINDOW *);

char *login(char *);
char *replace(char *, char, char);

// New file-viewing app in process..
void fileview(WINDOW *,char *);

int ststate=1;


void paint(char ch, short clr){
        wpaint(stdscr,ch,clr);
}

int main(void){

	char str[100];

	initscr();
 	cbreak();
	noecho();
	printw("starting up");

	DIR *dp;
	struct dirent *dir;

 	char desk[100];
	int chd;

	drvchck();

	char username[100];
	login(username);

      	sprintf(desk,"%s/.Mzdos/C/%s/Desktop",home,username);
        sprintf(str,"%s/.Mzdos/A/dat",home);

        FILE *fp=fopen(str,"r+");
        if(fp == NULL){
                bluescreen("Data file doesn\'t exist - Background file");
                exit(0);
        }

        int c=0;
        char in[50];
        char secin[50];

	register int res;
        unsigned int ch=0;
	int col=0;

	short fs=0;
	short ss=0;

        time_t lctime;
        struct tm * loctime;

        time(&lctime);
        loctime=localtime(&lctime);


        curs_set(0);

        srand(time(0));


        WINDOW *menu=newwin(3,MAXX,MAXY-3,0);

	WINDOW *note=newwin(MAXY/2, MAXX/2, MAXY/2 - MAXY/4, MAXX/2 - MAXX/4);
	WINDOW *info=newwin(MAXY/2,MAXX,0,0);
	WINDOW *trm=newwin(MAXY/2,MAXX/2,rand()%MAXY/2,rand()%MAXX/2);
        WINDOW *clck=newwin(3,20,rand()%MAXY/2,rand()%MAXX/2);
        WINDOW *app=newwin(MAXY/2,MAXX,0,0);

	WINDOW *ico=newwin(6,7,2,2);


        WINDOW *mb2=newwin(24,24,(MAXY-getmaxy(menu)-24),0);
        WINDOW *optm=derwin(mb2,3,getmaxx(mb2)-2,1,1);
        WINDOW *opoff=derwin(mb2,3,getmaxx(mb2)-2,1+getmaxy(optm),1);
        WINDOW *oprs=derwin(mb2,3,getmaxx(mb2)-2,1+getmaxy(optm)*2,1);
	WINDOW *opcl=derwin(mb2,3,getmaxx(oprs),1+getmaxy(oprs)*3,1);
	WINDOW *opout=derwin(mb2,3,getmaxx(oprs),1+getmaxy(oprs)*4,1);
        WINDOW *srch=derwin(mb2,3,getmaxx(mb2)-2,getmaxy(mb2)-4,1);

        MEVENT evnt;

        mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);


	drvchck();

        fscanf(fp,"%d %d %hd %hd",&ch,&col,&fs,&ss);
        fclose(fp);

        const chtype drvico[7][7]={
	        {ch,ch,ch,ch,ch,ch,ch},
	        {ch,ch,'D','R','V',ch,ch},
	        {ch,ACS_ULCORNER,ACS_HLINE,ACS_HLINE,ACS_HLINE,ACS_URCORNER,ch},
	        {ch,ACS_VLINE,ACS_HLINE,ACS_HLINE,ACS_HLINE,ACS_VLINE,ch},
	        {ch,ACS_LLCORNER,ACS_HLINE,ACS_HLINE,ACS_HLINE,ACS_LRCORNER,ch},
	        {ch,ch,ch,ch,ch,ch,ch},
	        {ch,ch,ch,ch,ch,ch,ch}
	};

        const chtype flico[7][7]={
                {'F','I','L','E','N','M','E'},
                {ch,ACS_URCORNER,ACS_HLINE,ACS_HLINE,ACS_HLINE,ACS_URCORNER,ch},
                {ch,ACS_VLINE,'~','~','~',ACS_VLINE,ch},
                {ch,ACS_LLCORNER,ACS_HLINE,ACS_HLINE,ACS_HLINE,ACS_LRCORNER,ch},
                {ch,ch,ch,ch,ch,ch,ch},
                {ch,ch,ch,ch,ch,ch,ch},
		{ch,ch,ch,ch,ch,ch,ch}
        };

        start_color();
        init_pair(1,COLOR_WHITE, COLOR_CYAN);
        init_pair(2,COLOR_WHITE, COLOR_BLUE);
        init_pair(3,COLOR_WHITE, COLOR_BLACK);
        init_pair(4,COLOR_BLUE, COLOR_WHITE);
	init_pair(5,COLOR_WHITE, COLOR_RED);
	init_pair(6,COLOR_BLACK, COLOR_WHITE);
	init_pair(col,fs,ss);

	int fx, fy;
	getbegyx(ico,fy,fx);
	fy*=5;


	paint(ch,col);

        refresh();
        wpaint(menu,32,4);
        wrefresh(menu);

        wattron(menu,COLOR_PAIR(4));
        mvwprintw(menu,1,1,"start");
        mvwprintw(menu,1,10,"%d:%d",loctime->tm_hour, loctime->tm_min);
        wattroff(menu,COLOR_PAIR(4));

        wrefresh(menu);

        keypad(stdscr, true);

        while(1){
		refresh();

		drvchck();

        	curs_set(0);
		paint(ch,col);

		mvwin(ico,1,2);
		wattron(ico,COLOR_PAIR(col));
		attron(COLOR_PAIR(col));
                for(register int i=0;i<5;i++){
                        box(ico,ch,ch);

                        wrefresh(ico);
			refresh();

			for(register int y=0;y<7;y++){
				for(register int x=0;x<7;x++){
					mvwaddch(ico,y,x,drvico[y][x]);
				}
			}
                        wrefresh(ico);

			mvprintw(getmaxy(ico),getbegx(ico)+2,"%c:",drives[i]);
			refresh();

			mvwin(ico,1,(getmaxx(ico)*2)+getbegx(ico));


		}
		wattron(ico,A_REVERSE);
		getbegyx(ico,fy,fx);
		
		dp=opendir(desk);
		while((dir=readdir(dp))!=NULL){
			if(strncmp(dir->d_name,".",1)){
				if(fx>=getmaxx(stdscr)-1){
					fy+=getmaxy(ico);
				}
				for(int i=0;i<7;i++){
					for(int j=0;j<7;j++){
						mvwaddch(ico,i,j,flico[i][j]);
					}
				}

				wrefresh(ico);
				mvprintw(getmaxy(ico)+fy,fx+(getmaxx(ico)-strlen("C D R V"))/2,"C D R V");
				mvprintw((getmaxy(ico)+fy)-1,fx+(getmaxx(ico)-strlen(dir->d_name))/2,"%s",dir->d_name);
				refresh();

				mvwin(ico,fy,fx+=getmaxx(ico)*2);

			}
		}
		closedir(dp);

                wattroff(ico,A_REVERSE);
                attroff(COLOR_PAIR(col));
		wattroff(ico,COLOR_PAIR(col));

                if(res==0){
                        wclear(trm);
                        wpaint(trm,ch,col);
                        wrefresh(trm);
                }
                if(res==1){
                        wclear(trm);
                        wpaint(trm,32,3);

                        box(trm,0,0);
                        wrefresh(trm);
                }



	        refresh();
	        wpaint(menu,32,4);
	        wrefresh(menu);

	        wattron(menu,COLOR_PAIR(4));
	        mvwprintw(menu,1,1,"start");
	        mvwprintw(menu,1,10,"%d:%d",loctime->tm_hour, loctime->tm_min);
	        wattroff(menu,COLOR_PAIR(4));

	        wrefresh(menu);

		drvchck();

		sprintf(quote,"YOUR SYSTEM IS DOWN");

                c=getch();
                if(c==KEY_MOUSE){
                        if(getmouse(&evnt) == OK){
                                if(evnt.bstate >= BUTTON1_PRESSED){
                                        if(touch(MAXY - getmaxy(menu),0,MAXY,strlen("start")+1,evnt)){
				  	        mvwprintw(menu,1,1,"start");
                                                ststate=0;
                                                wrefresh(menu);
                                        }
		                }
				if((evnt.bstate >= BUTTON1_PRESSED) && res == 1){
					if(mtouchwin(trm,evnt)){
						res=term(trm,username);
					}
				}
                        }else{
                                bluescreen("DESKTOP HAS CRASHED, BECAUSE THERE IS NO MOUSE OR THAT THE MOUSE IS UNAVAILABLE");
				endwin();
				exit(0);
                        }
                }
                if(ststate == 0){
                        usleep(250);

                        refresh();
/* ###################################################################################
                C R E A T I N G   M E N U
  ###################################################################################
*/


                        wpaint(mb2,32,4);
                        wattron(mb2,COLOR_PAIR(4));

                        box(mb2,0,0);

                        wattroff(mb2,COLOR_PAIR(4));
                        wrefresh(mb2);


/* ####################################################################################
                        C R E A T I N G  A P P S
  ####################################################################################
*/
                        wpaint(optm,32,4);
                        wattron(optm,COLOR_PAIR(4));

                        box(optm,0,0);
                        mvwprintw(optm,1,1,"AcornDOS Prompt");


                        wattroff(optm,COLOR_PAIR(4));
                        wrefresh(optm);

			wpaint(opcl,32,4);
			wattron(opcl,COLOR_PAIR(4));

			box(opcl,0,0);
			mvwprintw(opcl,1,1,"Clock");

			wattroff(opcl,COLOR_PAIR(4));
			wrefresh(opcl);

                        wpaint(opoff,32,4);
                        wattron(opoff,COLOR_PAIR(4));

                        box(opoff,0,0);
                        mvwprintw(opoff,1,1,"Off Button");

                        wattroff(opoff,COLOR_PAIR(4));
                        wrefresh(opoff);

                        wpaint(oprs,32,4);
                        wattron(oprs,COLOR_PAIR(4));

                        box(oprs,0,0);
                        mvwprintw(oprs,1,1,"Reset Computer");

                        wattroff(oprs,COLOR_PAIR(4));
                        wrefresh(oprs);

			wpaint(opout,32,4);
			wattron(opout, COLOR_PAIR(4));

			box(opout,0,0);
			mvwprintw(opout,1,1,"Log Out");

			wattroff(opout, COLOR_PAIR(4));
			wrefresh(opout);

                        ststate=2;
                }
                if(ststate==2){
                        echo();

                        wpaint(srch,32,4);
                        wattron(srch,COLOR_PAIR(4));

                        box(srch,0,0);
                        mvwprintw(srch,0,(getmaxx(srch)-strlen("Search"))/2,"Search");
                        mvwscanw(srch,1,1,"%s %s",in,secin);

                        wattroff(srch,COLOR_PAIR(4));
                        wrefresh(srch);

                        ststate=1;
			noecho();
                }
                if(ststate==1){
                        wpaint(mb2,ch,col);
			wrefresh(mb2);

                        wattron(menu,COLOR_PAIR(4));
                        mvwprintw(menu,1,1,"start");
                        wattron(menu,COLOR_PAIR(4));

                        wrefresh(menu);

                }
                if(!strcmp(in,"AcornDOS")||!strcmp(in,"Acorn")){
                        if(!strcmp(secin,"Prompt"))
                        {
                                res=term(trm,username);
				if(res!=1){
					wclear(trm);
					wpaint(trm,ch,col);
				}
				wrefresh(trm);
                        }
                }
                if(!strcmp(in,"Off")){
                        if(!strcmp(secin,"Button")){
                                clear();
                                mvprintw(0,0,"Turning Off");
                                usleep(1500);
                                endwin();
                                return 0;
                        }
                }
		if(!strcmp(in,"Quit")||(!strcmp(in,"Log") && !strcmp(secin,"Out"))){
			login(username);
			main();
			return 0;
		}
                if(!strcmp(in,"Reset")){
                        if(!strcmp(secin,"Computer")){
                                main();
                                return 0;
                        }
		}if(!strcmp(in,"Clock")){
			mzclock(clck);
		}
                if(c==KEY_F(9))
                        break;
                if(c==KEY_F(12)){
                        main();
                        return 0;
                }
 		sprintf(in," ");
		sprintf(secin," ");
	}
        endwin();
        return 0;

}

void wpaint(WINDOW *win, char ch, short clr){
        wattron(win,COLOR_PAIR(clr));

        for(int i=0;i<getmaxy(win);i++)
                for(int j=0;j<getmaxx(win);j++)
                        mvwprintw(win,i,j,"%c",ch);

        wattroff(win, COLOR_PAIR(clr));
}

void bluescreen(char *s){
	int t=0;

        curs_set(0);

        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLUE);
        paint(32,1);

        mvprintw(MAXY/6,(MAXX-strlen(s))/2,"%s",s);

        for(int i=0;i<strlen(drives);i++){
                mvprintw(20+(i+1),40,"DRIVE %c:",drives[i]);
        }
        mvprintw(21,50,"%s",drva);
        mvprintw(22,50,"%s",drvc);
        mvprintw(23,50,"%s",drvd);
        mvprintw(24,50,"%s",drve);
        mvprintw(25,50,"%s",drvz);

	attron(COLOR_PAIR(1));
	for(int i=0;i<getmaxy(stdscr);i++){
		for(int j=0;j<getmaxx(stdscr);j++){
			t=mvinch(i,j);
			mvaddch(i,j,(const chtype)t);
		}
	}
	attroff(COLOR_PAIR(1));

        getch();
//        endwin();

}

void drvchck(void){

	register int cd=0;
	register int state=0;

	char er[100];
	char err[500];
	char drvnames[6]="ACDEZ";
	char *drvs[5];

	drvs[0]=drva;
	drvs[1]=drvc;
	drvs[2]=drvd;
	drvs[3]=drve;
	drvs[4]=drvz;

	for(int i=0;i<5;i++){
		switch(chdir(drvs[i])){
			case -1:
				sprintf(er,"DRIVE %c IS DOWN, YOU CAN TRY TO CONTINUE, BUT FILES ON THE DRIVE WILL NOT BE SAVED!!\n",drvnames[i]);
				sprintf(err,"%s",er);
				state=1;
				break;
			default:
				break;
		}
	}
	if(state==1)
		bluescreen(err);
}

char *replace(char *string, char c1, char c2){

	char str[200];

	strcat(str, string);

	for(int i=0;i<strlen(str);i++){
		if(str[i]==c1)
			str[i]=c2;
	}
	sprintf(string,"%s",str);

	return string;
}
/*Checking if the mouse is in a specified coordinate area*/
int touch(int y, int x, int y1, int x1, MEVENT evnt){
	return ((evnt.y > y && evnt.y < y1) && (evnt.x > x && evnt. x < x1));
}
int mtouchwin(WINDOW *win, MEVENT evnt){
	return touch(getbegy(win),getbegx(win),getmaxy(win),getmaxx(win),evnt);
}
