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

    if(stat(argv[1],&statbuf)!=-1){

	char ch;
	int nl=0;
	FILE *fp=fopen(argv[1],"r+");

	while(!feof(fp)){
		ch=fgetc(fp);
		if(ch=='\n'){
			nl++;
		}
	}

	printf("ID of containing device [%lx, %x]\n",(long) major(statbuf.st_dev), minor(statbuf.st_dev));
	printf("Size of file: %ld\nNumber of lines: %d\n",(long)statbuf.st_size,nl);
	printf("Inode number: %ld\nMode: %lo\n",(long) statbuf.st_ino,(unsigned long)statbuf.st_mode);
	printf("Ownership: User ID=%ld Group ID=%ld\n",(long) statbuf.st_uid, (long) statbuf.st_gid);
	printf("Number of blocks allocated: %ld\n",(unsigned long)statbuf.st_blocks);
	printf("Time of last acces: %s\nTime of last modification: %s\nTime of last status change: %s",ctime(&statbuf.st_atime),ctime(&statbuf.st_mtime),ctime(&statbuf.st_ctime));

	fclose(fp);

    }else{
	perror("File not found");
	return -1;
    }

    getchar();

    initscr();
    noecho();
    cbreak();        

    int d=0;

    int ln=0;

    char file;

    FILE *fp=fopen(argv[1],"r");

    WINDOW *win=newwin(9,70,10,100);

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
            
            file=fgetc(fp);
            printw("%c",file);
	   
	    if(file == 10){
		ln++;
	    	delay_output(10);
		refresh();
	    }


	    if(ln  == getmaxy(stdscr)){
                getch();
		clear();
		ln=0;
	    }            

	}
        printw("\b");

        curs_set(0);

        refresh();
        box(win,0,0);
        
        
        wattron(win,A_REVERSE);
        mvwprintw(win,2,(getmaxx(win) - strlen(argv[1]))/2,"FILE :: %s",argv[1]);
        wattroff(win,A_REVERSE);
        
        wrefresh(win);
        
        
        
        
    }
    fclose(fp);
    getch();
    endwin();

    return 0;
}
