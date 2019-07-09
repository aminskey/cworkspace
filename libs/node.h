
#ifndef _NODE_H_                                                                                                                                                        
#define _NODE_H_                                                                                                                                                        

#define KB 1000
#define MB KB*KB
#define GB MB*KB
#define TB GB*KB

#include<stdlib.h>

                                                                                                                                                                        
                                                                                                                                                                        
// Defining Node System                                                                                                                                                 
                                                                                                                                                                        
struct Node {                                                                                                                                                           
                                                                                                                                                                        
        int key;                                                                                                                                                        
                                                                                                                                                                        
        char *data;                                                                                                                                                     
                                                                                                                                                                        
        char *name;                                                                                                                                                     
                                                                                                                                                                        
        struct Node *next;                                                                                                                                              
        struct Node *prev;                                                                                                                                              
                                                                                                                                                                        
};                                                                                                                                                                      

//Head Node
struct Node *head;                                                                                                                                                                        
                                                                                                                                                                        
// Prototyping commands                                                                                                                                                             
                                                                                                                                                                        
struct Node *freeNode(struct Node *n);                                                                                                                                                                        

                                                                                                                                                                        
// Defining Commands                                                                                                                                                                        
                                                                                                                                                                        
struct Node *freeNode(struct Node *n){

	n->prev=n->next;

	free(n);

	return n=NULL;

}                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
                                                                                                                                                                        
#endif                                                                                                                                                                  
