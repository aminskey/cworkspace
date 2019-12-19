#include<stdio.h>
/***************************************************************************************
 * 
 * 	M A D E		I N		2 6 / 1 / 19
 * 
 * P U R P O S E	:	T A L K   T O	A L L	4 	T E R M I N A L S 	IF AVAILABLE
 * 
 ***************************************************************************************/

void putcTerm(const char *);

int main(int argc, const char *argv[]){
    putcTerm(argv[1]);
    return 0;
}

void putcTerm(const char *type){
	int a;

	char p[100];
	char d1[100];
	char d2[100];
	char d3[100];
	char d4[100];
	char d5[100];
	char d6[100];

	sprintf(p,"/dev/%s0",type);
	sprintf(d1,"/dev/%s1",type);
	sprintf(d2,"/dev/%s2",type);
	sprintf(d3,"/dev/%s3",type);
	sprintf(d4,"/dev/%s4",type);
	sprintf(d5,"/dev/%s5",type);
	sprintf(d6,"/dev/%s6",type);
	
	FILE *fp=fopen(p,"w+");
	FILE *dev1=fopen(d1,"w+");
	FILE *dev2=fopen(d2,"w+");
	FILE *dev3=fopen(d3,"w+");
	FILE *dev4=fopen(d4,"w+");
	FILE *dev5=fopen(d5,"w+");
	FILE *dev6=fopen(d6,"w+");

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
	if(dev5==NULL){
		printf("TERMINAL ttys005 NOT ONLINE\n");
	}else{
		printf("TERMINAL ttys005 ONLINE\n");
	}
	if(dev6==NULL){
		printf("TERMINAL ttys006 NOT ONLINE\n");
	}else{
		printf("TERMINAL ttys006 ONLINE\n");
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
		if(dev5!=NULL)	
			fputc(a,dev5);
		if(dev6!=NULL)	
			fputc(a,dev6);
		
	}

	fclose(fp);
	fclose(dev1);
	fclose(dev2);
	fclose(dev3);
	fclose(dev4);
	fclose(dev5);
	fclose(dev6);
	

}
