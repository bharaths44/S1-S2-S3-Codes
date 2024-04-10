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
	int ch,entry,i=0,flag;
	while (1)
	{
		printf("1. Insert\n2. Display\n3. Count\n4. Search\n5. Exit");
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
				pos=head;
				for(i=0;pos!=NULL;i++)
					pos=pos->next;
				printf("The number of elements is %d\n\n",i);
				break;
			}
			case 4 :
			{
				printf("\nEnter element to be searched :");
				scanf("%d",&entry);
				pos=head;
				flag=0;
				while(pos!=NULL)
				{
					if(pos->data==entry)
					{
						flag=1;
						break;
					}
					pos=pos->next;
				}
				if(flag==1)
					printf("Element found\n\n");
				else
					printf("Element not found\n\n");
				break;
			}
			case 5 :
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
