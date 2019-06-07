#include<stdio.h>
#include<ncurses.h>
#include<string.h>

int main(void)
{
	initscr();
	cbreak();
	noecho();

	char *dev="/dev/ttys";

	FILE *fp;

	int i=0;

	while(1)
	{
		sprintf(dev,"/dev/ttys%d",i);
		fp=fopen(dev,"r");

		i++;

		if(fp==NULL)
		{
			fprintf(stderr,"Terminal %d not Available\n",i);
		}else{
			printf("Terminal %d Available\n",i);
		}
		fclose(fp);
	}

	getch();
	endwin();

	return 0;
}
