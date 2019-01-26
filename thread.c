#include<stdio.h>
#include<string.h>

void putsTerm(const char *in);


int main(int argc, const char *argv[]){
	

	putsTerm(argv[1]);
	
	return 0;
}
void putsTerm(const char *in){

	FILE *fp=fopen("/dev/ttys000","w+");
	FILE *dev1=fopen("/dev/ttys001","w+");
	FILE *dev2=fopen("/dev/ttys002","w+");
	FILE *dev3=fopen("/dev/ttys003","w+");
	FILE *dev4=fopen("/dev/ttys004","w+");
	
	if(fp==NULL){
		printf("TERMINAL ttys000 NOT ONLINE\n");
	}
	if(dev1==NULL){
		perror("TERMINAL ttys001 NOT ONLINE\n");
	}
	if(dev2==NULL){
		printf("TERMINAL ttys002 NOT ONLINE\n");
	}
	if(dev3==NULL){
		printf("TERMINAL ttys003 NOT ONLINE\n");
	}if(dev4==NULL){
		printf("TERMINAL ttys004 NOT ONLINE\n");
	}


	if(fp!=NULL)
		fprintf(fp,"%s\n",in);
	if(dev1!=NULL)	
		fprintf(dev1,"%s\n",in);
	if(dev2!=NULL)	
		fprintf(dev2,"%s\n",in);
	if(dev3!=NULL)	
		fprintf(dev3,"%s\a\n",in);
	if(dev4!=NULL)	
		fprintf(dev4,"%s\a\n",in);
	

	fclose(fp);
	fclose(dev1);
	fclose(dev2);
	fclose(dev3);
	fclose(dev4);
	
	
}



