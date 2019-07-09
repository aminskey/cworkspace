
#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      

extern struct Node;


struct Node *freeNode(struct Node *n);                                                                                                                                  


int main(void)                                                                                                                                                          
{                                                                                                                                                                       
                                                                                                                                                                        
 struct Node *testNode=(struct Node*)malloc(sizeof(struct Node));                                                                                                        
                                                                                                                                                                        
 freeNode(testNode);                                                                                                                                                    
                                                                                                                                                                        
}                                                                                                                                                                       
                                                                                                                                                                        
                                                                                                                                                                        
struct Node *freeNode(struct Node *n){                                                                                                                                  
                                                                                                                                                                        
                                                                                                                                                                        
         if(n == NULL)                                                                                                                                                  
                perror("Node Is Already Null");                                                                                                                         
         else{                                                                                                                                                          
                                                                                                                                                                        
                 free(n);                                                                                                                                               
                                                                                                                                                                        
         }                                                                                                                                                              
                                                                                                                                                                        
                                                                                                                                                                        
         return n = NULL;                                                                                                                                               
                                                                                                                                                                        
                                                                                                                                                                        
}                                                                                                                                                                       
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
