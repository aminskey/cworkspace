#include<ncurses.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>

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

short fs, ss;
int col, ch;

int dir(WINDOW *,char *,int);
int more(WINDOW *, char *, int);

void locdrv(WINDOW *);
void Mzpause(WINDOW *);

char drive[]="ACDEZ";

int term(WINDOW *wterm){

	int winy;
	int winx;

        char cmd[30];
        char arg1[130];
        char arg2[130];
        char arg3[130];
        char arg4[130];
        char str[130];

        int ln=0;
        int cd=0;
	int st=0;
	int in=0;



	char srch[]=" ";

        char cwd[100];

        char cdrv='C';
        int drvstate=0;

	int dstate=0;

        if((dstate=drvchck())==-1){
        	sprintf(quote,"DRIVE %c IS DOWN, YOUR SYSTEM IS DOWN",drive[dstate]);
	        bluescreen(quote);
	}
	sprintf(quote,"YOUR SYSTEM IS DOWN");

	WINDOW *iterm=derwin(wterm,getmaxy(wterm)-2,getmaxx(wterm)-2,1,1);


	MEVENT evnt;

	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);


	sprintf(srch,"%s/.Mzdos/A/dat",home);
	FILE *fp=fopen(srch,"r");
	if(fp == NULL){
		bluescreen("Your System Is DOWN!! CALL THE MANUFACTURER AND TELL HIM THAT SOMETHINGS MESSED UP");
		exit(0);
	}else{
		fscanf(fp,"%d %d %fd %fd",&ch,&col,&fs,&ss);
	}

        start_color();
        init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(col,fs,ss);

	wclear(wterm);
	wclear(iterm);

        box(wterm,0,0);
        mvwprintw(wterm,0,(getmaxx(wterm)-strlen("Acorn Terminal"))/2,"Acorn Terminal");
        wrefresh(wterm);


        echo();
        curs_set(1);

        chdir(drvc);



        while(1){
		getcwd(cwd,180);

	        if((dstate=drvchck())==-1){
                	sprintf(quote,"DRIVE %c IS DOWN, YOUR SYSTEM IS DOWN",drive[dstate]);
                	bluescreen(quote);
        	}
	        sprintf(quote,"YOUR SYSTEM IS DOWN");


                wprintw(iterm,"%c:\\>",cdrv);
                wscanw(iterm,"%s %s %s %s %s",cmd,arg1,arg2,arg3,arg4);
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

        	if((dstate=drvchck())==-1){
                	sprintf(quote,"DRIVE %c IS DOWN, YOUR SYSTEM IS DOWN",drive[dstate]);
                	bluescreen(quote);
        	}
	        sprintf(quote,"YOUR SYSTEM IS DOWN");


                switch(drvstate){
                        case 1:
                                cdrv='A';
				chdir(drva);
                                drvstate=0;
                                break;
                        case 2:
                                cdrv='C';
				chdir(drvc);
                                drvstate=0;
                                break;
                        case 3:
                                cdrv='D';
				chdir(drvd);
                                drvstate=0;
                                break;
                        case 4:
                                cdrv='E';
				chdir(drve);
                                drvstate=0;
                                break;
                        case 5:
                                cdrv='Z';
				chdir(drvz);
                                drvstate=0;
                                break;
                        default:
				drvstate=0;
				chdir(cwd);
                                break;
                }


                if(!strcmp(cmd,"exit") || !strcmp(cmd,"EXIT")){
                        if(!strcmp(arg1,"_")){
				return st=0;
                        }

                        if(!strcmp(arg1,"desk") || !strcmp(arg1,"DESK")){
                                endwin();
                                exit(0);
                        }
                }if(!strcmp(cmd,"restart")||!strcmp(cmd,"RESTART")){
			main();
			exit(0);

		}if(!strcmp(cmd,"move")||!strcmp(cmd,"MOVE")){
			keypad(stdscr,TRUE);
			int c=getch();
			while(1){
				if(c==KEY_MOUSE){
					if(getmouse(&evnt)==OK){
						if(evnt.bstate >= BUTTON1_PRESSED){
							winy=evnt.y;
							winx=evnt.x;
						}
					}else{
						bluescreen("Your Mouse is not functioning, to use the desktop please fix the mouse!!");
						exit(0);
					}
				}
				break;
			}
                        if(!(winy>=(getmaxy(stdscr)-getmaxy(wterm))||winx>=(getmaxx(stdscr)-getmaxx(wterm)))){

				wclear(wterm);
				wattron(wterm,COLOR_PAIR(col));
				for(int i=0;i<getmaxy(wterm);i++){
					for(int j=0;j<getmaxx(wterm);j++)
						mvwprintw(wterm,i,j,"%c",ch);
				}
				wattroff(wterm,COLOR_PAIR(col));
				wrefresh(wterm);

				mvwin(wterm,winy,winx);
				return term(wterm);
			}
			else{
				ln+=3;
				wprintw(iterm,"You Cannot Place A Window Outside The Screen!!\n");
				ln++;
			}
		}if(!strcmp(cmd,"window")||!strcmp(cmd,"WINDOW")){
			if(!strcmp(arg1,"outer")||!strcmp(arg1,"OUTER")){
				int yside=getmaxy(wterm),xside=getmaxx(wterm);
				int y,x;
				getbegyx(wterm,y,x);
				wprintw(iterm,"size of window: %dx%d characters squared (ch2)\nwindow placed (%d,%d)\nstatus: window\n",yside,xside,y,x);
				ln+=5;
			}
			if(!strcmp(arg1,"inner")||!strcmp(arg1,"INNER")){
				int yside=getmaxy(iterm),xside=getmaxx(iterm);
				int y,x;
				getbegyx(iterm,y,x);
				wprintw(iterm,"size of window: %dx%d characters squared (ch2)\nsubwindow placed (%d,%d)\n times cleared: %d\nstatus: subwindow\n",yside,xside,y,x,in);
				ln+=5;
			}if(!strcmp(arg1,"all")||!strcmp(arg1,"ALL")){
				int yside=getmaxy(wterm),xside=getmaxx(wterm);
				int inyside=getmaxy(iterm),inxside=getmaxx(iterm);
				int y,x,iy,ix;
				getbegyx(wterm,y,x);
				getbegyx(iterm,iy,ix);
				wprintw(iterm,"size of window: %dx%d characters squared (ch2)\nsize of subwindow: %dx%d characters squared (ch2)\nwindow placed (%d,%d)\nsubwindow placed (%d,%d)\ntimes subwindow cleared: %d\nstatus: reporting both\n",yside,xside,inyside,inxside,y,x,iy,ix,in);
				ln+=11;
			}
		}if(!strcmp(cmd,"pwd")||!strcmp(cmd,"PWD")){
                        wprintw(iterm,"%s\n",cwd);
                }if(!strcmp(cmd,"cls")||!strcmp(cmd,"CLS")){
			wclear(iterm);
                        ln=0;
			in++;
		}if(!strcmp(cmd,"dir")||!strcmp(cmd,"DIR")){
			int dr=dir(iterm, arg1,ln);
			if(dr<=-1){
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
                                sprintf(str,"%s/.Mzdos/Z/commands.txt",home);
                                int f=more(iterm,str,ln);
                                if(f == -1){
                                        wprintw(iterm,"[more] : Cannot Open Requested File \'%s\' - \"--help\" for help\nif you do help _ , then it will display help page\n",str);
                                }else{
                                        ln=f;
                                }
                                continue;
                        }
                        sprintf(str,"%s/.Mzdos/Z/%s.txt",home,arg1);
                        int f=more(iterm,str,ln);
                        if(f == -1){
                                wprintw(iterm,"[more] : Cannot Open Requested File \'%s\' - \"--help\" for help\nif you do help _ , then it will display help page\n",str);
                        }else{
                                ln=f;
                        }
                        sprintf(str," ");
                }if(!strcmp(cmd,"reset")||!strcmp(cmd,"RESET")){
                        st=term(wterm);
			return st;
                }if(!strcmp(cmd,"console")||!strcmp(cmd,"CONSOLE")){
                        sprintf(str,"%s %s %s",arg1,arg2,arg3);
                        system(str);
                }if(!strcmp(cmd,"winout")||!strcmp(cmd,"WINOUT")){
			mvwprintw(wterm,0,0,"*");
			wrefresh(wterm);
			st=1;
			break;
		}if(!strcmp(cmd,"wheredrv")||!strcmp(cmd,"WHEREDRV")){
			locdrv(iterm);
		}if(!strcmp(cmd,"del")||!strcmp(cmd,"DEL")){
			int rm=remove(arg1);
			if(rm == -1){
				wprintw(iterm,"Cannot delete %s: %d",arg1,rm);
			}
			wprintw(iterm,"\n");
		}if(!strcmp(cmd,"cd")||!strcmp(cmd,"CD")||!strcmp(cmd,"chdir")||!strcmp(cmd,"CHDIR")){
			int cd=chdir(arg1);
			if(cd == -1){
				wprintw(iterm,"Cannot Access Directory: %d\n",cd);
			}
		}
		if(!strcmp(cmd,"mkdir")||!strcmp(cmd,"MKDIR")){
			int stat=mkdir(arg1,0777);
			if(stat == -1){
				wprintw(iterm,"Ooops Cannot Create Directory: %d",stat);
			}
			wprintw(iterm,"\n");
		}
                if(ln >= getmaxy(iterm)-1){
                        ln=0;
                        wclear(iterm);
                }

        	if((dstate=drvchck())==-1){
                	sprintf(quote,"DRIVE %c IS DOWN, YOUR SYSTEM IS DOWN",drive[dstate]);
                	bluescreen(quote);
        	}
	        sprintf(quote,"YOUR SYSTEM IS DOWN");

                sprintf(cmd," ");
//		sprintf(arg1," ");
//		sprintf(arg2," ");
                wrefresh(iterm);
        }
        noecho();
        curs_set(0);

	return st;

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
                i++;

                if(buff == '\n'){
                        ln++;
                }
                if(ln>=getmaxy(src)-1){
                        Mzpause(src);
                        wclear(src);
                        ln=0;
                }
		wprintw(src,"%c",buff);
        }
        wprintw(src,"\n---%s---\n",f);
        fclose(fp);

        return (ln++);

}
void locdrv(WINDOW *src){
	char drives[]={'A','C','D','E','Z'};
	char *drvs[]={0,0,0,0,0};

	drvs[0]=drva;
	drvs[1]=drvc;
	drvs[2]=drvd;
	drvs[3]=drve;
	drvs[4]=drvz;

	for(int i=0;i<45;i++){
		wprintw(src,"%c",(unsigned char)205);
		if(i == 15)
			wprintw(src,"%c",(unsigned char)206);
	}
	wprintw(src,"\nDRIVES");
	for(int i=strlen("\n WHERE"); i<45-strlen("DRIVES");i++){
		wprintw(src," ");
		if(i == 16){
			wprintw(src,"%c",(unsigned char)186);
		}
	}
	wprintw(src," WHERE\n");
        for(int i=0;i<45;i++){
                wprintw(src,"%c",(unsigned char)205);
                if(i == 15)
                        wprintw(src,"%c",(unsigned char)206);
        }
	wprintw(src,"\n");

	for(int i=0;i<5;i++){
		wprintw(src,"DRIVE %c",drives[i]);
		for(int i=strlen("DRIVE #");i<20;i++){
			wprintw(src," ");
			if(i == 15){
				wprintw(src,"%c",(unsigned char)186);
			}
		}
		wprintw(src,"%s\n",drvs[i]);
	}

        for(int i=0;i<45;i++){
                wprintw(src,"%c",(unsigned char)205);
                if(i == 15)
                        wprintw(src,"%c",(unsigned char)206);
        }
	wprintw(src,"\n");


}
void Mzpause(WINDOW *src){
	wprintw(src,"\tPress Anything To Continue ...");
	wgetch(src);
}
