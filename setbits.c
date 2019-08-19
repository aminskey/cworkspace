
 #include<string.h>                                                                                                                                                                      
                                                                              /*    EXCERSIZE FROM: The C programming Language  */                                                       
 char setbits(char *,  char *, int, int);                                     /*                                                */                                                       
                                                                              /*    DATE : 29/07/19                             */                                                       
 int main(void){                                                              /*    CHAPTER 2 SECTION 9 P. 49                   */                                                       
                                                                                                                                                                                         
         char Hello[]="Hello, World\n This Is Cool\n";                                                                                                                                   
                                                                                                                                                                                         
         char nbits[sizeof(Hello)];                                                                                                                                                      
                                                                                                                                                                                         
         setbits(nbits,Hello,strlen(Hello),'\7');                                                                                                                                        
                                                                                                                                                                                         
         printf("%s",nbits);                                                                                                                                                             
                                                                                                                                                                                         
         return 0;                                                                                                                                                                       
 }                                                                                                                                                                                       
                                                                                                                                                                                         
 char setbits(char *x, char *p, int n, int y){                                                                                                                                           
                                                                                                                                                                                         
         for(int i=0;i<n;i++){                                                                                                                                                           
                                                                                                                                                                                         
                                                                                                                                                                                         
                 p[i]=y;                                                                                                                                                                 
                                                                                                                                                                                         
         }                                                                                                                                                                               
                                                                                                                                                                                         
                                                                                                                                                                                         
         strcat(p,x);                                                                                                                                                                    
                                                                                                                                                                                         
  return *x;                                                                                                                                                                             
 }                                                                                                                                                                                       
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
 ÿ                                                                                                                                                                                       
                                                                                                                                                                                         