
#include<stdio.h>
#include<string.h>
#include<ncurses.h>

static int a1, a2, ans=0;
static int ai, bi, ci, di;
static int as, bs, cs, ds;
static int ac, bc, cc, dc;


int main(int argc, char *argv[]){

	FILE *fp=fopen(argv[1],"r");

	char buff[2000];
	char prnt[2000];


	if(fp == NULL){
		perror("File Cannot Be Found: Could Not Exist");
		return -1; 
	}
	rewind(fp);
        while(!feof(fp)){
		fscanf(fp,"%s",buff);
		if(strcmp(buff,"add")==false)
		{
			fscanf(fp,"%d %d",&a1, &a2);
			ans=a1+a2;
		}
		if(strcmp(buff,"sub")==false)
		{
			fscanf(fp,"%d %d",&a1, &a2);
			ans=a1-a2;
		}
		if(strcmp(buff,"mul")==false)
		{
			fscanf(fp,"%d %d",&a1, &a2);
			ans=a1*a2;
		}
		if(strcmp(buff,"div")==false)
		{
			fscanf(fp,"%d %d",&a1, &a2);
			ans=a1/a2;
		}
		if(strcmp(buff,"printv")==false)
		{
			fscanf(fp,"%s",prnt);
			if(strcmp(prnt,"a1")==false)
				printf(" %d ",a2);
			if(strcmp(prnt,"a2")==false)
				printf(" %d ",a1);
			if(strcmp(prnt,"ans")==false)
				printf(" %d ",ans);
			sprintf(prnt," ");
		}
		if(strcmp(buff,"print")==false)
		{
			a1=0;
			fscanf(fp,"%d",&a1);
			for(int i=0;i<a1;i++){
				fscanf(fp,"%s",prnt);
				printf(" %s ",prnt);
			}
			sprintf(prnt," ");
		}
	/*	if(strcmp(buff,"movi")==false)
		{
			fscanf(fp,"%s",prnt);
			if(strcmp(prnt,"ai")==false)
			{

			}
		}
	*/
	}

	return 0;
}
