#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<curses.h>
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

char quote[]="YOUR DRIVES ARE DOWN, EDIT THE \'drvConf\' C FILE AND BUILD AGAIN";

int drvchck(void);
void bluescreen(char *s);
void wpaint(WINDOW *,char, short);
void paint(char , short);
void term(void);
void wprcs(WINDOW *src);

int ststate=1;

char drives[6]="ACDEZ";

void paint(char ch, short clr){
        wpaint(stdscr,ch,clr);
}

int main(void){



        int c=0;
        char in[50];
        char secin[50];


        time_t lctime;
        struct tm * loctime;

        time(&lctime);
        loctime=localtime(&lctime);


        initscr();
        noecho();
        cbreak();

        curs_set(0);

        srand(time(0));

        WINDOW *menu=newwin(3,MAXX,MAXY-3,0);
        WINDOW *note=newwin(MAXY/2, MAXX/2, MAXY/2 - MAXY/4, MAXX/2 - MAXX/4);
        WINDOW *mb2=newwin(24,24,(MAXY-getmaxy(menu)-24),0);
        WINDOW *optm=derwin(mb2,3,getmaxx(mb2)-2,1,1);
        WINDOW *opoff=derwin(mb2,3,getmaxx(mb2)-2,1+getmaxy(optm),1);
        WINDOW *oped=derwin(mb2,3,getmaxx(mb2)-2,1+getmaxy(optm)*2,1);
        WINDOW *oprs=derwin(mb2,3,getmaxx(mb2)-2,1+getmaxy(optm)*3,1);
        WINDOW *info=newwin(10,20,rand()%MAXY/2,rand()%MAXX/2);
        WINDOW *srch=newwin(3,getmaxx(mb2)-2,rand()%MAXY/2,rand()%MAXX/2);

        MEVENT evnt;

        mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);


        if(!drvchck())
                bluescreen(quote);

        start_color();
        init_pair(1,COLOR_WHITE, COLOR_CYAN);
        init_pair(2,COLOR_WHITE, COLOR_BLUE);
        init_pair(3,COLOR_WHITE, COLOR_BLACK);
        init_pair(4,COLOR_BLUE, COLOR_WHITE);


        paint(32,1);

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
                curs_set(0);

                time(&lctime);
                loctime=localtime(&lctime);

                wattron(menu,COLOR_PAIR(4));
                mvwprintw(menu,1,1,"start");
                mvwprintw(menu,1,10,"%d:%d",loctime->tm_hour, loctime->tm_min);
                wattroff(menu,COLOR_PAIR(4));

                if(!drvchck())
                        bluescreen(quote);

                c=getch();
                if(c==KEY_MOUSE){
                        if(getmouse(&evnt) == OK){
                                if(evnt.bstate >= BUTTON1_PRESSED){
                                        if((evnt.y >= (MAXY-getmaxy(menu)) && evnt.y <= MAXY) && (evnt.x >= 1 && evnt.x <= strlen("start"))){
                                                mvwprintw(menu,1,1,"start");
                                                ststate=0;
                                                wrefresh(menu);
                                        }
                                }
                        }else{
                                bluescreen("DESKTOP HAS CRASHED, BECAUSE THERE IS NO MOUSE");
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
                        mvwprintw(optm,1,1,"BOXEmu Terminal");


                        wattroff(optm,COLOR_PAIR(4));
                        wrefresh(optm);

                        wpaint(opoff,32,4);
                        wattron(opoff,COLOR_PAIR(4));

                        box(opoff,0,0);
                        mvwprintw(opoff,1,1,"Off Button");

                        wattroff(opoff,COLOR_PAIR(4));
                        wrefresh(opoff);

                        wpaint(oped,32,4);
                        wattron(oped,COLOR_PAIR(4));

                        box(oped,0,0);
                        mvwprintw(oped,1,1,"Project Editor");

                        wattroff(oped,COLOR_PAIR(4));
                        wrefresh(oped);

                        wpaint(oprs,32,4);
                        wattron(oprs,COLOR_PAIR(4));

                        box(oprs,0,0);
                        mvwprintw(oprs,1,1,"Reset Computer");

                        wattroff(oprs,COLOR_PAIR(4));
                        wrefresh(oprs);

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
                }
                if(ststate==1){
                        wpaint(mb2,32,1);
                        wpaint(optm,32,1);
                        wpaint(srch,32,1);
                        wpaint(opoff,32,1);


                        wrefresh(srch);
                        wrefresh(optm);
                        wrefresh(mb2);
                        wrefresh(opoff);

                        wattron(menu,COLOR_PAIR(4));
                        mvwprintw(menu,1,1,"start");
                        wattron(menu,COLOR_PAIR(4));

                        wrefresh(menu);

                }
                if(!strcmp(in,"BOXEmu")){
                        if(!strcmp(secin,"Terminal"))
                        {
                                term();

                        }
                }
                if(!strcmp(in,"Off")){
                        if(!strcmp(secin,"Button")){
                                clear();
                                mvprintw(0,0,"Turning Off");
                                usleep(500);
                                endwin();
                                return 0;
                        }
                }
                if(!strcmp(in,"Project"))
                {
                        if(!strcmp(secin,"Editor"))
                                wprcs(note);
                }
                if(!strcmp(in,"Reset")){
                        if(!strcmp(secin,"Computer")){
                                main();
                                return 0;
                        }
                }
                if(c==KEY_F(9))
                        break;
                if(c==KEY_F(12)){
                        main();
                        return 0;
                }
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

        getch();
        endwin();

        perror("Something Went Wrong");
        exit(EOF);

}

