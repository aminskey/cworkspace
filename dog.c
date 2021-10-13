#include<time.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<ncurses.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/sysmacros.h>

int main(int argc, char *argv[]){

    struct stat statbuf;

    char fileData[6][500];

    if(stat(argv[1],&statbuf)!=-1){

	sprintf(fileData[0], "ID of containing device [%lx, %x]",(long) major(statbuf.st_dev), minor(statbuf.st_dev));
	sprintf(fileData[2], "Inode number: %ld - Mode: %lo",(long) statbuf.st_ino,(unsigned long)statbuf.st_mode);
	sprintf(fileData[3], "Ownership: User ID=%ld Group ID=%ld",(long) statbuf.st_uid, (long) statbuf.st_gid);
	sprintf(fileData[4], "Number of blocks allocated: %ld",(unsigned long)statbuf.st_blocks);
	sprintf(fileData[5], "Time of last access: %s  Time of last modification: %s  Time of last status change: %s",ctime(&statbuf.st_atime),ctime(&statbuf.st_mtime),ctime(&statbuf.st_ctime));

	char ch;
	int nl=0;
	FILE *fp=fopen(argv[1],"r+");

	while(!feof(fp)){
		ch=fgetc(fp);
		if(ch=='\n'){
			nl++;
		}
	}

	sprintf(fileData[1], "Size of file: %ld - Number of lines: %d",(long)statbuf.st_size,nl);
	fclose(fp);

    }else{
	perror("File not found");
	return -1;
    }

    initscr();
    noecho();
    cbreak();

    int d=0;

    int ln=0;

    char file;

    FILE *fp=fopen(argv[1],"r");

    WINDOW *win=newwin(15,70,10,100);

    if(fp==NULL){
        refresh();
        box(win,0,0);
        curs_set(0);

        wattron(win,A_REVERSE);

        mvwprintw(win,1,1,"\"%s\"::FILE NOT FOUND",argv[1]);

        wattroff(win,A_REVERSE);
        wrefresh(win);
    }else{
        while(!feof(fp))
        {

            file = fgetc(fp);

            printw("%c",file);

	    if(file == 10){
		ln++;
	    	delay_output(10);
		refresh();
	    }


	    if(ln  >= getmaxy(stdscr)){
                getch();
		clear();
		ln=0;
	    }

	}
        printw("\b");

        curs_set(0);

	refresh();

        mvwprintw(win,2,(getmaxx(win) - strlen(argv[1]))/2,"%s",argv[1]);

	for(int i=0; i<6; i++){
		mvwprintw(win, i+4, 2, "%s", fileData[i]);
	}

        refresh();
        box(win,0,0);

	mvwprintw(win, 0, (getmaxx(win) - strlen(" Status Report "))/2, " Status Report ");
	mvwaddch(win, 0, (getmaxx(win) - strlen(" Status Report "))/2 - 1, 117|A_ALTCHARSET);
	mvwaddch(win, 0, (getmaxx(win) - strlen(" Status Report "))/2 + strlen(" Status Report "), 116|A_ALTCHARSET);

        wrefresh(win);

    }
    fclose(fp);
    getch();
    endwin();

    return 0;
}
