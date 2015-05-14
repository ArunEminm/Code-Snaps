#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(char arr[], int l, int m, int r)
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
void mergeSort(char arr[], int l, int r)
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
void printArray(char A[], int l,int h)
{
    for (; l <=h; l++)
        printf("%c", A[l]);
    printf("\n");
}

int max(int a ,int b)
{
	if(a>b)
		return a;
	return b;
}

int min(int a ,int b)
{
	if(a>b)
		return b;
	return a;
}

int common_string_len(char *a,int la, int ha,char *b,int lb,int hb)
{
	if(la<=ha && lb<=hb)
	{
		if(a[la]==b[lb])
		{
			return 1+common_string_len(a,la+1,ha,b,lb+1,hb);
		}
		else
		{
			return max(common_string_len(a,la+1,ha,b,lb,hb),common_string_len(a,la,ha,b,lb+1,hb));
		}
	}
	return 0;
}



int main()
{
	char *A,*B;
	int l1,l2,*freq1,*freq2,len=0;
	A=(char *)malloc(10000*sizeof(char));
	B=(char *)malloc(10000*sizeof(char));
	freq1=(int *)malloc(256*(sizeof(int)));
	freq2=(int *)malloc(256*(sizeof(int)));
	scanf("%10000s",A);
	scanf("%10000s",B);
	l1=strlen(A);
	l2=strlen(B);
	for(int i=0;i<256;i++)
	{
		freq1[i]=0;
		freq2[i]=0;
	}
	for(int i=0;i<l1;i++)
	{
		freq1[(int)A[i]]+=1;
	}
	for(int i=0;i<l2;i++)
	{
		freq2[(int)B[i]]+=1;
	}
	for(int i=0;i<256;i++)
	{
		len+=min(freq1[i],freq2[i]);
	}
	printf("%d\n",l1+l2-2*len);
	return 0;
}
