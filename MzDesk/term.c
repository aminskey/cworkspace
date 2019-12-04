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
extern char home[];

extern int main();
extern int drvchck();
extern int bluescreen();

int dir(WINDOW *,char *,int);
int more(WINDOW *, char *, int);

void Mzpause(WINDOW *);

void term(void){
        char cmd[30];
        char arg1[30];
        char arg2[30];
        char str[30];

        int ln=0;
        int cd=0;

        char cwd[100];

        char cdrv='C';
        int drvstate=0;


        if(!drvchck())
                bluescreen(quote);

        WINDOW *wterm=newwin(MAXY/2, MAXX/2, MAXY/2 - MAXY/4, MAXX/2 - MAXX/4);
        WINDOW *iterm=derwin(wterm,getmaxy(wterm)-2,getmaxx(wterm)-2,1,1);

        start_color();
        init_pair(1,COLOR_WHITE,COLOR_CYAN);

        box(wterm,0,0);
        mvwprintw(wterm,0,(getmaxx(wterm)-strlen("BOXEmu Terminal"))/2,"BOXEmu Terminal");
        wrefresh(wterm);

        echo();
        curs_set(1);

        chdir(drvc);


        while(1){
		getcwd(cwd,180);

                if(!drvchck())
                        bluescreen(quote);
                
                
                wprintw(iterm,"%c:\\>",cdrv);
                wscanw(iterm,"%s %s %s",cmd,arg1,arg2);
                ln++;

                if(!strcmp(cmd,"A:")||!strcmp(cmd,"a:")){
                        drvstate=1;
                }if(!strcmp(cmd,"C:")||!strcmp(cmd,"c:")){
                        drvstate=2;
                }if(!strcmp(cmd,"D:")||!strcmp(cmd,"d:")){
                        drvstate=3;
                }if(!strcmp(cmd,"E:")||!strcmp(cmd,"e:")){
                        drvstate=4;
                }if(!strcmp(cmd,"Z:")||!strcmp(cmd,"z:")){
                        drvstate=5;
                }

                switch(drvstate){
                        case 1:
                                cdrv='A';
				cd=chdir(drva);
                                drvstate=0;
                                break;
                        case 2:
                                cdrv='C';
				cd=chdir(drvc);
                                drvstate=0;
                                break;
                        case 3:
                                cdrv='D';
				cd=chdir(drvd);
                                drvstate=0;
                                break;
                        case 4:
                                cdrv='E';
				cd=chdir(drve);
                                drvstate=0;
                                break;
                        case 5:
                                cdrv='Z';
				cd=chdir(drvz);
                                drvstate=0;
                                break;
                        default:
				cd=chdir(cwd);
                                break;
                }


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
                        ln=0;
		}if(!strcmp(cmd,"dir")||!strcmp(cmd,"DIR")){
			int dr=dir(iterm, arg1,ln);
			if(dr==-1){
				wprintw(iterm,"Oopsy Something went wrong!!\n");
			}
                        else{
                                ln=dr;
                        }
                }if(!strcmp(cmd,"more")||!strcmp(cmd,"MORE")){
                        int f=more(iterm, arg1, ln);
                        if(f == -1)               
                        {
                                wprintw(iterm,"[more] : Cannot Open Requested File -\'%s\' - \"--help\" for help\n",arg1);
                        }if(f==-2){
                                wprintw(iterm,"[Usage] : more [filename] --help --version\n");
                        }if(f==-3){
                                wprintw(iterm,"[Version]: 1\n");
                        }else{
                                ln=f;
                        }
                }if(!strcmp(cmd,"help")||!strcmp(cmd,"HELP")){
                        wprintw(iterm,"Help v 1.1\n\n");
                        ln+=2;
                        if(!strcmp(arg1,"_")){        
                                sprintf(str,"%s/.BOXEmu/commands.txt",home);
                                int f=more(iterm,str,ln);
                                if(f == -1){
                                        wprintw(iterm,"[more] : Cannot Open Requested File \'%s\' - \"--help\" for help\nif you do help _ , then it will display help page\n",str);
                                }else{
                                        ln=f;
                                }
                                continue;
                        }
                        sprintf(str,"%s/.BOXEmu/%s.txt",home,arg1);
                        int f=more(iterm,str,ln);
                        if(f == -1){
                                wprintw(iterm,"[more] : Cannot Open Requested File \'%s\' - \"--help\" for help\nif you do help _ , then it will display help page\n",str);
                        }else{
                                ln=f;
                        }
                        sprintf(str," ");
                }if(!strcmp(cmd,"reset")||!strcmp(cmd,"RESET")){
                        term();
                        exit(0);
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
int dir(WINDOW *src, char d[],int ln){

	int i=0;

	DIR *dp;
	struct dirent *dir;

	if((dp=opendir(d)) == NULL){
		return -1;
	}

	while((dir=readdir(dp)) != NULL){
		wprintw(src,"%25s",dir->d_name);
		i++;
		if(i>=2){
			ln++;
			wprintw(src,"\n");
			i=0;
		}

		if(ln >= getmaxy(src) - 2){
			Mzpause(src);
			wclear(src);
			ln=0;
		}
	}
        wprintw(src,"\n");
        closedir(dp);

        return ln;
}
int more(WINDOW *src, char *f, int ln){
        int i=0;
        char buff;

        FILE *fp=fopen(f,"r+");
        if(!strcmp(f,"--help")){
                return -2;
        }if(!strcmp(f,"--version")){
                return -3;
        }if(fp == NULL){
                return -1;
        }


        while(!feof(fp)){
                buff = fgetc(fp);
                wprintw(src,"%c",buff);
                i++;

                if(buff == '\n'){
                        ln++;
                }
                if(ln>=getmaxy(src)-1){
                        Mzpause(src);
                        wclear(src);
                        ln=0;
                }
        }
        wprintw(src,"\n---%s---\n",f);
        fclose(fp);

        return (ln++);

}
void Mzpause(WINDOW *src){
	wprintw(src,"\nPress Anything To Continue ...");
	wgetch(src);
}
