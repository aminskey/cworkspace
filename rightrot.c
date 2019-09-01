x
   #include<stdio.h>                                                                                                                                                                     
   #include<string.h>                                                                                                                                                                    
                                                                                                                                                                                         
   int rightrot(int, int);                                                                                                                                                               
                                                                                                                                                                                         
   int main(void){                                                             /*    EXCERSIZE FROM : The C programming Language */                                                      
                                                                                                                                                                                         
           char Hello[20]="Hello, World\n";                                    /*    DATE: 29/07/19                              */                                                      
                                                                                                                                                                                         
           for(int i=0;i<strlen(Hello);i++){                                   /*    CHAPTER 2 SECTION 9 P.49                    */                                                      
                                                                                                                                                                                         
                   rightrot(Hello[i],i);                                                                                                                                                 
                                                                                                                                                                                         
           }                                                                                                                                                                             
                                                                                                                                                                                         
           printf("%s",Hello);                                                                                                                                                           
                                                                                                                                                                                         
   }                                                                                                                                                                                     
                                                                                                                                                                                         
   int rightrot(int x, int n){                                                                                                                                                           
                                                                                                                                                                                         
                                                                                                                                                                                         
          x>>=n;                                                                                                                                                                         
                                                                                                                                                                                         
          return x;                                                                                                                                                                      
                                                                                                                                                                                         
                                                                                                                                                                                         
   }                                                                                                                                                                                     
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
                                                                                                                                                                                         
