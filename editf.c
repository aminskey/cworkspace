#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp=fopen(argv[1],"w+");
	char buff[2048];


	int ln=1;

	if(fp == NULL)
	{
		printf("Invalid File name");
		return -1;
	}

	system("clear");
	while(1)
	{

		scanf("%s",buff);


		if(strcmp(buff,"end")==0)
			break;
		if(strcmp(buff," ")==0)
		{
			fprintf(fp," ");
		}

		if(strcmp(buff,"\\n")==0)
		{	
			fprintf(fp,"\n");
			sprintf(buff," ");
			ln++;
		}
		fprintf(fp,"%s ",buff);

		
	}

	system("clear");
	printf("%d Lines",ln);
	return 0;

}
