#include<ncurses.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

#define MAXY getmaxy(stdscr)
#define MAXX getmaxx(stdscr)

extern char drva[];
extern char drvc[];
extern char drvd[];
extern char drve[];
extern char drvz[];
extern char quote[];

extern int main();
extern int drvchck();
extern int bluescreen();

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
                                if(imy >= 1){
                                        wprintw(iterm,"\n");

                                        ++dln;
                                        imy=0;
                                }
                                if(dln > getmaxy(iterm)-1){
                                        wprintw(iterm,"\nPress Anything To Continue!!");
                                        getch();
                                        wclear(iterm);
                                }

				wprintw(iterm,"%s - %d\t",dir->d_name,imy);
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
