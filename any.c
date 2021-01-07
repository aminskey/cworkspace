#include<stdio.h>

void any(char *s1, char *s2);

int main(int argc, char const *argv[])
{
    char s1[]="oof";
    char s2[]="ouf";
    any(s1,s2);

    return 0;
}


void any(char *s1,char *s2){

    int i,j,k,l;
    // k=0;

    for(i=j=0;s1[i]!='\0';i++){
        if(s1[i]!=s2[i])
            j++;
    }

    for(k=i=j;s2[i]!='\0';i--){
        if(s2[i]==s1[i])
            k--;
    }

    for(l=i=j;s1[i]!='\0';i++){
        if(s1[i]!=s2[i])
            l++;
    }
    s1[j]='\0';
    s2[k]='\0';


    printf("%d %d %d \n",j,k,l);
}
