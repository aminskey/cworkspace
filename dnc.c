#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	char buff;
	char dcr[200];

	srand(time(0));


	sprintf(dcr,".DecryptV:%d",rand());

	FILE *denc=fopen(argv[1],"r+");
	FILE *fp=fopen(dcr,"w+");

	if(denc==NULL){
		perror("File Not Available");
		exit(0);
	}

	while(!feof(denc)){
		buff=fgetc(denc);
		fprintf(fp,"%c",~buff);
		printf("%c",~buff);
	}

	fclose(denc);
	fclose(fp);

	return 0;
}
