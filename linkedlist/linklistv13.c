#include<stdio.h>
#include<stdlib.h>
#include <time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}
void main()
{
	struct node
	{
		int data;
		struct node *next;
	};
	struct timeval t0;
   	struct timeval t1;
   	float elapsed;
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
				printf("\nEnter number of data :");
				scanf("%d",&entry);
				gettimeofday(&t0, NULL);
				if(head==NULL)
				{
					head=(struct node*)malloc(sizeof(struct node));
					head->data=rand()%100;
					pos=head;
					tail=head;
				}
				
				for(i=0;i<entry-1;i++)
				{
					tail->next=(struct node*)malloc(sizeof(struct node));
					tail=tail->next;
					tail->data=rand()%100;
				}
				gettimeofday(&t1, NULL);
				elapsed = timedifference_msec(t0, t1);
				printf("Code executed in %f milliseconds.\n", elapsed);
			}
				printf("\n\n");
				break;
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
