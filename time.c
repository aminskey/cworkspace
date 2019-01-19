#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){
    printf("%s\n",__TIMESTAMP__);
    if(strcmp(argv[1],"--mdate")==0){
        printf("%s program made in 15/1/19\n",argv[0]);
    }else if(strcmp(argv[1]," ")){
        
    }else{

    }
    
    return 0;
}