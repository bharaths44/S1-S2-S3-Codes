#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;
}*top=NULL;

void push(int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	if(top==NULL)
		newnode->next=NULL;
	else
		newnode->next=top;
	top=newnode;
	printf("%d is pushed\n",val);
}


int pop()
{
	if(top==NULL)
		printf("Underflow");
	else
	{
		struct node *temp=top;
		int temp_data=top->data;
		top=top->next;
		free(temp);
		printf("%d popped\n",temp_data);
	}
}

void display()
{
	if(top==NULL)
		printf("Stack empty");
	else
	{
		printf("The stack is :\n");
		struct node *temp=top;
		while(temp->next!=NULL)
		{
			printf("|%d|\n",temp->data);
			temp=temp->next;
		}
		printf("|%d|\n",temp->data);
	}
}

void main()
{
	int ch,val;
	while(1)
	{
		printf("\n*************************\n");
		printf("\t1. Push\n\t2. Pop\n\t3. Display\n\t4. Exit");
		printf("\n*************************\n");
		printf("Enter your choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("Enter the value :");
				scanf("%d",&val);
				push(val);
				break;
			}
			case 2:
			{
				pop();
				break;
			}
			case 3:
			{
				display();
				break;
			}
			case 4 :
			{
				printf("Thank you\n");
				exit(0);
			}
		}
	}
}

	
	
