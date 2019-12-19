#include<stdio.h>

int main(int argc, const char *argv[]){
	FILE *fp=fopen(argv[1],"w+");
	if(fp==NULL){
		perror("File Note Available");
		exit(0);
	}


	fprintf(fp,"%s",argv[2]);
	return 0;
}
