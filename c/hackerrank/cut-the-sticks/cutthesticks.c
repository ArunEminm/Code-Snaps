#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void printArray(int  arr[],int i,int j)
{
	for(;i<=j;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition (int arr[], int l, int h,int size)
{
	int x=arr[h];
	int i = (l - 1);
	//int size=sizeof(arr)/sizeof(arr[0]);

	for (int j = l; j <= h- 1; j++)
	{
		if (arr[j] <= x)
		{
			//i++;
			swap(&arr[++i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[h]);
	//printArray(arr,0,size-1);
	return (i + 1);
}
 
void quickSort(int arr[], int l, int h,int size)
{
    if (l < h)
    {
        int p = partition(arr, l, h,size); /* Partitioning index*/
        quickSort(arr, l, p - 1,size);
        //printArray(arr,l,h);
        quickSort(arr, p + 1, h,size);
        //printArray(arr,l,h);
    }
}

int main() 
{
	int N;
	scanf("%d",&N);
	int *lengths;
	lengths=(int *)malloc(N*sizeof(int));
	for(int i=0;i<N;i++)
		scanf("%d",&lengths[i]);
	quickSort(lengths,0,N-1,N);
	//printArray(lengths,0,N-1);
	int i;
	int i_prev;
	for(i=0;i<N-1;i++)
	{
		printf("%d\n",N-i);
		i_prev=i;
		while(lengths[i]==lengths[i+1])
		{
			i++;
		}
	}
	if(i==N-1)
		printf("1\n");
    return 0;
}
