#include<stdio.h>
#include<stdlib.h>

struct Node {

	int data;
	char *name;
	struct Node *next;

};


void printList(struct Node *);

int main(void)
{

	struct Node *head=NULL;
	struct Node *second=NULL;
	struct Node *third=NULL;

	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));

	head->data=1;
	head->name="head";
	head->next=second;

	second->data=2;
	second->name="second";
	second->next=third;

	third->data=3;
	third->name="third";
	third->next=NULL;


	printf("   Linked List Table\n");

	for(int i=0;i<22;i++){
		printf("%c",(unsigned char)205);

		if(i  == 7)
			printf("%c",(unsigned char)209);
	}
	printf("\nNum\t%c\tName\n",(unsigned char)179);

	for(int i=0;i<22;i++){
                printf("%c",(unsigned char)205);

                if(i  == 7)
                        printf("%c",(unsigned char)216);
        }

	printf("\n");
	printList(head);

	for(int i=0;i<22;i++){
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
