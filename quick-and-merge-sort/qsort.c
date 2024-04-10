#include<stdio.h>
#include<time.h>
#include<stdlib.h>
float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}


void swap(int *a, int *b) 
{
  int t = *a;
  *a = *b;
  *b = t;
}


int partition(int array[], int low, int high,int pivot) 
{
  int i = (low - 1);
  for (int j = low; j < high; j++) 
  {
    if (array[j] <= pivot) 
    {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) 
{
  if (low < high) 
  {
  	int pivot=array[high];
    int pi=partition(array, low, high,pivot);
    quickSort(array,low,pi-1);
    quickSort(array,pi+1,high);
  }
}


int main() 
{
	struct timeval t0;
   	struct timeval t1;
   	float elapsed;
	int n,*data,j,i;
	printf("Enter number of elements :");
	scanf("%d",&n);
    data = (int*)malloc(sizeof(int)*n);
    srand( (unsigned) time(NULL) * getpid());
    if(data != NULL)
    {
        for(j =0;j<n; j++)
            data[j] = rand()%100;
    }
    printf("Given array is \n");
	for(i=0;i<n;i++)
		printf(" | %d | ",data[i]);
	gettimeofday(&t0, NULL);
	quickSort(data, 0, n - 1);
	gettimeofday(&t1, NULL);
	printf("\nSorted array is: \n");
	for (i=0;i<n;++i) 
    		printf(" | %d | ", data[i]);
  	printf("\n");
	elapsed = timedifference_msec(t0, t1);
	printf("\nCode executed in %f milliseconds.\n", elapsed);
}
