#include<stdio.h>
#include<stdlib.h>

int main(void){
    FILE *fp=fopen(".spw","r");

    int buff;

    if(fp==NULL){
        fprintf(stderr,"sparrow file unavailable");
    }else{
        while(!feof(fp)){
            fscanf(fp,"%x",buff);

            printf("%c",(char)buff);
        }
    }

    system("rm -rf .spw");
  
    return 0;
}
