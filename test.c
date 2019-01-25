#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int false=0;
int true=1;    


int main(int argc, char *argv[]){
    
    char str[200];
    

    while(strcmp(str,"exit")!=false){
        printf("]");
        scanf("%s",str);
        
        if(strncmp(str,"\n",11)==true){
            printf("OK\n");
            continue;
            
        }
        else if(strcmp(str,"clear")==false){
            for(int i=0;i<40;i++){                
                printf("\n");
            }
            continue; 
        }
        else if(strncmp(str,"bash",20)!=false){
                      
            printf("\b\x1b[7m%s\x1b[0m\n",str+strlen(str-10));     
            continue;
            
        }else if(strncmp(str,"exit",4)==true){
            return 0;
        }
        else if(strcmp(str,"print")!=false){
            system(str);
            
        }else{

        }
        
        

        
        
    }

    return 0;
}