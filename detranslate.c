#include<stdio.h>
#include<stdlib.h>

int main(void){
    FILE *fp=fopen(".spw","r");

    char buff[300];

    if(fp==NULL){
        fprintf(stderr,"sparrow file unavailable");
    }else{
        while(!feof(fp)){
            fscanf(fp,"%s",buff);

            printf("%c",(char)atoi(buff));
        }
    }

    system("rm -rf .spw");
  
    return 0;
}
