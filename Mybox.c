#include<stdio.h>
#include<ncurses.h>
#include<string.h>
#include<stdlib.h>	// For Them Viewing the code please feel free to fork and change the call function!
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>

int call(const char *s);

int crt(const char *s);

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dir;

	crt("~/.BOXEmu/");
	system("~/bin/cimg ~/.BOXEmu/intro.img");

        initscr();
        noecho();
        cbreak();
	clear();
//      nodelay();

	curs_set(1);

        int i=0;
        char s[2048]=" ";
	char pwd[4096];
	char run[100];


	const char drvz[200] = "/mnt";
	const char drve[200] = "/bin";
	const char drvc[200] = "/home/amin";
	const char drvd[200] = "/media/amin";
	const char drva[200] = "/";

	char drivs[]="ACDEZ";
	char drv[200];
	char drvl[20];

        start_color();
        init_pair(1,COLOR_WHITE,COLOR_BLUE);
	init_pair(2,COLOR_WHITE, COLOR_RED);

        WINDOW *hw=newwin(getmaxy(stdscr)/4,getmaxx(stdscr)/4,0,0);
	WINDOW *msg=newwin(getmaxy(stdscr)/2,getmaxx(stdscr),getmaxy(stdscr)/2 - getmaxy(stdscr)/4, 0);
	WINDOW *sub=newwin(20,60,10,90);

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

	int dv=2;
	int conf=0;
	int chd=0;
	int div=0;

	chd=chdir(drva);
	if(chd==-1){
		mvprintw(1,10,"CANNOT LOCATE DRIVE A");
		drvl[conf++]='A';
	}
	chd=chdir(drvc);
        if(chd==-1){
                mvprintw(3,10,"CANNOT LOCATE DRIVE C");
		drvl[conf++]='C';
        }
        chd=chdir(drvd);
        if(chd==-1){
                mvprintw(6,10,"CANNOT LOCATE DRIVE D");
		drvl[conf++]='D';
        }
        chd=chdir(drvz);
        if(chd==-1){
                mvprintw(9,10,"CANNOT LOCATE DRIVE Z");
		drvl[conf++]='Z';
        }
	chd=chdir(drve);
	if(chd==-1){
		mvprintw(12,10,"CANNOT LOCATE DRIVE E");
		drvl[conf++]='E';
	}
	if(conf>=1){
		curs_set(0);
		wattron(msg,COLOR_PAIR(2));
		for(int a=1;a<getmaxy(msg)-1; a++)
        	{
                	for(int b=1;b<getmaxx(msg)-1;b++)
                        	mvwprintw(msg,a,b," ");
        	}

		refresh();
		box(msg,0,0);
		wrefresh(msg);

		mvwprintw(msg,0,(getmaxx(msg)-strlen("_ FATAL ERROR! _"))/2,"%c FATAL ERROR! %c",(unsigned char)185,(unsigned char)204);

		mvwprintw(msg,6,10,"%s Cannot Locate Your Drives",argv[0]);

		wrefresh(msg);


   	        wattron(sub,COLOR_PAIR(2));
		refresh();
		box(sub,0,0);

		mvwprintw(sub,0,(getmaxx(stdscr)-strlen("_ DRIVE STATUS _"))/2,"%c DRIVE STATUS %c",(unsigned char)185,(unsigned char)204);

                for(int a=1;a<getmaxy(sub)-1; a++)
                {
                        for(int b=1;b<getmaxx(sub)-1;b++)
                                mvwprintw(sub,a,b," ");
                }
		wrefresh(sub);



		mvwprintw(sub,5,10,"DRIVE A: %s ",drva);
		mvwprintw(sub,7,10,"DRIVE C: %s",drvc);
		mvwprintw(sub,9,10,"DRIVE D: %s",drvd);
		mvwprintw(sub,11,10,"DRIVE Z: %s",drvz);
		mvwprintw(sub,13,10,"DRIVE E: %s",drve);

		mvwprintw(sub,15,20,"%d Drives Are Down",conf);
		mvwprintw(sub,17,20,"Drives: %s",drvl);

		wrefresh(sub);
		wattroff(sub,COLOR_PAIR(2));

		mvwprintw(msg,12,10,"You Can Continue(It Won't Work!!)");
		mvwprintw(msg,14,10,"Or You Can Just Exit And Edit The File, Run Make BOXEmu And Things Will Work!!");
		mvwprintw(msg,15,10,"\'r\' to rescan");
		mvwprintw(msg,getmaxy(msg)-1,(getmaxx(msg)-strlen("_ Space To Continue _"))/2,"%c Space To Continue %c",(unsigned char)185,(unsigned char)204);

		wrefresh(msg);

		keypad(msg,true);

		wattroff(msg,COLOR_PAIR(2));

		int inc=getch();

		if(inc==32)
		{
	                for(int a=1;a<getmaxy(hw)-1; a++)
        	        {
                	        for(int b=1;b<getmaxx(hw)-1;b++)
                        	        mvwprintw(msg,a,b," ");
	                }
			wrefresh(msg);
			sprintf(drv," ");
		}if(inc=='r'){
			main(argc,argv);
			return 0;
		}else{
			echo();
			endwin();
			return -1;
		}


	}
	else{
		chdir(drvc);
		conf=0;
		sprintf(drv,"C:\\");
		dv=3;
	}

	char mdr[60];

	div=0;

	move(15,0);
	for(int a=0;a<35;a++){
		printw("%c",(unsigned char)205);
		if(a == 17)
			printw("%c",(unsigned char)206);
	}
	printw("\nDRIVES");
	for(int b=6;b<28;b++){
		printw(" ");
		if(b == 17){
			printw("%c",(unsigned char)186);
		}
	}
	printw("WHERE\n");
	for(int c=0;c<35;c++){
		printw("%c",(unsigned char)205);
		if(c==17){
			printw("%c",(unsigned char)206);
		}
	}
	for(int y=0;y<5;y++){
		div++;
		printw("\n");
		printw("DRIVE %c",drivs[y]);
		for(int x=0;x<15;x++){
			printw(" ");
			if(x == 10){
				printw("%c",(unsigned char)186);
			}
		}
		switch(div){
			case 1:
				printw("%s",drva);
				break;
			case 2:
				printw("%s",drvc);
				break;
			case 3:
				printw("%s",drvd);
				break;
			case 4:
				printw("%s",drve);
				break;
			case 5:
				printw("%s",drvz);
				break;
			default:
				break;
		}
	}
	printw("\n");
	for(int j=0;j<35;j++){
		printw("%c",(unsigned char)205);
		if(j==17){
			printw("%c",(unsigned char)206);
		}
	}
	printw("\n");

	i=24;
	conf=0;
        while(1){
		getwd(pwd);
        	mvprintw(0+i,0,"%s> ",drv);
        	scanw("%s",s);

		chd=chdir(drva);
		if(chd==-1){
				mvprintw(1,10,"CANNOT LOCATE DRIVE A");
				drvl[conf++]='A';
		}
		chd=chdir(drvc);
		if(chd==-1){
				mvprintw(3,10,"CANNOT LOCATE DRIVE C");
				drvl[conf++]='C';
		}
		chd=chdir(drvd);
		if(chd==-1){
				mvprintw(6,10,"CANNOT LOCATE DRIVE D");
				drvl[conf++]='D';
		}
		chd=chdir(drvz);
		if(chd==-1){
				mvprintw(9,10,"CANNOT LOCATE DRIVE Z");
				drvl[conf++]='Z';
		}
	        chd=chdir(drve);
	        if(chd==-1){
        	        mvprintw(12,10,"CANNOT LOCATE DRIVE E");
                	drvl[conf++]='E';
        	}

		if(conf>=1){
			curs_set(0);
			wattron(msg,COLOR_PAIR(2));
			for(int a=1;a<getmaxy(msg)-1; a++)
			{
				for(int b=1;b<getmaxx(msg)-1;b++)
					mvwprintw(msg,a,b," ");
			}

			refresh();
			box(msg,0,0);
			wrefresh(msg);

			mvwprintw(msg,0,(getmaxx(msg)-strlen("_ FATAL ERROR! _"))/2,"%c FATAL ERROR! %c",(unsigned char)185,(unsigned char)204);

			mvwprintw(msg,6,10,"%s Cannot Locate Your Drives",argv[0]);

			wrefresh(msg);


			wattron(sub,COLOR_PAIR(2));
			refresh();
			box(sub,0,0);

			mvwprintw(sub,0,(getmaxx(stdscr)-strlen("_ DRIVE STATUS _"))/2,"%c DRIVE STATUS %c",(unsigned char)185,(unsigned char)204);

					for(int a=1;a<getmaxy(sub)-1; a++)
					{
							for(int b=1;b<getmaxx(sub)-1;b++)
									mvwprintw(sub,a,b," ");
					}
			wrefresh(sub);



			mvwprintw(sub,5,10,"DRIVE A: %s ",drva);
			mvwprintw(sub,7,10,"DRIVE C: %s",drvc);
			mvwprintw(sub,9,10,"DRIVE D: %s",drvd);
			mvwprintw(sub,11,10,"DRIVE Z: %s",drvz);
			mvwprintw(sub,13,10,"DRIVE E: %s",drve);

			mvwprintw(sub,15,20,"%d Drives Are Down",conf);
			mvwprintw(sub,17,20,"Drives: %s",drvl);

			wrefresh(sub);
			wattroff(sub,COLOR_PAIR(2));

			mvwprintw(msg,12,10,"You Can Continue(It Won't Work!!)");
			mvwprintw(msg,14,10,"Or You Can Just Exit And Edit The File, Run Make BOXEmu And Things Will Work!!");
			mvwprintw(msg,15,10,"\'r\' to rescan");
			mvwprintw(msg,getmaxy(msg)-1,(getmaxx(msg)-strlen("_ Space To Continue _"))/2,"%c Space To Continue %c",(unsigned char)185,(unsigned char)204);

			wrefresh(msg);

			keypad(msg,true);

			wattroff(msg,COLOR_PAIR(2));

			int inc=getch();

			if(inc==32)
			{
						for(int a=1;a<getmaxy(hw)-1; a++)
						{
								for(int b=1;b<getmaxx(hw)-1;b++)
										mvwprintw(msg,a,b," ");
						}
				wrefresh(msg);
				sprintf(drv," ");
			}if(inc=='r'){
				main(argc,argv);
				return 0;
			}else{
				echo();
				endwin();
				return -1;
			}


		}
		else{
			conf=0;
		}

		switch(dv){
			case 1:
				sprintf(drv,"Z:\\");
				chdir(drvz);
				dv=0;
				break;
			case 2:
				sprintf(drv,"A:\\");
				chdir(drva);
				dv=0;
				break;
			case 3:
				sprintf(drv,"C:\\");
				chdir(drvc);
				dv=0;
				break;
			case 4:
				sprintf(drv,"D:\\");
				chdir(drvd);
				dv=0;
				break;
			case 5:
				sprintf(drv,"E:\\");
				chdir(drve);
				dv=0;
				break;
			default:
				dv=0;
				chdir(pwd);
				break;

		}
		if(!strcmp(s,"LL")||!strcmp(s,"ll")){
			system("rm -rf ./out");
			system("ls -al >> ./out");
			system("dog ./out");

			clear();
			i=0;
		}
        	if(strcmp(s,"HELP")==false || strcmp(s,"help")==false)
        	{
                       printw("LL - like dir but shows file permissions\nMKDIR - Create Directory\nRUN - run a command with parameters on the computer\nWHEREDRV - show where the drives are located\nGCC - compile c programs\nNANO - The system file editor\nTOUCH - create new file\nVER - Display Version\nFIND - find files with the same name / letter \nRM - Remove File\nDIR - Display Files In Directory\nTYPE - read file\nARCHIVE - File Search Engine\nCD - Change Current Directory\nHELP - ....... you just called this one\nEXIT - ...It's quite obvious\nCLS - Will Clear The screen\nPWD - Print Current Directory\nCONSOLE - Run Command On Console\nWIN - Will Run Desktop\nEDIT - A Full Screen Editor\nINTRO - BOXEmu Introduction\nEMACS - RUN EMACS\nPAUSE - Will Wait For A Keystroke\n");
                       i=i+25;

        	}if(!strcmp(s,"INTRO")||!strcmp(s,"intro")){
			endwin();
			system("~/bin/cimg ~/.BOXEmu/intro.img");
		}/*if(!strcmp(s,"RESCAN")||!strcmp(s,"rescan")){
			goto scan;
		}*/

		if(strcmp(s,"CALL")==false || strcmp(s,"call")==false){
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
		}if(!strcmp(s,"MKDIR")||!strcmp(s,"mkdir")){
			scanw("%s",str);
			int mk=mkdir(str,S_IROTH);
			if(mk == EOF){
				printw("Something Went Wrong: %d",EOF);
			}
			i=i+3;
		}if(!strcmp(s,"RUN")||!strcmp(s,"run")){

			scanw("%s %s",s,str);
			sprintf(run,"%s/%s %s",pwd,s,str);

			endwin();
			system(run);

			initscr();
			getch();
			clear();

			sprintf(str," ");

			i=0;
		}if(strcmp(s,"EXIT")==false || strcmp(s, "exit")==false)
                {
                        break;
                }if(strcmp(s,"CLS")==false || strcmp(s,"cls")==false)
                {
                        i=0;
                        clear();
                }if(!strcmp(s,"WHEREDRV")||!strcmp(s,"wheredrv")){
			div=0;

			for(int a=0;a<35;a++){
				printw("%c",(unsigned char)205);
				if(a == 17)
					printw("%c",(unsigned char)206);
			}
			printw("\nDRIVES");
			for(int b=6;b<28;b++){
				printw(" ");
				if(b == 17){
					printw("%c",(unsigned char)186);
				}
			}
			printw("WHERE\n");
			for(int c=0;c<35;c++){
				printw("%c",(unsigned char)205);
				if(c==17){
					printw("%c",(unsigned char)206);
				}
			}
			for(int y=0;y<5;y++){
				div++;
				printw("\n");
				printw("DRIVE %c",drivs[y]);
				for(int x=0;x<15;x++){
					printw(" ");
					if(x == 10){
						printw("%c",(unsigned char)186);
					}
				}
				switch(div){
					case 1:
						printw("%s",drva);
						break;
					case 2:
						printw("%s",drvc);
						break;
					case 3:
						printw("%s",drvd);
						break;
					case 4:
						printw("%s",drve);
						break;
					case 5:
						printw("%s",drvz);
						break;
					default:
						break;
				}
			}
			printw("\n");
			for(int j=0;j<35;j++){
				printw("%c",(unsigned char)205);
				if(j==17){
					printw("%c",(unsigned char)206);
				}
			}
			printw("\n");
			i=i+11;
		}
		if(strcmp(s,"CONSOLE")==false || strcmp(s,"console")==false)
		{
			sprintf(s," ");
			scanw("%s %s",s,str);
			endwin();

			sprintf(run,"%s %s",s,str);

			system(run);

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
			sprintf(mdr,"%s",pwd);
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
			i=0;
		}if(strcmp(s,"VER") == false || strcmp(s,"ver")==false){
			printw("BoxEmu v0.6.2 alpha\n\n\t SUPER SIX");
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
		}if(strcmp(s,"emacs")==false || strcmp(s,"EMACS")==false){
			system("emacs");
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
		}if(!strcmp(s,"Z:") || !strcmp(s,"z:")){
			sprintf(drv,"Z:\\");
			int cd=chdir(drvz);
			if(cd == -1){
				return -1;
			}
			dv=1;
		}if(!strcmp(s,"A:") || !strcmp(s,"a:")){
                        sprintf(drv,"A:\\");
                        int cd=chdir(drva);
                        if(cd == -1){
                                return -1;
                        }
			dv=2;
                }if(!strcmp(s,"C:") || !strcmp(s,"c:")){
                        sprintf(drv,"C:\\");
                        int cd=chdir(drvc);
                        if(cd == -1){
                                return -1;
                        }
			dv=3;
                }if(!strcmp(s,"D:") || !strcmp(s,"d:")){
                        sprintf(drv,"D:\\");
                        int cd=chdir(drvd);
                        if(cd == -1){
                                return -1;
                        }
			dv=4;
                }if(!strcmp(s,"E:")||!strcmp(s,"e:")){
			sprintf(drv,"E:\\");
			int cd=chdir(drve);
			if(cd == -1){
				return -1;
			}
			dv=5;
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
int crt(const char *s){
	DIR *dp;

	if((dp=opendir(s))==NULL)
	{
		int stat=mkdir(s,S_IROTH);
		if(stat==EOF)
		{
			return 1;
		}
	}else{
		return 0;
	}
}
