#include<stdio.h>                                                                                                                                                         
#include<ncurses.h>                                                                                                                                                        
#include<string.h>

int main(void){                                                                                                                                                                                                                           
                                                                                                                                                                                                                                          
        initscr();                                                                                                                                                                                                                        
        cbreak();                                                                                                                                                                                                                         
        noecho();                                                                                                                                                                                                                         
                                                                                                                                                                                                                                          
        start_color();                                                                                                                                                                                                                    
        init_pair(1, COLOR_WHITE, COLOR_BLUE);                                                                                                                                                                                            
   
	attron(COLOR_PAIR(1));
                                                                                                                                                                                                                                       
        for(int i=0;i<getmaxy(stdscr);i++){                                                                                                                                                                                               
                for(int j=0;j<getmaxx(stdscr);j++)                                                                                                                                                                                        
       			mvprintw(i,j," ");                                                                                                                                                                                                                                   
	}        
                                                                                                                                                                                                                                  
        mvprintw(getmaxy(stdscr)/2,(getmaxx(stdscr)-strlen("Hello And Welcome To The CWorkspace"))/2,"Hello And Welcome To The CWorkspace");                                                                                                                                                                                                                                  
                                                                                                                                                                                                                                          
        attroff(COLOR_PAIR(1));                                                                                                                                                                                                                                   
                                                                                                                                                                                                                                          
	getch();
	flash();
	endwin();

	return 0;                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                                                                                                                                                                    
}                                                                                                                                                                                                                                         
                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                          
