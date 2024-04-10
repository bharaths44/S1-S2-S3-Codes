#include<stdio.h>
#include<stdlib.h>
int n=-1;
struct node
	{
		int data;
		struct node *next;
	};
	struct node *head=NULL,*pos=NULL,*tail=NULL;

void enqueue(int entry)
{
	if(head==NULL)
				{
					head=(struct node*)malloc(sizeof(struct node));
					head->data=entry;
					pos=head;
					tail=head;
					printf("%d inserted",entry);
				}
	else
				{
					tail->next=(struct node*)malloc(sizeof(struct node));
					tail=tail->next;
					tail->data=entry;
					printf("%d inserted",entry);
				}
		n++;
}

void display()
{
	if(n==-1)
		printf("Queue Empty\n");
	else
	{
				pos=head;
				printf("Elements are :");
				while(pos!=NULL)
				{
					printf("\t| %d |",pos->data);
					pos=pos->next;
				}
	}
	printf("\n");
}

void dequeue()
{
	if(n==-1)
		printf("Queue Empty\n");
	else
	{			
				struct node *temp=head;
				printf("%d deleted",head->data);
				head=head->next;
				temp->next=NULL;
				free(temp);
				n--;
		}
		printf("\n");
}



void main()
{
	int ch,i=0,entry;
	while (1)
	{
		printf("\t*************\n");
		printf("\t1. Enqueue\n\t2. Display\n\t3. Dequeue\n\t4. Exit\n");
		printf("\t*************\n");
		printf("Enter your choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :
			{
				printf("Enter data :");
				scanf("%d",&entry);
				enqueue(entry);
				printf("\n\n");
				break;
			}
			case 2 :
			{
				display();
				printf("\n");
				break;
			}
			
			case 3 :
			{
				dequeue(entry);
				break;
			}
			case 4 :
			{
				printf("Good bye!!!\n\n");
				exit(0);
			}
			default :
			{
				printf("Wrong input\n\n");
				break;
			}
		}
	}
}
