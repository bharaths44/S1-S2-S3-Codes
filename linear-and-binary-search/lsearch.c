#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}
void main()
{
 	struct timeval t0;
   	struct timeval t1;
   	float elapsed;
    long *arr;
    int key,num,i;
    printf("Enter number of elements in array :");
    scanf("%d",&num);
    arr=(long*)malloc(sizeof(long)*num);
    srand((unsigned)time(NULL)*getpid());
    if(arr!=NULL)
    {
        for(i=0;i<num;i++)
            arr[i] = rand()%100;
    }
    printf("The array is :");
     for(i=0;i<num;i++)
    	printf("| %ld |",arr[i]);
    printf("\nEnter element to be searched :");
    scanf("%d",&key);
    gettimeofday(&t0, NULL);
    for(i=0;i<num;i++)
    {
    	if(arr[i]==key)
    	{
    		printf("Element found at %d\n",i);
    		gettimeofday(&t1, NULL);
			elapsed=timedifference_msec(t0, t1);
			printf("Code executed in %f milliseconds.\n", elapsed);
    		exit(0);
    	}
    }
    printf("Element not found\n");
    gettimeofday(&t1, NULL);
    elapsed=timedifference_msec(t0, t1);
    printf("Code executed in %f milliseconds.\n", elapsed);
}
