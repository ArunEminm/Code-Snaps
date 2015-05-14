#include<stdio.h>
#include<stdlib.h>

long merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];
 
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    long count=0;
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
            //We are finding no of elements in leftsubarray which are greater than R[j] because those are the R[j] is shifting by
	    count+=n1-i;
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
    return count;
}
 
/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
long mergeSort(int arr[], int l, int r)
{
	long C=0l;
	if (l < r)
	{
		int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
		C+=mergeSort(arr, l, m);
		C+=mergeSort(arr, m+1, r);
		C+=merge(arr, l, m, r);
	}
	return C;
}
 
 
/* Function to print an array */
void printArray(int A[], int l,int h)
{
    for (; l <=h; l++)
        printf("%d ", A[l]);
    printf("\n");
}

int main(){
	int T;
	scanf("%d",&T);
	while(T-->0){
		int N;
		scanf("%d",&N);
		int val[N];
		int i=0;
		while(i<N){
			scanf("%d",&val[i]);
			i++;
		}
		printf("%ld\n",mergeSort(val,0,N-1));
	}
}


