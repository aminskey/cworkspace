#include<stdio.h>
#include<ncurses.h>
#include<time.h>

extern void wpaint();

extern const char home[];

void clock(WINDOW *src){
	char str[50];
	sprintf(str,"%s/.Mzdos/dat",home);

	FILE *fp=fopen(str,"r+");

	time_t *time;
	struct tm *loctime;

	time(&time);
	loctime=localtime(&time);


	int c=wgetch(src);
	while(c==0){
		mvwprintw(src,1,1,"%dh:%dmin:%d",loctime->tm_hour,loctime->tm_min,loctime->tm_sec);
	}

	

}
