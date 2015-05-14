#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define print(x) printf("%d\n",x)
#define take(x) scanf("%d",&x)


void printArray(long A[], int l,int h)
{
    for (; l <=h; l++)
        printf("%ld\n", A[l]);
    printf("\n");
}

int main()
{
	int n,m,a,b,k;
	long *list,max;
	take(n);take(m);
	list=(long  *)malloc(n*sizeof(long));
	for(int i=0;i<n;i++)
		list[i]=0;
	while(m-->0)
	{
		take(a);take(b);take(k);
		if(b==n)
		{
			list[a-1]+=k;
			continue;
		}
		list[a-1]+=k;
		list[b]-=k;
	}
	max=list[0];
	for(int i=1;i<n;i++)
	{
		list[i]+=list[i-1];
		if(max<list[i])
			max=list[i];
	}
	//printArray(list,0,n-1);
	printf("%ld\n",max);
}