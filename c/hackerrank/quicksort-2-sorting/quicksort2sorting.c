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


int partition (int arr[], int l, int h)
{
	int size,il,ih;
	int x=arr[l];
	size=h-l+1;
	int low[size],high[size];
	il=0;ih=0;
	for(int k=l+1;k<=h;k++)
	{
		if(arr[k]<=arr[l])
		{
			low[il++]=arr[k];
		}
		else
			high[ih++]=arr[k];
	}
	int i=l;
	for(int k=0;k<il;k++)
		arr[i++]=low[k];
	arr[i]=x;
	for(int k=0;k<ih;k++)
		arr[++i]=high[k];
	return l+il;
}
 
void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h); /* Partitioning index*/
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
        printArray(arr,l,h);
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
	quickSort(_ar,0,_ar_size-1);
	//printf("Sorted Array:\n");
	//printArray(_ar,0,_ar_size-1);
	
}