int drvchck(void){
        int cd=0;


        extern const char drva[];
        extern const char drvc[];
        extern const char drvd[];
        extern const char drve[];
        extern const char drvz[];

        if((cd=chdir(drva)) != 0){
                return cd;
        }else{
                return EOF;
        }
        if((cd=chdir(drvc)) != 0){
                return cd;
        }else{
                return EOF;
        }
        if((cd=chdir(drvd)) != 0){
                return cd;
        }else{
                return EOF;
        }
        if((cd=chdir(drve)) != 0){
                return cd;
        }else{
                return EOF;
        }
        if((cd=chdir(drvz)) != 0){
                return cd;
        }else{
                return EOF;
        }




}
void term(void){
        DIR *dp;
        struct dirent *dir;

        char cmd[30];
        char arg1[30];
        char arg2[30];

        int ln=0;
        int cd=0;

        char cwd[100];

        char cdrv='C';
        char drvstate=0;

	int dln, imy;

	dln=imy=0;

        if(!drvchck())
                bluescreen(quote);

        WINDOW *term=newwin(MAXY/2, MAXX/2, MAXY/2 - MAXY/4, MAXX/2 - MAXX/4);
        WINDOW *iterm=derwin(term,getmaxy(term)-2,getmaxx(term)-2,1,1);

        start_color();
        init_pair(1,COLOR_WHITE,COLOR_CYAN);

        box(term,0,0);
        mvwprintw(term,0,(getmaxx(term)-strlen("BOXEmu Terminal"))/2,"BOXEmu Terminal");
        wrefresh(term);

        echo();
        curs_set(1);

        chdir(drvc);


        while(1){

		getcwd(cwd,180);

                if(!drvchck())
                        bluescreen(quote);

                switch(drvstate){
                        case 0:
                                cd=chdir(cwd);
                                break;

                        case 1:
                                cdrv='A';
                                drvstate=0;
                                break;
                        case 2:
                                cdrv='C';
                                drvstate=0;
                                break;
                        case 3:
                                cdrv='D';
                                drvstate=0;
                                break;
                        case 4:
                                cdrv='E';
                                drvstate=0;
                                break;
                        case 5:
                                cdrv='Z';
                                drvstate=0;
                                break;
                        default:
                                break;
                }

                wprintw(iterm,"%c:\\>",cdrv);
                wscanw(iterm,"%s %s %s",cmd,arg1,arg2);
                ln++;

                if(!strcmp(cmd,"exit") || !strcmp(cmd,"EXIT")){
                        if(!strcmp(arg1,"_")){
                                main();
                                exit(0);
                        }

                        if(!strcmp(arg1,"desk") || !strcmp(arg1,"DESK")){
                                endwin();
                                exit(0);
                        }
                }if(!strcmp(cmd,"pwd")||!strcmp(cmd,"PWD")){
                        wprintw(iterm,"%s\n",cwd);
                }if(!strcmp(cmd,"cls")||!strcmp(cmd,"CLS")){
			wclear(iterm);
		}if(!strcmp(cmd,"dir")||!strcmp(cmd,"DIR")){

                        if((dp=opendir(arg1)) == NULL){
                                wprintw(iterm,"Something Went Wrong !!\n");
                        }
                        while((dir=readdir(dp)) != NULL){
                                imy++;
                                if(imy >= 3){
                                        wprintw(iterm,"\n");

                                        imy=0;
					dln++;
                                }
                                if(dln >= getmaxy(iterm)-2){
                                        wprintw(iterm,"\nPress Anything To Continue!!");
                                        getch();
                                        wclear(iterm);
                                }

				wprintw(iterm,"%s ",dir->d_name,imy);
			}
			wprintw(iterm,"\n");
  	        	closedir(dp);
                }if(!strcmp(cmd,"A:")||!strcmp(cmd,"a:")){
                        int cd=chdir(drva);
                        drvstate=1;
                }if(!strcmp(cmd,"C:")||!strcmp(cmd,"c:")){
                        int cd=chdir(drvc);
                        drvstate=2;
                }if(!strcmp(cmd,"D:")||!strcmp(cmd,"d:")){
                        int cd=chdir(drvd);
                        drvstate=3;
                }if(!strcmp(cmd,"E:")||!strcmp(cmd,"e:")){
                        int cd=chdir(drve);
                        drvstate=4;
                }if(!strcmp(cmd,"Z:")||!strcmp(cmd,"z:")){
                        int cd=chdir(drvz);
                        drvstate=5;
                }
                if(ln >= getmaxy(iterm)-1){
                        ln=0;
                        wclear(iterm);
                }

                sprintf(cmd," ");
                wrefresh(iterm);
        }
        noecho();
        curs_set(0);

}
void wprcs(WINDOW *src){
        WINDOW *sub=derwin(src,getmaxy(src)-2,getmaxx(src)-2,1,1);

        init_pair(1,COLOR_MAGENTA,COLOR_CYAN);
        init_pair(2,COLOR_WHITE,COLOR_BLUE);

        refresh();
        wattron(src,COLOR_PAIR(1));

        box(src,0,0);
        wpaint(sub,176,2);

        mvwprintw(src,0,(getmaxx(src)-strlen("# Project Editor #"))/2,"%c Project Editor %c",(unsigned char)185,(unsigned char)204);

        wattroff(src,COLOR_PAIR(1));
        wrefresh(src);
}
