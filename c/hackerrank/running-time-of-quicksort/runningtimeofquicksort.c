#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// /* Function to sort an array using insertion sort*/
int insertionSort(int arr[], int n)
{
   int i, key, j;
   int count=0;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position*/
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];count++;
           --j;
       }
       arr[j+1] = key;
   }
   return count;
}

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


int* partition (int arr[], int l, int h,int size)
{
	int x=arr[h];
	int i = (l - 1);
	int *r;
	r=(int *)malloc(2*sizeof(int));
	int sw=0;
	//int size=sizeof(arr)/sizeof(arr[0]);

	for (int j = l; j <= h- 1; j++)
	{
		if (arr[j] <= x)
		{
			i++;
			swap(&arr[i], &arr[j]);
			sw++;
		}
	}
	swap(&arr[i + 1], &arr[h]);
	sw++;
	//printArray(arr,0,size-1);
	*r=i+1;
	*(r+1)=sw;
	return r;;
}
 
int quickSort(int arr[], int l, int h,int size)
{
	static int count=0;
	int *r=(int *)malloc(2*sizeof(int));
    if (l < h)
    {
        r = (partition(arr, l, h,size)); /* Partitioning index*/
        int p=*r;
        count+=*(r+1);
        quickSort(arr, l, p - 1,size);
        //printArray(arr,l,h);
        quickSort(arr, p + 1, h,size);
        //printArray(arr,l,h);
    }
    return count;
}

int main() 
{
	int _ar_size;
	scanf("%d", &_ar_size);
	int _ar[_ar_size],_ar2[_ar_size], _ar_i;
	int shifts,swaps;
	for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) 
	{
		scanf("%d", &_ar[_ar_i]); 
		_ar2[_ar_i]=_ar[_ar_i];
	}
	//printArray(_ar,0,_ar_size-1);
	swaps=quickSort(_ar,0,_ar_size-1,_ar_size);
	shifts=insertionSort(_ar2,_ar_size);
	//printf("%d %d\n",shifts,swaps);
	printf("%d\n",shifts-swaps);
	
}
