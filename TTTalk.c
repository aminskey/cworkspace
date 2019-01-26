#include<stdio.h>
void putcTerm(void);

int main(void){
    putcTerm();
    return 0;
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
		printf("TERMINAL ttys003 NOT ONLINE\ngi");
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