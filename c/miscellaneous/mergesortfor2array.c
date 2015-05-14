//By Arun Kumar
//Btech IIT Delhi

#include<stdio.h>
#include<stdlib.h>

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[],int idx[], int l, int m, int r)
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

void mergeSort(int arr[],int idx[],int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr,idx, l, m);
        mergeSort(arr,idx, m+1, r);
        merge(arr,idx, l, m, r);
    }
}

void printArray(int arr[],int l,int h)
{
	for(;l<=h;l++)
		printf("%d ",arr[l]);
	printf("\n");
}

int main(void)
{
	int val[5]={32,34,16,45,54};
	int index[5]={0,1,2,3,4};
	printArray(val,0,5-1);
	printArray(index,0,5-1);
	mergeSort(val,index,0,5-1);
	printArray(val,0,5-1);
	printArray(index,0,5-1);
}
