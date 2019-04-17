#include <stdio.h>
#include <ncurses.h>
#include <dirent.h>
#include <unistd.h>

int main() {
   char pwd[2000];
    initscr();
    cbreak();
    DIR *dp;
    struct dirent *dir;

    getcwd(pwd,sizeof(pwd));
    dp=opendir(pwd);
    if(dp==NULL){
        printw("UNFORTUNETLY THERE IS A PROBLEM");
    }else{
        while((dir=readdir(dp))!=NULL){
            printw("%s\n",dir->d_name);
        }
    }


    getch();
    endwin();
}