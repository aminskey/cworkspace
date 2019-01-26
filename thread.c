#include<stdio.h>

void putsTerm(const char *in);
void putcTerm(void);

int main(int argc, const char *argv[]){

	putsTerm(argv[1]);
	putcTerm();
	return 0;
}
void putsTerm(const char *in){

	FILE *fp=fopen("/dev/ttys000","w+");
	FILE *dev1=fopen("/dev/ttys001","w+");
	FILE *dev2=fopen("/dev/ttys002","w+");
	FILE *dev3=fopen("/dev/ttys003","w+");
	
	if(fp==NULL){
		perror("TERMINAL NOT ONLINE");
	}
	else if(dev1==NULL){
		perror("TERMINAL NOT ONLINE");
	}
	else if(dev2==NULL){
		perror("TERMINAL NOT ONLINE");
	}
	else if(dev3==NULL){
		perror("TERMINAL NOT ONLINE");
	}



	fprintf(fp,"%s\n",in);
	fprintf(dev1,"%s\n",in);
	fprintf(dev2,"%s\n",in);
	fprintf(dev3,"%s\a\n",in);
	

	fclose(fp);
	fclose(dev1);
	fclose(dev2);
	fclose(dev3);
	
	
}
void putcTerm(void){
	int a;

	FILE *fp=fopen("/dev/ttys000","w+");
	FILE *dev1=fopen("/dev/ttys001","w+");
	FILE *dev2=fopen("/dev/ttys002","w+");
	FILE *dev3=fopen("/dev/ttys003","w+");

	if(fp==NULL){
		printf("TERMINAL ttys000 NOT ONLINE\n");
	}
	else if(dev1==NULL){
		printf("TERMINAL ttys001 NOT ONLINE\n");
	}
	else if(dev2==NULL){
		printf("TERMINAL ttys002 NOT ONLINE\n");
	}
	else if(dev3==NULL){
		printf("TERMINAL ttys003 NOT ONLINE\n");
	}

	
	while(a!=EOF)
	{
		a=getchar();
		fputc(a,fp);
		fputc(a,dev1);
		fputc(a,dev2);
		fputc(a,dev3);
		
	}

	fclose(fp);
	fclose(dev1);
	fclose(dev2);
	fclose(dev3);
	

}


