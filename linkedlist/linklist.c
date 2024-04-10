#include<stdio.h>
#include<stdlib.h>
void main()
{
	struct node
	{
		int data;
		struct node *next;
	};
	struct node *head=NULL,*pos=NULL,*tail=NULL;
	int ch,entry;
	while (1)
	{
		printf("1. Insert\n2. Display\n3. Exit");
		printf("\nEnter your choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :
			{
				printf("\nEnter data :");
				scanf("%d",&entry);
				if(head==NULL)
				{
					head=(struct node*)malloc(sizeof(struct node));
					head->data=entry;
					pos=head;
					tail=head;
				}
				else
				{
					tail->next=(struct node*)malloc(sizeof(struct node));
					tail=tail->next;
					tail->data=entry;
				}
				printf("\n\n");
				break;
			}
			case 2 :
			{
				pos=head;
				printf("\nElements are :");
				while(pos!=NULL)
				{
					printf("\t%d",pos->data);
					pos=pos->next;
				}
				printf("\n\n");
				break;
			}
			case 3 :
			{
				printf("\nGood bye!!!\n\n");
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
