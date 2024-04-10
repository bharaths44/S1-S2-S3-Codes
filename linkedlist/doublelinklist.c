#include<stdio.h>
#include<stdlib.h>
void main()
{
	struct node
	{
		struct node *prev;
		int data;
		struct node *next;
	};
	int ch,entry,i;
	struct node *head=NULL,*pos=NULL, *tail=NULL;
	while(1)
	{
		printf("\t\n1. Append\t\n2. Display(Forward)\t\n3. Display(Reverse)\t\n4. Delete\t\n5. Exit\n\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("Enter data: ");
				scanf("%d",&entry);
				if(head==NULL)
				{
					head=(struct node*)malloc(sizeof(struct node));
					head->prev=NULL;
					head->data= entry;
					head->next=NULL;
					pos=head;
					tail=head;
				}
				else
				{
					tail->next=(struct node *)malloc(sizeof(struct node));
					tail->next->prev=tail;
					tail->next->data=entry;
					tail->next->next=NULL;
					tail=tail->next;
				} break;
			}
			case 2:
			{	if(head==NULL)
				printf("No elements\n");
				pos=head;
				printf("Elements are: ");
				while(pos!=NULL)
				{
					printf("\t%d",pos->data);
					pos=pos->next;
				} break;
			}
			case 3:
			{
				pos = tail;
				printf("elements are: ");
				while(pos!=NULL)
				{
					printf("\t%d",pos->data);
					pos=pos-> prev;
				} break;
			}
			case 4:
			{	
				struct node *temp;
				printf("\nenter position:\n");
				scanf("%d",&entry);
				if(entry==0)
				{
				struct node* del= head;
				if(head->next!=NULL)
				{
					head= head -> next;
					del -> next=NULL;
					head -> prev=NULL;
					free(del);
				}
				else
					free(head);
				}
				else
				{
					temp=head;
					for(i=0;i<entry-1;i++)
						temp=temp->next;
					if(temp->next->next==NULL)
					{
						struct node* del=tail;
						tail=temp;
						del -> prev=NULL;
						tail->next=NULL;
						free(del);
					}	
					else
					{
						struct node* del=temp->next;
						temp->next=temp->next->next;
						temp->next->prev=temp;
						del->prev=NULL;
						del->next=NULL;
						free(del);
					}
				}break;
			}		
			case 5:
			{
				printf("Goodbye!");
				exit(0);
			}
		}
	}
}
