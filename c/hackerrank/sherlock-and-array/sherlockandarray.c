#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void printArray(int  arr[],int i,int j)
{
	for(;i<=j;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main() 
{
	int T;
	int N;
	int *arr,*l_sum;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&N);
		arr=NULL;
		arr=(int *)malloc(N*sizeof(int));
		l_sum=NULL;
		l_sum=(int *)malloc(N*sizeof(int));
		int sum=0;
		for(int i=0;i<N;i++)
		{	
			l_sum[i]+=sum;
			scanf("%d",&arr[i]);
			sum+=arr[i];
		}
		//printArray(arr,0,N-1);
		//printArray(l_sum,0,N-1);
		int i=0;
		for(i=0;i<N;i++)
		{
			int cal=2*l_sum[i]+arr[i];
			if(cal==sum)
				{
					//printf("%d ",i);
					printf("YES\n");
					break;
				}
		}
		if(i==N)
			printf("NO\n");
	}
    return 0;
}
