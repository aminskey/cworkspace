#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[1]){
	char c;
	int num=0;
	
	char str[30];

	
	FILE *fp=fopen(argv[1],"r+");	
	FILE *sw=fopen(".spw","w");
	if(fp==NULL){
		perror("FILE NOT FOUND");
	}else{
		
		c=fgetc(fp);
		while(!feof(fp)){
			fprintf(sw,"%x ",(int)c);
			c=fgetc(fp);
			num++;
		}
		fscanf(sw,"%s",str);
		sleep(1);
		fclose(sw);
		fclose(fp);
		
		fprintf(fp,"%s",str);
	}
	
	fclose(fp);
	
	return 0;
}
