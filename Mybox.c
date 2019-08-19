#include<stdio.h>
#include<ncurses.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>

int call(const char *s);


int main(void)
{
	DIR *dp;
	struct dirent *dir;


        initscr();
        noecho();
        cbreak();
//      nodelay();

        int i=0;
        char s[2048]=" ";
	char pwd[4096];


        start_color();
        init_pair(1,COLOR_WHITE,COLOR_BLUE);
        WINDOW *hw=newwin(getmaxy(stdscr)/4,getmaxx(stdscr)/4,0,0);

        system("~/bin/cimg .myBox/info/.info");

        refresh();
        wattron(hw,COLOR_PAIR(1));
        box(hw,0,0);
        wattroff(hw,COLOR_PAIR(1));
        wrefresh(hw);


        wattron(hw,COLOR_PAIR(1));
        for(int a=1;a<getmaxy(hw)-1; a++)
        {
                for(int b=1;b<getmaxx(hw)-1;b++)
                        mvwprintw(hw,a,b," ");
        }

        mvwprintw(hw,0,(getmaxx(hw)-strlen("  BoxEmu  "))/2,"%c BoxEmu %c",(unsigned char)185,(unsigned char)204);
        mvwprintw(hw,2,1,"Type help for help");
        wrefresh(hw);
        wattroff(hw, COLOR_PAIR(1));
        echo();

	char str[200];
	int c=0;
	char gcmp[200];
	char cmp[200];

        i=20;
        while(1){
		getwd(pwd);
                mvprintw(0+i,0,"Cprog:%s> ",pwd);
                scanw("%s",s);

                if(strcmp(s,"HELP")==false || strcmp(s,"help")==false)
                {
                       printw("GCC - compile c programs\nNANO - The system file editor\nTOUCH - create new file\nVER - Display Version\nFIND - find files with the same name / letter \nRM - Remove File\nDIR - Display Files In Directory\nTYPE - read file\nARCHIVE - File Search Engine\nCD - Change Current Directory\nHELP - ....... you just called this one\nEXIT - ...It's quite obvious\nCLEAR - Will Clear The screen\nPWD - Print Current Directory\nCONSOLE - Run Command On Console\nWIN - Will Run Desktop\nEDIT - A Full Screen Editor\nINTRO - BOXEmu Introduction\nPAUSE - Will Wait For A Keystroke\n");
                       i=i+20;

                }if(strcmp(s,"CALL")==false || strcmp(s,"call")==false){
			sprintf(s," ");
			scanw(s);
			call(s);

		//	endwin();
		//	initscr();
			clear();
			i=0;
		}if(strcmp(s,"PAUSE")==false || strcmp(s,"pause")==false)
		{
			noecho();
			printw("Press Any Thing to Continue ...");
			getch();
			i=i+2;
			echo();
		}if(strcmp(s,"EXIT")==false || strcmp(s, "exit")==false)
                {
                        break;
                }if(strcmp(s,"CLEAR")==false || strcmp(s,"clear")==false)
                {
                        i=0;
                        clear();
                }
		if(strcmp(s,"CONSOLE")==false || strcmp(s,"console")==false)
		{
			sprintf(s," ");
			scanw("%s",s);
			endwin();
			system(s);

			initscr();
			getch();
			clear();
			i=0;
		}if(strcmp(s, "PWD")==false || strcmp(s, "pwd")==false)
		{
			printw("%s",pwd);
			i=i+2;
		}if(strcmp(s, "EDIT")==false || strcmp(s, "edit")==false){
			endwin();
			system("~/bin/Edit");
			initscr();
			clear();
			i=0;
		}if(strcmp(s, "DIR")==false || strcmp(s, "dir")==false){
			/*system("~/bin/dir");
			clear();*/
			if((dp=opendir(pwd)) == NULL){
				printw("OOPS .. Something Went Wrong");
			}
			i+=1;
			while((dir=readdir(dp)) != NULL)
			{
				mvprintw(i,c,"%s",dir->d_name);
				c+=40;
				if(c % 3 == 0)
				{
					i++;
					printw("\n");
					c=0;
				}if(i >  getmaxy(stdscr)-4){
					mvprintw(getmaxy(stdscr)-1,0,"Press Anything To Continue");
					getch();
					clear();
					i=0;
				}
			}
			i++;
			closedir(dp);
		}if(strcmp(s, "WIN")==false || strcmp(s, "win")==false){
			sprintf(str,"~/bin/WinSh %s",pwd);
			system(str);
			clear();
			i=0;
		}if(i > getmaxy(stdscr)-1){
			clear();
			i=0;
		}if(strcmp(s, "CD")==false ||  strcmp(s, "cd")==false)
		{
			sprintf(s," ");
			scanw("%s",s);
			int ch=chdir(s);
			if(ch == -1)
				printw("Cannot Change to Requested Directory");
			i=i+3;
		}if(strcmp(s, "ARCHIVE")==false || strcmp(s, "archive")==false){
			system("~/bin/Archive");
			clear();
			i=0;
		}if(strcmp(s, "TYPE")==false || strcmp(s, "type")==false){
			sprintf(s, " ");
			scanw("%s",s);
			sprintf(str,"~/bin/dog %s",s);
			system(str);
			clear();
			i=i+3;
		}if(strcmp(s,"VER") == false || strcmp(s,"ver")==false){
			printw("BoxEmu v0.1 = MyBox v1.6 beta\n\n\tSUPERSIX");
			i=i+3;
		}if(strcmp(s, "RM") == false || strcmp(s, "rm")==false){
			sprintf(s, " ");
			scanw("%s",s);
			int retrn=remove(s);
			if(retrn == -1)
				printw("Cannot Remove Requested File");
			i=i+4;

		}if(strcmp(s, "FIND")==false || strcmp(s, "find")==false){
			sprintf(s, " ");
			scanw("%s",s);
			i++;
			if((dp=opendir(pwd))==NULL){
				printw("Cannot Open Direcotry");
			}
			while((dir=readdir(dp)) != NULL){
				if(strncmp(s,dir->d_name,strlen(s))==false){
					printw("%s\n",dir->d_name);
					i++;
				}
			}
			closedir(dp);
		}if(strcmp(s,"nano")==false || strcmp(s,"NANO")==false){
			system("nano");
			clear();
			i=0;
		}if(strcmp(s,"gcc")==false || strcmp(s,"GCC")==false){
			sprintf(cmp," ");
			scanw("%s",cmp);
			sprintf(gcmp,"gcc %s -lncurses",cmp);

			printw("%s\nPress Anything To Compile",gcmp);
			getch();
			endwin();
			system(gcmp);

			sleep(1);
			usleep(500);
			initscr();
			i=i+2;
		}if(strcmp(s,"TOUCH")==false || strcmp(s,"touch")==false){
			sprintf(s," ");
			scanw("%s",s);
			FILE *chk=fopen(s,"r");
			if(chk != NULL)
			{
				printw("FILE ALL READY EXISTS");
			}else if(chk == NULL)
			{
				FILE *fp=fopen(s,"w+");
				fclose(fp);
			}
			fclose(chk);
			i=i+2;

		}else{
			i=i+1;
		}
		sprintf(s," ");
        }


        noecho();
        endwin();
        return 0;
}
int call(const char *f){

	DIR *dp;
        struct dirent *dir;

	char pwd[200];


	char s[200];

	FILE *fp=fopen(f,"r");
	int i=20;
	int c=0;
	char str[200];

	if(fp == NULL)
		return -1;
	while(!feof(fp)){

		fscanf(fp,"%s",s);
                if(strcmp(s, "DIR")==false || strcmp(s, "dir")==false){
                        /*system("~/bin/dir");
                        clear();*/
                        if((dp=opendir(pwd)) == NULL){
                                printw("OOPS .. Something Went Wrong");
                        }
                        i+=1;
                        while((dir=readdir(dp)) != NULL)
                        {
                                mvprintw(i,c,"%s",dir->d_name);
                                c+=40;
                                if(c % 3 == 0)
                                {
                                        i++;
                                        printw("\n");
                                        c=0;
                                }if(i >  getmaxy(stdscr)-4){
                                        mvprintw(getmaxy(stdscr)-1,0,"Press Anything To Continue");
                                        getch();
                                        clear();
                                        i=0;
                                }
                        }
                        i++;
                        closedir(dp);
                }if(strcmp(s, "WIN")==false || strcmp(s, "win")==false){
                        sprintf(str,"~/bin/WinSh %s",pwd);
                        system(str);
                        clear();
                        i=0;
                }if(strcmp(s, "TYPE")==false || strcmp(s, "type")==false){
                        fscanf(fp,"%s",s);
                        sprintf(str,"~/bin/dog %s",s);
                        system(str);
                        clear();
                        i=i+3;
                }if(strcmp(s, "CD")==false ||  strcmp(s, "cd")==false)
                {
                        fscanf(fp,"%s",s);
                        int ch=chdir(s);
                        if(ch == -1)
                                printw("Cannot Change to Requested Directory");
                        i=i+3;
                }if(strcmp(s,"PAUSE")==false || strcmp(s,"pause")==false)
                {
                        noecho();
                        printw("Press Any Thing to Continue ...");
                        getch();
                        i=i+2;
                        echo();
                }if(strcmp(s,"EXIT")==false || strcmp(s, "exit")==false)
                {
                        break;
                }if(strcmp(s,"CLEAR")==false || strcmp(s,"clear")==false)
                {
                        i=0;
                        clear();
                }if(strcmp(s, "PWD")==false || strcmp(s, "pwd")==false)
                {
			getwd(pwd);
                        printw("%s",pwd);
                        i=i+2;
                }if(strcmp(s, "ARCHIVE")==false || strcmp(s, "archive")==false){
                        system("~/bin/Archive");
                        clear();
                        i=0;
                }if(strcmp(s, "FIND")==false || strcmp(s, "find")==false){
                        fscanf(fp,"%s",s);
                        i++;
                        if((dp=opendir(pwd))==NULL){
                                printw("Cannot Open Direcotry");
                        }
                        while((dir=readdir(dp)) != NULL){
                                if(strncmp(s,dir->d_name,strlen(s))==false){
                                        printw("%s\n",dir->d_name);
                                        i++;
                                }
                        }
                        closedir(dp);
                }if(strcmp(s,"TOUCH")==false || strcmp(s,"touch")==false){
                        fscanf(fp,"%s",s);
                        FILE *chk=fopen(s,"r");
                        if(chk != NULL)
                        {
                                printw("FILE ALL READY EXISTS");
                        }else if(chk == NULL)
                        {
                                FILE *fp=fopen(s,"w+");
                                fclose(fp);
                        }
                        fclose(chk);
                        i=i+2;

               }if(strcmp(s, "RM") == false || strcmp(s, "rm")==false){
                        fscanf(fp,"%s",s);
                        int retrn=remove(s);
                        if(retrn == -1)
                                printw("Cannot Remove Requested File");
                        i=i+4;

               }

	}

	return 0;
}
