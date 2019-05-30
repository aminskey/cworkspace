#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>


void *sound(void)
{
	
	system("afplay ~/Downloads/Elevator.wav");

}

char *ship[]={
	"			   ",
	"		#########  ",
        "		      #### ",
	"	################## ",
	"######################### ",
        "	################## ",
	"		      #### ",
	"		#########  ",
	"			   ",
};

char *elevator[]={
	"          ",
	"##########",
	"#   ##   #",
	"#   ##   #",
	"#   ##   #",
	"#   ##   #",
	"##########"
};


int main(void)
{
	initscr();
	noecho();
	cbreak();

	pthread_t thr;
	WINDOW *el=newwin(10,20,0,0);
	WINDOW *ans=newwin(10,40,(getmaxy(stdscr)-10)/2,(getmaxx(stdscr)-40)/2);

	char s[100];
	char s2[100];


	printw("Date: 26/12/3012\nLocation: Somewhere\n");
	mvprintw(4,0,"You are sleeping in your bed\n");
	printw("Inside a spaceship, ...\n");
	printw("[Snoring]....\n");

	mvprintw(getmaxy(stdscr)/2,(getmaxx(stdscr)-strlen("Press any Key to continue"))/2,"Press Any Key To Continue");
	getch();
	clear();

	refresh();

	for(int i=0;i<7;i++)
	{
		wprintw(el,"%s\n",elevator[i]);
	}

	pthread_create(&thr,NULL,sound,NULL);
	for(int j=0;j<getmaxy(stdscr)-6;j++)
	{
		
		mvwin(el,j,0);
		wrefresh(el);
		delay_output(100);
		
	}
	pthread_cancel(thr);
	clear();

	printw("someone: wake up\n\nYou Get disturbed And You Reply [Zzzz, Go Away or ...]\n");

	wattron(ans,A_REVERSE);

	refresh();
	box(ans,0,0);

	wattroff(ans,A_REVERSE);
	

	mvwprintw(ans,0,(getmaxx(ans)-strlen("Answer"))/2 ,"Answer");
	echo();
	mvwscanw(ans,4,8,"%s %s",s,s2);
	noecho();
	wrefresh(ans);

	attron(A_REVERSE);
	if(strcmp(s,"Zzzz")==false)
	{
		wprintw(stdscr,"Wake Up!\nCaptain\'s Calling");
	}else if(strcmp(s,"Go")==false && strcmp(s2,"Away")==false)
	{
		wprintw(stdscr,"Captain\'s Calling");
	}else{
		wprintw(stdscr,"Quit that nonsense, Captain\'s Calling\n");
	}
	attroff(A_REVERSE);
	wrefresh(ans);
	getch();
	clear();

	printw("Captain:");
	attron(A_REVERSE);
	printw("Our control system is being Hacked\n");
	getch();
	system(" ~/cworkspace/dog /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ncurses.h && ~/cworkspace/dog /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h && ~/cworkspace/dog /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdlib.h");
	clear();

	printw("The Engine Exploded");
	attroff(A_REVERSE);		
	getch();
	clear();

again:
	printw("You have a cargo ship on dock it can withstand 100 tons\npeople are screaming and shouting; panicing.\nWill you save the people or panic?\n");

	wclear(ans);

	refresh();
	wattron(ans,A_REVERSE);
	box(ans,0,0);
	wattroff(ans,A_REVERSE);
	wrefresh(ans);

	mvwprintw(ans,0,(getmaxx(ans)-strlen("Answer"))/2,"Answer");

	echo();

	mvwscanw(ans,4,8,"%s",s);
	if(strcmp(s,"panic")==false)
	{
		goto end;
	}else if(strcmp(s,"save")==false){
		wprintw(stdscr,"\nGood\n");
	}else{
		clear();
		goto again;
	}
	noecho();
end:
	clear();
	attron(A_REVERSE);
	for(int i=0;i<getmaxy(stdscr);i++)
		for(int j=0;j<getmaxx(stdscr);j++)
			mvprintw(i,j," ");

	attroff(A_REVERSE);
	refresh();

	wclear(ans);

	box(ans,0,0);
	mvwprintw(ans,(getmaxy(ans)/2)-1,(getmaxx(ans)-strlen("G A M E     O V E R"))/2,"G A M E     O V E R");
	wrefresh(ans);
	getch();
	endwin();
	return 0;
}
