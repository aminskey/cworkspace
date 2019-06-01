#include<stdio.h>
#include<ncurses.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int c=0x0;
	int nl=5;

	FILE *fp=fopen(argv[1],"r");

	initscr();
	cbreak();
	noecho();


	if(fp == NULL)
		perror("Cannot Access File");


	while(!feof(fp))
	{
		fscanf(fp,"%x",&c);
		printw("%c",(unsigned char)c);
		if(c == 0xa)
			nl++;

		if(nl >= getmaxy(stdscr)-1){
			getch();
			clear();
			nl=0;	
		}
		delay_output(10);
		refresh();		
	
	}
	int stat=0;
	if(strcmp(argv[1],".spw")==false)
	{
		stat=remove(argv[1]);
	}

	if(stat == 0){
		
	}else{
		clear();
		perror("Cannot Remove Encryption file");
	}



	getch();
	endwin();
	return 0;	
}
