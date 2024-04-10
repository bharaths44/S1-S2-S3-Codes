#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1;
int isfull(int n)
{
	if(rear==n-1)
		return 1;
	else
		return 0;
}
	
int isempty(int n)
{
	if(front==-1)
		return 1;
	else
		return 0;
}
	
void enqueue(int val,int *q,int n)
{
	if(isfull(n))
		printf("Queue Full\n");
	else
	{
		if(front==-1)
			front=0;
		rear++;
		q[rear]=val;
		printf("%d inserted\n",q[rear]);
	}
}

void dequeue(int *q,int n)
{
	if(isempty(n))
		printf("Queue Empty\n");
	else
	{
		printf("%d deleted\n",q[front]);
		q[front]=-1;
		front++;
		if(front>rear)
		{
			front=-1;
			rear=-1;
		}
	}
}


void display(int *q,int n)
{
	int i,x;
	if(isempty(n))
		printf("Queue Empty\n");
	else
	{
		for(i=front;i<=rear;i++)
			printf("| %d |\t",*(q+i));
	}
	printf("\n");
}

void main()
{
	int ch,val,n;
	printf("Enter number of data :");
	scanf("%d",&n);
	int q[n];
	while (1) 
	{
	printf("************************************\n");
	printf("\t1. Enqueue\n\t2. Dequeue\n\t3. Display\n\t4. Exit");
	printf("\n************************************\n");
	printf("Enter the choice :");
	scanf("%d",&ch);
	switch(ch)
	{
			case 1 :
				{
					printf("Enter value to be inserted :");
					scanf("%d",&val);
					enqueue(val,q,n);
					printf("\n");
					break;
				}
		 	case 2:
			{
				dequeue(q,n);
				printf("\n");
				break;
			}
			case 3:
			{
				display(q,n);
				printf("\n");
				break;
			}
			case 4 :
			{
				printf("Thank you ;)\n");
				exit(0);
				break;
			}
		}
	}
}
