#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

struct Node {

	int data;
	char *name;
	struct Node *next;

};


void printList(struct Node *);
void push(struct Node** head_ref, int new_data, char *name);
void deleteNode(struct Node **head_ref, int key);

int main(void)
{

	struct Node *head=NULL;

	srand(time(0));
	push(&head,rand()%100000,"First Node Pushed");
	push(&head,rand()%100000,"Second Node Pushed");
	push(&head,5,"Deleted Node");

	deleteNode(&head, 5);

	system("clear");

	printf("   Linked List Table\n");

	for(int i=0;i<35;i++){
		printf("%c",(unsigned char)205);

		if(i  == 7)
			printf("%c",(unsigned char)209);
	}
	printf("\nNum\t%c\tName\n",(unsigned char)179);

	for(int i=0;i<35;i++){
                printf("%c",(unsigned char)205);

                if(i  == 7)
                        printf("%c",(unsigned char)216);
        }

	printf("\n");
	printList(head);

	for(int i=0;i<35;i++){
                printf("%c",(unsigned char)205);

                if(i  == 7)
                        printf("%c",(unsigned char)207);
        }

	return 0;


}

void printList(struct Node *n){
	while(n != NULL)
	{
		printf("%d\t%c\t%s\n", n->data, (unsigned char)179 ,n->name);
		n = n->next;

	}
}
void push(struct Node** head_ref, int new_data, char *new_name)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    	new_node->data  = new_data;
	new_node->name = new_name;

    	new_node->next = (*head_ref);

    	(*head_ref)    = new_node;
}
void deleteNode(struct Node **head_ref, int key)
{

    	struct Node* temp = *head_ref, *prev; 

    	if (temp != NULL && temp->data == key)
    	{
        	*head_ref = temp->next;
        	free(temp);
        	return;
    	}



    	while (temp != NULL && temp->data != key)
    	{
        	prev = temp;
        	temp = temp->next;
    	}

    	if (temp == NULL) return;

    	prev->next = temp->next;

    	free(temp);
}
