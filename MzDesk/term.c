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

int dir(WINDOW *,char *,int);
int more(WINDOW *, char *, int);

void locdrv(WINDOW *);
void Mzpause(WINDOW *);



int term(WINDOW *wterm){
        char cmd[30];
        char arg1[130];
        char arg2[130];
        char arg3[130];
        char arg4[130];
        char str[130];

        int ln=0;
        int cd=0;
	int st=0;

        char cwd[100];

        char cdrv='C';
        int drvstate=0;


        if(!drvchck())
                bluescreen(quote);

	WINDOW *iterm=derwin(wterm,getmaxy(wterm)-2,getmaxx(wterm)-2,1,1);

        start_color();
        init_pair(1,COLOR_WHITE,COLOR_CYAN);

	wclear(wterm);
	wclear(iterm);

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

		if(!drvchck()){
			bluescreen(quote);
		}

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
                }if(!strcmp(cmd,"pwd")||!strcmp(cmd,"PWD")){
                        wprintw(iterm,"%s\n",cwd);
                }if(!strcmp(cmd,"cls")||!strcmp(cmd,"CLS")){
			wclear(iterm);
                        ln=0;
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
                                sprintf(str,"%s/.Mzdos/commands.txt",home);
                                int f=more(iterm,str,ln);
                                if(f == -1){
                                        wprintw(iterm,"[more] : Cannot Open Requested File \'%s\' - \"--help\" for help\nif you do help _ , then it will display help page\n",str);
                                }else{
                                        ln=f;
                                }
                                continue;
                        }
                        sprintf(str,"%s/.Mzdos/%s.txt",home,arg1);
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

	for(int i=0;i<30;i++){
		wprintw(src,"%c",(unsigned char)205);
		if(i == 15)
			wprintw(src,"%c",(unsigned char)206);
	}
	wprintw(src,"\nDRIVES");
	for(int i=strlen("\n WHERE"); i<30-strlen("DRIVES");i++){
		wprintw(src," ");
		if(i == 16){
			wprintw(src,"%c",(unsigned char)186);
		}
	}
	wprintw(src," WHERE\n");
        for(int i=0;i<30;i++){
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

        for(int i=0;i<30;i++){
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
