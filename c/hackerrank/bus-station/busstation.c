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
    for (; l<=h; l++)
        printf("%d ", A[l]);
    printf("\n");
}

//Brute force
// void solution(int *a,int l,int h)
// {
// 	int sum_1=0;
// 	for(int i=l;i<=h;i++)
// 	{
// 		sum_1+=a[i];
// 		int j=i+1,sum_2=sum_1;
// 		while(j<=h)
// 		{
// 			sum_2=0;
// 			while(j<=h && sum_2<sum_1)
// 			{
// 				sum_2+=a[j];
// 				j++;
// 			}
// 			if(sum_2==sum_1)
// 				continue;
// 			break;
// 		}
// 		if(j==h+1 && sum_2==sum_1)
// 			printf("%d ",sum_1);
// 	}
// 	printf("\n");
// }


void solution(int *a,int l,int h,int sum_0)
{
	int sum_1=0;
	for(int i=l;i<=h;i++)
	{
		sum_1+=a[i];
		if(sum_0%sum_1==0)
		{
			int j=i+1,sum_2=sum_1;
			while(j<=h)
			{
				sum_2=0;
				while(j<=h && sum_2<sum_1)
				{
					sum_2+=a[j];
					j++;
				}
				if(sum_2==sum_1)
					continue;
				break;
			}
			if(j==h+1 && sum_2==sum_1)
				printf("%d ",sum_1);
		}
	}
	printf("\n");
}

int main()
{
	int n,*a,sum_0=0;
	take(n);
	a=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		take(a[i]);
		sum_0+=a[i];
	}
	solution(a,0,n-1,sum_0);
}
