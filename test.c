#include<stdio.h>
#include<unistd.h>
#include<ncurses.h>
#include<strings.h>
#include<dirent.h>
#include<stdlib.h>


char str[1000]=" ";

char str1[100];

char in;
int in1, in2, ans;
int a=0, b=0;
int c=0;

int wln=1, fc=0;
char fc1=0; 

char open[]="sudo ~/bin/dog                                                                                                                           ";
char str2[]="dog ~/cworkspace/commandError.er";
char str3[1000];

void *ls(void);

static int ln=1;

int main(int argc, const char *argv[]){


    FILE *fp;
    
    DIR *dp;
    struct dirent *dir;
    

    int c=0;
    

    in1=in2=0;

    initscr();
    noecho();
    start_color();
    cbreak();

    
    curs_set(0);
    WINDOW *term=newwin(15,60,20,65);
    WINDOW *cc=newwin(10,20,15,35);
    WINDOW *note=newwin(10,20,10,75);
    
    init_pair(1,COLOR_WHITE,COLOR_CYAN); 
    init_pair(2,COLOR_BLACK,COLOR_WHITE);
    init_pair(3,COLOR_WHITE,COLOR_BLACK);

    dp=opendir(argv[1]);

    keypad(note,true);

start1:
    clear();
    wclear(term);

    attron(COLOR_PAIR(1));
    for(int i = 0; i < getmaxy(stdscr); i++)
    {
        
        for(int j=0; j<getmaxx(stdscr);j++){
            mvprintw(i,j,"%c",(unsigned char)176);
        }
        
        
       
    }
    
    
        
    
    
    attroff(COLOR_PAIR(1));

    

    if(dp!=NULL){
    
        if((dir=readdir(dp))!=NULL){
            for(int i=0;i<2;i++)
                dir=readdir(dp);   
        }
    

        attron(COLOR_PAIR(2));
        for(int i = 0; i < 4; i++)
        {
            for(int j=0; j<5; j++){
                mvprintw(i+2,j+2," ");
                if((j>0 && j<4) && i % 1 == 0){
                    
                    mvprintw(i+2,j+2,"~");
                    
                    
                }
                
            }
        }
    
        attroff(COLOR_PAIR(2));

        refresh();

        

        
        attron(COLOR_PAIR(1));
        mvprintw(6,2,"%s",dir->d_name);
        attroff(COLOR_PAIR(1));

    }
    dir=readdir(dp);
    if(dp!=NULL){        
    attron(COLOR_PAIR(2));
        for(int i=0;i<4;i++){
            for(int j=0;j<5;j++){
                mvprintw(i+8,j+2," ");
                if(j>0 && j<4)
                    mvprintw(i+8,j+2,"~");
            
            }
        }
        attroff(COLOR_PAIR(2));

        
        attron(COLOR_PAIR(1));
        mvprintw(12,2,"%s",dir->d_name);
        attroff(COLOR_PAIR(1));

    }
    
    
    
    

    

    wattron(term,COLOR_PAIR(1));
    box(term,0,0);
    wrefresh(term);
    wattroff(term,COLOR_PAIR(1));

    

    echo();
    curs_set(1);
start:
    for(int i=0;i<8;i++){
                for(int j=0;j<28;j++){
                    mvwprintw(term,i+1,j+1," ");
                }
            }
    
    
    
    
    ln=1;
    refresh();
    for(int i=0;i<ln;i++){
        fp=NULL;

        mvwprintw(term,ln,1,"C://>");
        mvwscanw(term,ln,7,"%s",&str);
        fp=fopen(str,"r");
        if(ln<8)
            ln=ln+1;
        
        if(strcmp(str,"exit")==false){
            break;
        }
        else if(strcmp(str,"safari")==false){
            system("open -a safari");
        }
        else if(strcmp(str,"GChrome")==false){
            system("open -a Google\\ Chrome");
        }
        else if(strcmp(str,"khanacademy")==false){
            system("open http://www.khanacademy.org");
        }
        else if(strcmp(str,"youtube")==false){
            system("open http://www.youtube.com");
        }
        else if(strcmp(str,"homework")==false){
            system("open http://pilehaveskolen.m.skoleintra.dk/");
        }
        else if(strcmp(str,"bash")==false){
            noecho();
            system("bash");
            goto start1;
        }
        else if(strcmp(str,"clear")==false){
            goto start;
        }
        else if(strcmp(str,"V/S-Code")==false){
            system("open -a Visual\\ Studio\\ Code");
        }
        else if(strcmp(str,"StoreCal")==false){
            system(str);
            goto start1;
        }
        else if(strcmp(str,"MGameT")==false){
            system(str2);
            goto start1;
        }else if(strcmp(str,"Reload-Workspace")==false){
            
            goto start1;
        }
        else if(strcmp(str,"TTYTALK")==false){
            system("TTYTalk");
            goto start1;
        }
        else if(strcmp(str,"FOURTERM")==false){
            system("FourTerm \"HELLO\"");
            goto start1;
        }
        else if(strcmp(str,"AsciiTable")==false){
            system(str);
            goto start1;
        }
        
        else if(strcmp(str,"MoveEx")==false){
            system("MoveProj");
            goto start1;
        }
        else if(strcmp(str,"Book-ReportEx")==false){
            system("Bookrep");
            goto start1;
        }
        else if(strcmp(str,"calculator")==false){
            

            
            wattron(cc,COLOR_PAIR(1));
            box(cc,0,0);
            wattroff(cc,COLOR_PAIR(1));


            wattron(cc,COLOR_PAIR(3));
            for(int i=0;i<a-2;i++){
                for(int j=0;j<b-2;j++){
                    mvwprintw(cc,i+1,j+1," ");
                }
            }
            wattroff(cc,COLOR_PAIR(3));
            
            mvwscanw(cc,1,1,"%c",&in);
            if(in=='*'){
                mvwscanw(cc,2,1,"%d %d",&in1,&in2);
                ans=in1*in2;
                mvwprintw(cc,3,1,"%d",ans);
                
            }
            if(in=='/'){
                mvwscanw(cc,2,1,"%d %d",&in1,&in2);
                ans=in1/in2;
                mvwprintw(cc,3,1,"%d",ans);
            }
            if(in=='+'){
                mvwscanw(cc,2,1,"%d %d",&in1,&in2);
                ans=in1+in2;
                mvwprintw(cc,3,1,"%d",ans);
            }
            if(in=='-'){
                mvwscanw(cc,2,1,"%d %d",&in1,&in2);
                ans=in1-in2;
                mvwprintw(cc,3,1,"%d",ans);
            }
            wrefresh(cc);
            
        }
        else if(strcmp(str,"calclear")==false){
            
            getmaxyx(cc,a,b);
            wattron(cc,COLOR_PAIR(1));
            for(int i=0;i<a;i++){
                for(int j=0;j<b;j++){
                    mvwprintw(cc,i,j," ");
                }
            }
            wattroff(cc,COLOR_PAIR(1));
            wrefresh(cc);

        }else if(strcmp(str,"notes")==false){

            wattron(note,COLOR_PAIR(1));
            box(note,0,0);
            wattroff(note,COLOR_PAIR(1));

            

            mvwscanw(note,1,1,"%s",str1);
            fp=fopen(str1,"w+");
again:
            a=b=0;
            getmaxyx(note,a,b);

            wattron(note,COLOR_PAIR(3));
            for(int i=0;i<a-2;i++){
                for(int j=0;j<b-2;j++){
                    mvwprintw(note,i+1,j+1," ");
                }
            }
            wattroff(note,COLOR_PAIR(3));

            wmove(note,1,1);

            c=0;
            
            wmove(note,1,1);
         
            while(c!=KEY_F(10)){
                while(fc<3){
                    fc1=fgetc(fp);
                    wattron(note,COLOR_PAIR(3));
                    wprintw(note,"%c",fc1);
                    wattroff(note,COLOR_PAIR(3));
                    fc++;
                    
                }
                
                wattron(note,COLOR_PAIR(2));
                if(c=='\n'){
                    wmove(note,wln+1,1);
                    wln=wln+1;
                }
                if(wln>5){
                    goto again;
                } 
                


                echo();
                wln+=wln;
                mvwscanw(note,wln,1,"%s",str3);
                fprintf(fp,"%s",str3);
                noecho();
                wattroff(note,COLOR_PAIR(2));
                c=wgetch(note);

                

                              
            }
            echo(); 
            wclear(note);

            fclose(fp);
            
            goto start;
            

            
        }
        else if(fp!=NULL){
            sprintf(open+15,"%s/%s",argv[1],str);
            wattron(term,A_INVIS);
            system(open);
            wattroff(term,A_INVIS);
            goto start1;
        }
        else if(strcmp(str,"ll")==FALSE){
            system("~/bin/N-ll");
            goto start1;
        }else if(fp==NULL)
        {
           continue; 
        }
        else{
            continue;
        }
        fclose(fp); 
        wrefresh(cc);
        
    }
    
    if(strcmp(str,"exit")==false)
    {
        system("clear");
    }else{
        goto start;
    }

    

    noecho();
    closedir(dp); 
    fclose(fp);
    endwin();
    
    return 0;
}
