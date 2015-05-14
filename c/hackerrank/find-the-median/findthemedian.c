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
 
void quickSort(int arr[], int l, int h,int size,int *median)
{
    if (l < h)
    {
        int p = partition(arr, l, h,size); /* Partitioning index*/
        if(p==size/2)
        {
        	if(size%2==0)
        	{
        		*median=arr[p-1]+(arr[p]-arr[p-1])/2;
        		return;
        	}
        	else
        	{
        		*median=arr[p];
        		return;
        	}
        }
        quickSort(arr, l, p - 1,size,median);
        //printArray(arr,l,h);
        quickSort(arr, p + 1, h,size,median);
        //printArray(arr,l,h);
    }
}

int main(void) 
{   
	int _ar_size;
	scanf("%d", &_ar_size);
	int _ar[_ar_size], _ar_i;
	int median;
	int *p=&median;
	p=(int *)malloc(sizeof(int));
	for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) 
		scanf("%d", &_ar[_ar_i]); 
	//printArray(_ar,0,_ar_size-1);
	quickSort(_ar,0,_ar_size-1,_ar_size,&median);
	//printf("Sorted Array:\n");
	//printArray(_ar,0,_ar_size-1);
	if(median)
		printf("%d\n",median);
	else
	{
		int mid=_ar_size/2;
        {
        	if(_ar_size%2==0)
        	{
        		median=_ar[mid-1]+(_ar[mid]-_ar[mid-1])/2;
        		//return 0;
        	}
        	else
        	{
        		median=_ar[mid];
        		//return 0;
        	}
        }
        printf("%d\n",median);
	}
	return 0;
}


