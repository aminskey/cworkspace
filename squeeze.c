#include<stdio.h>
void squeeze(char *, char*);

int main(void){
    
}

void squeeze(char s1[],char s2[]){
    
    char s3[]=" ";

    int i,j;
    
    for(i=j=0;s1[i]!='\0';i++){
        if(s1[i]==s2[i])
            continue;
        s1[j++]=s1[i];
    }

    for(i=j;s1[i]!='\0';i--){
        if(s1[i]!=s2[i])
            continue;
        s1[j++]=s1[i];
    }
    

    s1[j]='\0';
    s2[j]='\0';

    
}