#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <acorn.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <ctype.h>



int main(int argc, char *argv[]){

	char drvs[30];
	char usname[30];
	char head[100];
	char pas[20];


#if __APPLE__
	char headName[10]="/Users";
#elif __linux__
	char headName[10]="/home";
#endif

	char drives[5][50];
	char drvNames[6]="ACDEZ";
	char muser[100];
	char mdesk[120];
	char msg[]="replace the old config file with the new one in cworkspace/MzDesk/libfuncs";


	char config[100];
	char login[200];
	char data[200];

	char user[25];

	int errnums[6];
	int i=0;

	int f=0,b=0;

	struct stat *statbuf;

	initscr();
	cbreak();
	noecho();

	curs_set(0);

	start_color();
	init_pair(1,COLOR_WHITE,COLOR_BLUE);
	init_pair(2,COLOR_BLACK,COLOR_WHITE);
	init_pair(3,COLOR_WHITE,COLOR_BLACK);
	init_pair(4,COLOR_WHITE,COLOR_GREEN);

	WINDOW *setup=newwin(MAXY/2,MAXX/2,MAXY/2-MAXY/4,MAXX/2-MAXX/4);
	WINDOW *shdw=newwin(getmaxy(setup),getmaxx(setup),getbegy(setup)+1,getbegx(setup)+2);

	WINDOW *sub=derwin(setup,3,18,(getmaxy(setup)-3)/2,5);

	paint(32,1);

	refresh();
	wpaint(shdw,32,3);
	wrefresh(shdw);


	wpaint(setup,32,2);

	refresh();
	wattron(setup,COLOR_PAIR(2));

	box(setup,0,0);
	mvwprintw(setup,0,(getmaxx(setup)-strlen(argv[0])-2)/2,"| %s |",argv[0]);


	curs_set(1);
	echo();

	mvwprintw(setup,2,2,"What is your username:");
	for(int i=2+strlen("What is your username:");i<16+strlen("What is your username:");i++){
		mvwaddch(setup,3,i,111|A_ALTCHARSET);
	}

	mvwprintw(setup,4,2,"Where do you want you to store your drives:");
	for(int i=2+strlen("Where do you want your to store your drives:");i<26+strlen("Where do you want to store your drives:");i++){
		mvwaddch(setup,5,i,111|A_ALTCHARSET);
	}

	mvwprintw(setup,6,2,"Choose fore- and background colors (use numbers):");
        for(int i=2+strlen("Choose fore- and background colors (use numbers):");i<16+strlen("Choose fore- and background colors (use numbers):");i++){
                mvwaddch(setup,7,i,111|A_ALTCHARSET);
        }

	mvwprintw(setup,8,2,"New Username:");
	for(int i=2+strlen("New Username:");i<16+strlen("New Username:");i++){
		mvwaddch(setup,9,i,111|A_ALTCHARSET);
	}
	mvwprintw(setup,10,2,"New Password:");
	for(int i=2+strlen("New Password:");i<16+strlen("New Password:");i++){
		mvwaddch(setup,11,i,111|A_ALTCHARSET);
	}


	mvwscanw(setup,2,2+strlen("What is your username: "),"%s",usname);
	mvwscanw(setup,4,6+strlen("Where do you want to store your drives: "),"%s",drvs);
	mvwscanw(setup,6,6+strlen("Choose fore- and background colors (use numbers): "),"%d %d",&f,&b);
	mvwscanw(setup,8,2+strlen("New Username: "),"%s",user);


	noecho();
	mvwscanw(setup,10,2+strlen("New Password: "),"%s",pas);



	wattroff(setup,COLOR_PAIR(2));
	wrefresh(setup);

	sprintf(head,"%s/%s/%s",headName, usname,drvs);
	if(mkdir(head,0777)==-1){
		bluescreen(strerror(errno));
	}

	wattron(sub,COLOR_PAIR(4));

	box(sub,0,0);
	wattroff(sub,COLOR_PAIR(4));
	wrefresh(sub);

	for(i=0;i<5;i++){

		sprintf(drives[i],"%s/%c",head,drvNames[i]);
		if(mkdir(drives[i],0777)==-1){
			bluescreen(strerror(errno));
			errnums[i]=errno;
		}

		wattron(sub,COLOR_PAIR(4));
		mvwprintw(sub,1,1+i*2,"##");
		wattroff(sub,COLOR_PAIR(4));
		wrefresh(sub);

		sleep(1);
	}


	sprintf(muser, "%s/%s",drives[1], user);
	sprintf(mdesk,"%s/Desktop",muser);

	if(mkdir(muser,0777)==-1){
		bluescreen(strerror(errno));
		endwin();
		exit(-1);
	}
        wattron(sub,COLOR_PAIR(4));
        mvwprintw(sub,1,(i+=3)+1,"##");
        wattroff(sub,COLOR_PAIR(4));
        wrefresh(sub);
	sleep(1);

	if(mkdir(mdesk,0777)==-1){
		bluescreen(strerror(errno));
		endwin();
		exit(-1);
	}

        wattron(sub,COLOR_PAIR(4));
        mvwprintw(sub,1,(i+=2)+1,"##");
        wattroff(sub,COLOR_PAIR(4));
        wrefresh(sub);
	sleep(1);

	sprintf(config,"%s/drvConf.c",head);
	if(creat(config,0777)==-1){
		bluescreen(strerror(errno));
	}

	FILE *fp=fopen(config,"r+");
	if(fp == NULL){
		bluescreen(strerror(errno));
		endwin();
		exit(-1);
	}

	rewind(fp);

	for(int j=0;j<5;j++){
		fprintf(fp,"char drv%c[50] = \"%s\";\n",tolower(drvNames[j]),drives[j]);
	}
	fprintf(fp,"char home[50] = \"/home/%s\";\nchar drives[6] = \"ACDEZ\";",usname);
	fclose(fp);

        wattron(sub,COLOR_PAIR(4));
        mvwprintw(sub,1,(i+=2)+1,"##");
        wattroff(sub,COLOR_PAIR(4));
        wrefresh(sub);
	sleep(1);

	sprintf(login,"%s/A/login",head);
	if(creat(login,0777)==-1){

	}

	FILE *log=fopen(login,"r+");
	if(fp == NULL){
		bluescreen(strerror(errno));
		endwin();
		exit(-1);
	}

	fprintf(log,"%s %s", user, pas);
	fclose(log);

	sprintf(data,"%s/A/dat",head);
	if(creat(data,0777)==-1){

	}

	FILE *fdata=fopen(data,"r+");
	if(fdata == NULL){
		bluescreen(strerror(errno));
		endwin();
		printf("Mission Abort\n\a");
		exit(-1);
	}

	fprintf(fdata,"32 10 %d %d", f, b);
	fclose(fdata);

        wattron(sub,COLOR_PAIR(4));
        mvwprintw(sub,1,(i+=2)+1,"##");
        wattroff(sub,COLOR_PAIR(4));
        wrefresh(sub);
	sleep(1);


	wattron(setup,COLOR_PAIR(2));
	mvwprintw(setup,20,(getmaxx(setup)-strlen(msg))/2,"%s",msg);
	wattroff(setup,COLOR_PAIR(2));
	wrefresh(setup);

	getch();
	clear();
	endwin();

	for(int k=0;k<5;k++){
		if(errnums[k]>=131 || errnums[k]<=0)
			printf("On Drive %c errornum: %10d - error report: Succes\n",drvNames[k],errnums[k]);
		else{
			printf("On Drive %c errornum: %10d - error report: %s\n",drvNames[k],errnums[k],strerror(errnums[k]));
		}
	}
	return 0;
}
