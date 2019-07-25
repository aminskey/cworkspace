#include<stdio.h>
#include<ncurses.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>

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
intro:
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

        mvwprintw(hw,0,(getmaxx(hw)-strlen("  MyBox v1.5  "))/2,"%c MyBox v1.5 %c",(unsigned char)185,(unsigned char)204);
        mvwprintw(hw,2,1,"Type help for help");
        wrefresh(hw);
        wattroff(hw, COLOR_PAIR(1));
        echo();

	char str[200];
	int c=0;

        i=20;
        while(1){
		getwd(pwd);
                mvprintw(0+i,0,"Cprog:%s> ",pwd);
                scanw("%s",s);

                if(strcmp(s,"HELP")==false || strcmp(s,"help")==false)
                {
                       printw("DIR - DISPLAY FILES IN DIRECTORY\nTYPE - read file\nARCHIVE - File Search Engine\nCD - Change Current Directory\nHELP - ....... you just called this one\nEXIT - ...It's quite obvious\nCLEAR - Will Clear The screen\nPWD - Print Current Directory\nConsole - Run Command On Console\nWIN - Will Run Desktop\nEDIT - A Full Screen Editor\nINTRO - BOXEmu Introduction\nPAUSE - Will Wait For A Keystroke\n---%cNo Other Commands Yet%c---",(unsigned char)185,(unsigned char)204);
                       i=i+14;

                }if(strcmp(s,"PAUSE")==false || strcmp(s,"pause")==false)
		{
			printw("Press Any Thing to Continue ...");
			getch();
			i=i+2;
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
			scanw(s);
			system(s);

			getch();
			clear();
			i=0;
		}if(strcmp(s, "PWD")==false || strcmp(s, "pwd")==false)
		{
			printw("%s",pwd);
			i=i+2;
		}if(strcmp(s, "EDIT")==false || strcmp(s, "edit")==false){
			system("~/bin/Edit");
			clear();
			i=0;
		}if(strcmp(s, "INTRO")==false || strcmp(s, "intro")==false)
		{
			goto intro;
		}if(strcmp(s, "DIR")==false || strcmp(s, "dir")==false){
			/*system("~/bin/dir");
			clear();*/
			if((dp=opendir(pwd)) == NULL){
				printw("OOPS .. Something Went Wrong");
			}
			while((dir=readdir(dp)) != NULL)
			{
				mvprintw(i,c,"%s",dir->d_name);
				c=c+20;
				if(c % 2 == 0)
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
		}else{
			i=i+1;
		}
		sprintf(s," ");
        }


        noecho();
        endwin();
        return 0;
}
