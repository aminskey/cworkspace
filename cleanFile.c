#include<stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp=fopen(argv[1],"w+");

	if(fp == NULL)
	{
		perror("File not available");
	}

	fseek(fp, 0 ,SEEK_END);
	while(!feof(fp))
	{
		fprintf(fp,"\b");
	}
	return 0;
}
