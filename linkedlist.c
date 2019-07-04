#include<stdio.h>
#include<stdlib.h>

struct Node {

	int key;
	char *pName;
	struct Node *next;

};


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
void initlist(void);


void freeNode(struct Node *n);
// Head node
struct Node *head=NULL;


void initlist (void)
{
	head=(struct Node*)malloc(sizeof(struct Node));
	addNode(head,0,"First Patient");

}


int main(void)
{

	initlist();
	printList();

	freeNode(head);
	return 0;
}

void printList()
{
	while(head != NULL)
	{
		printf("%d\t%c\t%s\n", head->key, (unsigned char)179 ,head->pName);
		head = head->next;

	}
}

struct Node *addNode(struct Node *n,int key, char *pName)
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
}
void freeNode(struct Node *n){

	if(n == NULL)
		perror("Cannot free NULL");
	else{
		free(n);
	}
}
