#include<stdio.h>
#include<stdlib.h>

struct Node {

	int key;
	char *pName;
	struct Node *next;
	struct Node *prev;

};


// Prints the list from the Head Node to the End of the list
void printList(void);

// Add a node to the end of the list
void addNode(int key, char *pName);

// Add a node after the specified Node in  the list
//void addAfterNode(struct Node** first, int data, char *name);

// Remove a node from anywhere in the list
void removeNode(int key);

// search and return the Node with data
//Node search(int data);

// Check if the list is  circular
//void isCircularList(void); 

// Initialize the list
void init(void);

// Head node
struct Node *head=NULL;


void init (void)
{
	addNode(-1,"First Patient");

}


int main(void)
{

	init();
	printList();

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

void addNode(int key, char *pName)
{
	struct Node *node=(struct Node*)malloc(sizeof(struct Node));
	struct Node *last = head;

	if(head == NULL)
		node=NULL;

	while(last->next != NULL)
		last = last->next;
	node = last->next;

	node->pName=pName;
	node->key=key;

}
