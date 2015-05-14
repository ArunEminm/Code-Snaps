#include<stdio.h>
#include<stdlib.h>

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge2(int arr[],int idx[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
    int idx_l[n1],idx_r[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
	idx_l[i]=idx[l+i];
    }
    for(j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1+ j];
	idx_r[j]=idx[m+1+j];
    }
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
	    idx[k]=idx_l[i];
            i++;
        }
	//in case of equality I'm taking the most index in the index array->unstable sorting
        else
        {
            arr[k] = R[j];
	    idx[k]=idx_r[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
	idx[k]=idx_l[i];
	i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
	idx[k]=idx_r[j];
        j++;
        k++;
    }
}

void mergeSort2(int arr[],int idx[],int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort2(arr,idx, l, m);
        mergeSort2(arr,idx, m+1, r);
        merge2(arr,idx, l, m, r);
    }
}

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge1(int arr[], int l, int m, int r)
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
void mergeSort1(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort1(arr, l, m);
        mergeSort1(arr, m+1, r);
        merge1(arr, l, m, r);
    }
}

/* Function to print an array */
void printArray(int A[], int l,int h)
{
    for (; l <=h; l++)
        printf("%d ", A[l]);
    printf("\n");
}

int main(void){
	int n;
	scanf("%d",&n);
	int *val;
	val=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d",&val[i]);
	}
	mergeSort1(val,0,n-1);
	int *diff,*index;
	diff=(int *)malloc((n-1)*sizeof(int));
	index=(int *)malloc((n-1)*sizeof(int));
	for(int i=0;i<n-1;i++){
		diff[i]=val[i+1]-val[i];
		index[i]=i;
	}
	mergeSort2(diff,index,0,n-2);
	int i=0;
	do{
		printf("%d %d ",val[index[i]],val[index[i]+1]);	
		i++;
	}while(diff[i]==diff[i-1]);
}
