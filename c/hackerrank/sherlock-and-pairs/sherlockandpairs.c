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

void solution(int *a,int l,int h)
{
	long poss=0;
	int len=h-l+1;
	for(int i=0;i<len-1;i++)
	{
		long rep=1;
		while(i<l+len-1 && a[l+i]==a[l+i+1])
		{
			rep++;
			i++;
		}
		poss+=(rep-1)*rep;
	}
	printf("%ld\n",poss);
}

int main()
{
	int T;
	take(T);
	while(T-->0)
	{
		int *p,N;
		take(N);
		p=(int *)malloc(N*sizeof(int));
		for(int i=0;i<N;i++)
			take(p[i]);
		mergeSort(p,0,N-1);
		//printArray(p,0,N-1);
		solution(p,0,N-1);
	}
}
