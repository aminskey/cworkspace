#include<stdio.h>

int main(void){
    FILE *fp=fopen("/dev/ttys000","w+");
	FILE *dev1=fopen("/dev/ttys001","w+");
	FILE *dev2=fopen("/dev/ttys002","w+");
	FILE *dev3=fopen("/dev/ttys003","w+");
	FILE *dev4=fopen("/dev/ttys004","w+");
    FILE *dev5=fopen("/dev/ttys005","w+");
    FILE *dev6=fopen("/dev/ttys006","w+");

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
	printf("\x1b[7m");
	return 0;
}