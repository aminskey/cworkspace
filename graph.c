#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXY 15
#define MAXX 44


int graph[MAXY][MAXX]=
{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}


};

void makepoint(int, int, int);
void decode(void);
void newonlast(void);
void graphval(void);
void rect(int, int, int, int, int);
void rectol(int, int, int, int, int);
void printatloc(int, int, char *);

int main(void){
	newonlast();
	graphval();

	return 0;
}
void printatloc(int y, int x, char *s){
	for(int i=0;i<strlen(s);i++){
		graph[y][x+i]=s[i];
	}
}
void rectol(int sy, int sx, int ey, int ex, int num){
	rect(sy,sx,ey,ex,num);
	rect(sy+1,sx+1,ey-1,ex-1,0);
}
void rect(int sy, int sx, int ey, int ex, int num){
	for(int i=sy;i<ey;i++){
		for(int j=sx; j<ex;j++)
			makepoint(i,j,num);
	}
}
void makepoint(int y, int x, int num){

        graph[y][x]=num;

}
void newonlast(void){
	for(int i=0;i<MAXY;i++){
		makepoint(i,MAXX-1,7);
	}
}
void graphval(void){
	for(int i=0;i<=MAXY;i++){
		for(int j=0;j<=MAXX;j++){
			printf("%d",graph[i][j]);
		}
		printf("\n");
	}
}
void decode(void){


        for(int i=0;i<=MAXY;i++){
                for(int j=0;j<=MAXX;j++){
                        switch(graph[i][j]){
                                case 0:
                                        printf(" ");
                                        break;
                                case 1:
                                        printf("*");
                                        break;
                                case 2:
                                        printf("#");
                                        break;
                                case 3:
                                        printf("~");
                                        break;
                                case 4:
                                        printf("/");
                                        break;
                                case 5:
                                        printf("|");
                                        break;
                                case 6:
                                        printf("\\");
                                        break;
				case 7:
					printf("\n");
					break;
                               default:
					printf("%c",(unsigned char)graph[i][j]);
					break;
                        }
                }
        }
}
