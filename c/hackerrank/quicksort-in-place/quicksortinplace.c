#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


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

int main(void) 
{   
	int _ar_size;
	scanf("%d", &_ar_size);
	int _ar[_ar_size], _ar_i;
	for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) 
		scanf("%d", &_ar[_ar_i]); 
	//printArray(_ar,0,_ar_size-1);
	quickSort(_ar,0,_ar_size-1,_ar_size);
	//printf("Sorted Array:\n");
	printArray(_ar,0,_ar_size-1);
	
}


