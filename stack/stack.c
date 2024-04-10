#include<stdio.h>
#include<stdlib.h>
#define n 5
int top=-1,stack[n];
int isfull()
{
	if(top==n-1)
		return 1;
	else
		return 0;
}
	
int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
	
void push(int val)
{
	if(isfull())
		printf("\nOverflow\n");
	else
	{
		top++;
		stack[top]=val;
		printf("\n%d pushed\n",stack[top]);
	}
}

void pop()
{
	if(isempty())
		printf("\nUnderflow");
	else
	{
		printf("\n%d popped\n",stack[top]);
		stack[top]=-1;
		top--;
	}
}


void display()
{
	int i,x;
	x=top;
	for(i=x;i>=0;i--)
	{
		printf("\n| %d |\n",stack[i]);
	}
}

void main()
{
	int ch,val;
	while (1) 
	{
	printf("\n************************************\n");
	printf("\t1. Push\n\t2. Pop\n\t3. Display\n\t4. Exit");
	printf("\n************************************\n");
	printf("\nEnter the choice :");
	scanf("%d",&ch);
	switch(ch)
	{
			case 1 :
				{
					printf("\nEnter value to be pushed :");
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
				break;
			}
		}
	}
}


