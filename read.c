#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	FILE *fp=fopen(argv[1],"r");

	if(fp == NULL){
		perror("File Not Found");
		return EOF;
	}

	char c=0;
	int col=0;
	int ln=0;

	printf("\x1b[7m");
	while(!feof(fp))
	{
		c=fgetc(fp);
		printf("%5d",c);
		if(col  == 20){
			printf("\n");
			col=0;
		}if(col == '\n')
		{
			ln++;
		}if(ln > 40){
			usleep(1500);
			ln=0;
			continue;
		}
		else{
			col++;
		}
	}
	printf("\x1b[0m\n");
	return 0;
}
