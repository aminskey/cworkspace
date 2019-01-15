#include<stdio.h>
#include<stdlib.h>

int main(void){
    FILE *fp=fopen(".spw","r");

    char buff[300];

    if(fp==NULL){
        perror("sparrow file not found");
    }else{
        while(!feof(fp)){
            fscanf(fp,"%s",buff);

            printf("%c",(char)atoi(buff));
        }
    }
}