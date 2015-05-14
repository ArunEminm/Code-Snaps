#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define print(x) printf("%d\n",x)
#define take(x) scanf("%d",&x)

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
 
 
/* Function to print an array */
void printArray(int A[], int l,int h)
{
    for (; l <=h; l++)
        printf("%d ", A[l]);
    printf("\n");
}


void solution(int *a,int *b,int l,int h,int k)
{
	int i=l;
	int len=h-l+1;
	for(i=0;i<len;i++)
	{
		if(a[l+i]+b[h-i]<k)
		{
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}

int main() 
{
	int T;
	take(T);
	while(T-->0)
	{
		int N,K;
		take(N);take(K);
		int *a,*b;
		a=(int *)malloc(N*sizeof(int));
		b=(int *)malloc(N*sizeof(int));
		for(int i=0;i<N;i++)
			take(a[i]);
		for(int i=0;i<N;i++)
			take(b[i]);
		mergeSort(a,0,N-1);
		mergeSort(b,0,N-1);
		//printArray(a,0,N-1);
		//printArray(b,0,N-1);
		solution(a,b,0,N-1,K);
	}
    return 0;
}
