#include<stdio.h>
#include<string.h>

void putsTerm(const char *, const char *);


int main(int argc, const char *argv[]){
	

	putsTerm(argv[1],argv[2]);
	
	return 0;
}
void putsTerm(const char *in, const char *type){

	char p[170];
	char d1[170];
	char d2[170];
	char d3[170];
	char d4[170];
	char d5[170];
	char d6[170];

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
		printf("TERMINAL ttys003 NOT ONLINE\n");
	}
	if(dev4==NULL){
		printf("TERMINAL ttys004 NOT ONLINE\n");
	}else{
		printf("TERMINAL ttys004 NOT ONLINE\n");
	}
	if(dev5==NULL){
		printf("TERMINAL ttys005 NOT ONLINE\n");
	}else{
		printf("TERMINAL ttys005 NOT ONLINE\n");
	}
	if(dev6==NULL){
		printf("TERMINAL ttys006 NOT ONLINE\n");
	}else{
		printf("TERMINAL ttys006 NOT ONLINE\n");
	}


	if(fp!=NULL)
		fprintf(fp,"\n%s\n",in);
	if(dev1!=NULL)	
		fprintf(dev1,"\n%s\n",in);
	if(dev2!=NULL)	
		fprintf(dev2,"\n%s\n",in);
	if(dev3!=NULL)	
		fprintf(dev3,"\n%s\a\n",in);
	if(dev4!=NULL)	
		fprintf(dev4,"\n%s\a\n",in);
	if(dev5!=NULL)	
		fprintf(dev5,"\n%s\a\n",in);
	if(dev6!=NULL)	
		fprintf(dev6,"\n%s\a\n",in);
	

	fclose(fp);
	fclose(dev1);
	fclose(dev2);
	fclose(dev3);
	fclose(dev4);
	fclose(dev5);
	fclose(dev6);
	
}



