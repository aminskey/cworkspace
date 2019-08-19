
   #include<stdio.h>                                                                                                                                                                     
   #include<string.h>                                                              /* EXCERSIZE FROM : The C programming Language */                                                     
                                                                                   /*                                             */                                                     
   char invert(char *, char *, int);                                               /* DATE : 29/07/19                             */                                                     
                                                                                   /*                                             */                                                     
   int main(void){                                                                 /* CHAPTER 2 SECTION 9 P. 49                   */                                                     
           char Hello[]="Hello, World\n";                                                                                                                                                
                                                                                                                                                                                         
           char nbits[120];                                                                                                                                                              
                                                                                                                                                                                         
           invert(nbits,Hello,strlen(Hello));                                                                                                                                            
                                                                                                                                                                                         
           printf("%s",nbits);                                                                                                                                                           
                                                                                                                                                                                         
           return 0;                                                                                                                                                                     
   }                                                                                                                                                                                     
                                                                                                                                                                                         
   char invert(char *x, char *p, int n){                                                                                                                                                 
                                                                                                                                                                                         
           for(int i=0;i<n;i++){                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                   x[i]= ~p[i];                                                                                                                                                          
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
           }                                                                                                                                                                             
                                                                                                                                                                                         
           return *x;                                                                                                                                                                    
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
   }                                                                                                                                                                                     
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         