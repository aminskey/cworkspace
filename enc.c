#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>

int main(int argc, char *argv[]){
	char enf[100]=" ";
	char buff, inv;

	srand(time(0));

	sprintf(enf,".%ld%d",strlen(argv[1]),rand());


	FILE *fp=fopen(argv[1],"r");
	FILE *enc=fopen(enf,"w+");

	if(fp == NULL){
		perror("Your File Doesn't Exist");
		exit(0);
	}

	while(!feof(fp)){
		buff=fgetc(fp);
		inv=~buff;
		fprintf(enc,"%c",inv);
	}

	printf("%s\n",enf);

	fclose(fp);
	fclose(enc);

	return 0;
}
