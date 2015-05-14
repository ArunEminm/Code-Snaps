#include<stdio.h>
#include<stdlib.h>

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int l,int h)
{
   int i, key, j,count=0;
   for (i = l+1; i <=h; i++)
   {
       key = arr[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= l && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j--;
       }
       arr[j+1] = key;
       count+=(i-j-1);
   }
   printf("%d\n",count);
}
 
// A utility function ot print an array of size n
void printArray(int arr[], int l,int h)
{
   for (; l <= h; l++)
       printf("%d ", arr[l]);
   printf("\n");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		int n;
		scanf("%d",&n);
		int *arr;
		arr=(int *)malloc(n*sizeof(int));
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		insertionSort(arr,0,n-1);
	}
	return 0;
}

