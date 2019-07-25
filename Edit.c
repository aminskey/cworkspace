#include<ncurses.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>


int main(void)
{


	initscr();
	cbreak();
	noecho();


	curs_set(0);
	start_color();

	init_pair(1,COLOR_WHITE, COLOR_BLUE);
	init_pair(2,COLOR_WHITE, COLOR_RED);
	init_pair(3,COLOR_WHITE, COLOR_GREEN);
	init_pair(4,COLOR_BLACK, COLOR_BLUE);


	char fn[2020];

	MEVENT mvnt;

	mousemask(ALL_MOUSE_EVENTS, NULL);




	WINDOW *nf=newwin(8,50,getmaxy(stdscr)/2,(getmaxx(stdscr)-30)/2);
	WINDOW *ed=newwin(getmaxy(stdscr)-2,getmaxx(stdscr)-2,1,1);
	WINDOW *dt=derwin(ed,getmaxy(ed)-2,getmaxx(ed)-2,1,1);
	WINDOW *cmp=newwin(10,40,10,30);

	clear();
	attron(COLOR_PAIR(1));

	for(int i=0;i<getmaxy(stdscr);i++)
	{
		for(int j=0;j<getmaxx(stdscr);j++)
			mvprintw(i,j," ");
	}

	box(stdscr,0,0);

	mvprintw(0,(getmaxx(stdscr)-strlen("  Project editor  "))/2,"%c Project Editor %c", (unsigned char)185, (unsigned char)204);

	mvprintw(getmaxy(stdscr)-1,(getmaxx(stdscr)-strlen("F10 - SAVE, COMPILE & RUN"))/6,"F10 - Save, Compile & Run");
	mvprintw(getmaxy(stdscr)-1,((getmaxx(stdscr)-strlen("F9 - Save and Exit"))/3)+3,"F9 - Save And Exit");
	mvprintw(getmaxy(stdscr)-1,(getmaxx(stdscr)-strlen("F1 - Exit"))/2,"F1 - Exit");
	mvprintw(getmaxy(stdscr)-1,(getmaxx(stdscr)-strlen("F5 - New File"))/2 + getmaxx(stdscr)/4, "F5 - New File");
	mvprintw(getmaxy(stdscr)-1,(getmaxx(stdscr)-strlen("F6 - Save"))/2 + getmaxx(stdscr)/8, "F6 - Save");

	attroff(COLOR_PAIR(1));

start:

	wattron(nf,COLOR_PAIR(2));

	for(int i=0;i<getmaxy(nf);i++)
		for(int j=0;j<getmaxx(nf);j++)
			mvwprintw(nf,i,j," ");

	refresh();
	box(nf,0,0);

	char nm[2019];
	char path[2018];

	mvwprintw(nf,2,3," Name:");
	for(int i=9;i<29;i++)
		mvwaddch(nf,3,i,ACS_S1);


	mvwprintw(nf,4,1,"Address:");
        for(int i=9;i<29;i++)
                mvwaddch(nf,5,i,ACS_S1);


	echo();

	mvwscanw(nf,2,9,"%s",nm);
	mvwscanw(nf,4,9,"%s",path);
	noecho();

	sprintf(fn,"%s/%s",path,nm);

	wclear(nf);

	wattron(nf,COLOR_PAIR(2));

	for(int i=0;i<getmaxy(nf);i++)
		for(int j=0;j<getmaxx(nf);j++)
			mvwprintw(nf,i,j," ");

	refresh();
	box(nf,0,0);

	mvwprintw(nf,2,4,"%s; Is Okay?",fn);
	mvwprintw(nf,4,4,"F1 FOR YES");
	mvwprintw(nf,4,20,"F2 FOR NO");


	wattroff(nf,COLOR_PAIR(2));

	noecho();

	keypad(nf, true);
	int c=0;
	while(1){
		c=wgetch(nf);
		if(c == KEY_F(1))
			break;
		if(c == KEY_F(2)){
			wclear(nf);
			break;
		}

	}
	if(c == KEY_F(2))
	{
		wattron(nf,COLOR_PAIR(2));
		for(int i=0;i<getmaxy(nf);i++)
			for(int j=0;j<getmaxx(nf);j++)
				mvwprintw(nf,i,j," ");

		refresh();
		box(nf,0,0);

		mvwprintw(nf,4,4,"Do You Want To Quit:");
		mvwprintw(nf,6,6,"F1 FOR YES");
		mvwprintw(nf,6,20,"F2 FOR NO");

		while(1){
			c=wgetch(nf);
			if(c == KEY_F(1))
				goto no;
			if(c == KEY_F(2))
			{
				wclear(nf);
				goto start;
			}
		}

		wattroff(nf,COLOR_PAIR(2));
	}
	wrefresh(nf);
	int j=0;

	if(c == KEY_F(1))
	{


		wattron(nf,COLOR_PAIR(1));
		for(int i=0;i<getmaxy(nf);i++)
			for(int j=0;j<getmaxx(nf);j++)
				mvwprintw(nf,i,j," ");
		wattroff(nf,COLOR_PAIR(1));

		wrefresh(nf);
		delwin(nf);
		refresh();

		wattron(ed,COLOR_PAIR(2));
		for(int i=0;i<getmaxy(ed);i++)
			for(int j=0;j<getmaxx(ed);j++)
				mvwprintw(ed,i,j," ");

		box(ed,0,0);

		mvwprintw(ed,0,(getmaxx(ed)-strlen(nm))/2,"%s",nm);
		wrefresh(ed);

		int d=0;
		int x=0,y=0;
		wmove(dt,mvnt.y,mvnt.x);
		keypad(dt,true);
		char *s;

		int fy=0,fx=0;

		FILE *frp=fopen(fn,"r");


		wattron(dt,COLOR_PAIR(2));

		if(frp == NULL){
			fclose(frp);
			goto loop;

		}
		int c=0;
		/*=fgetc(frp);*/


		rewind(frp);
		wmove(dt,0,0);
		while(!feof(frp)){

			c=fgetc(frp);


			if(c == '\n'){
				++fy;
				fx=0;
			}
			mvwprintw(dt,fy-1,fx,"%c",c);
                        ++fx;

		}

		fclose(frp);
		int fc=0;

		for(int i=0;i<getmaxy(dt);i++){
			for(int j=0;j<getmaxx(dt);j++)
               		{
                		fc=winch(dt);
                        	mvwprintw(dt,i,j,"%c",fc);
                	}
		}


		wattroff(dt, COLOR_PAIR(2));

		wmove(dt,0,0);

loop:
		while(1)
		{

			noecho();
			curs_set(1);
			d=wgetch(dt);
			wattron(dt,COLOR_PAIR(2));


			/*KEY_BACKSPACE FOR LINUX AND OTHERS, KEY_DC FOR MAC*/

			if(d == 127 || d == KEY_DC || d == 7 || d == KEY_BACKSPACE){

				mvwprintw(dt,y,x," ");
				wmove(dt,y,x--);

				wrefresh(dt);

			}
			else if(d == 10)
			{
				y++;
				x=0;
			}

			else if(d == KEY_F(10)){
				break;
			}else if(d == KEY_F(1)){
				break;
			}else if(d == KEY_F(9)){
				break;
			}else if(d == KEY_F(5)){
				break;
			}else if(d == KEY_DOWN)
			{
				wmove(dt,++y,x);
				wrefresh(dt);
			}
			else if(d == KEY_UP)
			{
				wmove(dt,--y,x);
				wrefresh(dt);
			}
			else if(d == KEY_LEFT)
			{
				wmove(dt,y,--x);
				wrefresh(dt);
			}
			else if(d == KEY_RIGHT)
			{
				wmove(dt,y,++x);
				wrefresh(dt);
			}
/* 	 		else if(d == KEY_MOUSE)
			{
				if(getmouse(&mvnt) == OK)
				{
					wmove(dt,y=mvnt.y - 2,x=mvnt.x - 2);
					wrefresh(dt);
				}
			}
*/			else if(d == 9)
				wmove(dt,y,x=x+8);

			else{
				x++;
				wprintw(dt,"%c",d);
			}
			wattroff(dt,COLOR_PAIR(2));
                	wattroff(ed,COLOR_PAIR(2));

			wrefresh(dt);
		}
		int t=0;

		// wattron(dt,COLOR_PAIR(3));


		wmove(dt,0,0);
		if(d == KEY_F(10)){
			FILE *fp=fopen(fn,"w+");

			rewind(fp);

			char str[100];
			char comp[200];
			char run[100];
			char jrun[100];
			char nasmrun[100];


			for(int i=0;i<getmaxy(dt);i++)
			{

				fprintf(fp,"\n");

				for(int j=0;j<getmaxx(dt);j++)
				{
					t=mvwinch(dt,i,j);
					fprintf(fp,"%c",t);
					mvwprintw(dt,i,j,"%c",t);
				}
				wrefresh(ed);
				wrefresh(dt);

			}

			fclose(fp);

			wattron(cmp, COLOR_PAIR(1));

			for(int i=0;i<getmaxy(cmp);i++)
				for(int j=0;j<getmaxx(cmp);j++)
					mvwprintw(cmp,i,j," ");


			sprintf(str,"%c Compile / Run %s %c",(unsigned char)240,nm,(unsigned char)240);

			refresh();
			box(cmp,0,0);
			wrefresh(cmp);

			mvwprintw(cmp,0,(getmaxx(cmp)-strlen(str))/2,"%s",str);
			mvwprintw(cmp,2,(getmaxx(cmp)-strlen("Compiler / Interpreter:"))/2, "Compiler / Interpreter:");
			echo();


			mvwscanw(cmp,3,(getmaxx(cmp)-strlen("Compiler"))/3,"%s",comp);
			if(strcmp(comp,"NoCompile")==false){
				// Do nothing
			}else{
				clear();
				refresh();
				sprintf(run,"%s %s", comp, fn);
				echo();
				if(strcmp(comp,"gcc")==false)
					sprintf(run,"%s %s -lncurses",comp, fn);
				if(strcmp(comp,"g++")==false)
					sprintf(run,"%s %s -lncurses",comp, fn);
				if(strcmp(comp,"nasm")==false)
					sprintf(run,"%s %s -o %s",comp, fn, fn - 2);


				system("clear");
				endwin();
				system(run);


				if(strcmp(comp,"gcc")==false)
					system("./a.out");
				if(strcmp(comp,"g++")==false)
					system("./a.out");
				if(strcmp(comp,"javac")==false)
				{
					sprintf(jrun,"java %s",fn-5);
					system(jrun);
				}
				if(strcmp(comp,"nasm")==false)
				{
					sprintf(nasmrun,"ld %s.o -o %s ; ./%s",fn-2, fn - 2, fn-2);
					system(nasmrun);


				}
				sleep(1);
				usleep(500);
			}

			wattroff(cmp,COLOR_PAIR(1));
			wrefresh(cmp);

			initscr();
			noecho();
			cbreak();

			clear();

			mvprintw(getmaxy(stdscr)/2,(getmaxx(stdscr)-strlen("Press \'r\' to restart\t\tPress Anything Else To Continue"))/2,"Press \'r\' to restart\t\tPress Anything Else To Continue");
			noecho();
			int ch=getch();
			if(ch=='r')
			{
				endwin();
				main();
			}

			else{

			}

		}if(d == KEY_F(9))
		{
			FILE *fp=fopen(fn,"w+");
			rewind(fp);

			for(int i=0;i<getmaxy(dt);i++)
                        {

                                fprintf(fp,"\n");

                                for(int j=0;j<getmaxx(dt);j++)
                                {
                                        t=winch(dt);
                                        fprintf(fp,"%c",t);
                                        mvwprintw(dt,i,j,"%c",t);
                                }
                                wrefresh(ed);
                                wrefresh(dt);

                        }

                        fclose(fp);
		}
		if(d == KEY_F(5))
		{
			endwin();
			main();
		}
		else{

		}

		//wattroff(dt,COLOR_PAIR(3));


	}

	sleep(1);

no:
	endwin();

	return 0;
}
