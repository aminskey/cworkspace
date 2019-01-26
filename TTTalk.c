#include<stdio.h>
/***************************************************************************************
 * 
 * 	M A D E		I N		2 6 / 1 / 19
 * 
 * P U R P O S E	:	T A L K   T O	A L L	4 	T E R M I N A L S 	IF AVAILABLE
 * 
 ***************************************************************************************/

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
	FILE *dev4=fopen("/dev/ttys004","w+");

	printf("\x1b[7m");

	if(fp==NULL){
		printf("TERMINAL ttys000 NOT ONLINE\n");
	}else{
		printf("TERMINAL ttys000 ONLINE\n");
	}
	if(dev1==NULL){
		printf("TERMINAL ttys001 NOT ONLINE\n");
	}else{
		printf("TERMINAL ttys001 ONLINE\n");
	}
	if(dev2==NULL){
		printf("TERMINAL ttys002 NOT ONLINE\n");
	}else{
		printf("TERMINAL ttys002 ONLINE\n");
	}
	if(dev3==NULL){
		printf("TERMINAL ttys003 NOT ONLINE\n");
	}else{
		printf("TERMINAL ttys003 ONLINE\n");
	}
	if(dev4==NULL){
		printf("TERMINAL ttys004 NOT ONLINE\n");
	}else{
		printf("TERMINAL ttys004 ONLINE\n");
	}
	printf("\x1b[0m");
	printf("\n");

	while(a!=EOF)
	{
		a=getchar();
		if(fp!=NULL)
			fputc(a,fp);
		if(dev1!=NULL)
			fputc(a,dev1);
		if(dev2!=NULL)
			fputc(a,dev2);
		if(dev3!=NULL)	
			fputc(a,dev3);
		if(dev4!=NULL)	
			fputc(a,dev4);
		
	}

	fclose(fp);
	fclose(dev1);
	fclose(dev2);
	fclose(dev3);
	

}