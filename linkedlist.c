#include <stdio.h>
#include <stdlib.h>
#include "libs/node.h"


// Prints the list from the Head Node to the End of the list
void printList(void);

// Add a node to the end of the list
struct Node *addNode(struct Node *n, int key, char *pName);

// Add a node after the specified Node in  the list
//void addAfterNode(struct Node** first, int data, char *name);

// Remove a node from anywhere in the list
void removeNode(int key);

// search and return the Node with data
//Node search(int data);

// Check if the list is  circular
//void isCircularList(void); 

// Initialize the list
struct Node* initlist(int key, char *data, char *name);


struct Node *initlist(int key, char *data, char *name)
{

	extern struct Node *head;

	head->key=key;
	head->data=data;
	head->name=name;

	return head;
}


int main(void)
{
	//struct Node *head=(struct Node*)malloc(sizeof(struct Node));

	initlist(12,"This Is The First Node in the List","Head Node");

	freeNode(head);

	return 0;

}

/*void printList()
{

	while(head != NULL)
	{
		printf("%d\t%c\t%s\n", head->key, (unsigned char)179 ,head->pName);
		head = head->next;

	}
}*/

/*struct Node *addNode(struct Node *n,int key, char *pName)
{
	if(n == NULL){
		n=head;
	}else{
		while(n->next != NULL)
			n = n->next;
	}

	n=(struct Node*)malloc(sizeof(struct Node));

	n->key=key;
	n->pName=pName;

	return n;
}*/
