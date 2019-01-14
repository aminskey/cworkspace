#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[1]){
	char c;
	FILE *fp=fopen(argv[1],"r");
	
	if(fp==NULL){
		perror("FILE NOT FOUND");
	}else{		
		c=fgetc(fp);
		while(!feof(fp)){
			c=fgetc(fp);
			printf("%d",c);
		}
	}
	return 0;
}
