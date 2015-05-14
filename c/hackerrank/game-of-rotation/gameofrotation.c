#include<stdio.h>
#include<stdlib.h>
#define print_long(x) printf("%ld\n",x)
#define print_int(x) printf("%d\n",x)
#define take_long(x) scanf("%ld",&x)
#define take_int(x) scanf("%d",&x)

//array print i and j both are included
void printArray(long arr[],int i,int j)
{
	for(;i<=j;i++)
	{
		print_long(arr[i]);
	}
	printf("\n");
}

int main() 
{
	int N,sum=0;
	take_int(N);
	long *val,*p_mean;
	val=(long *)malloc(N*sizeof(long));
	p_mean=(long *)malloc(N*sizeof(long));
	p_mean[0]=0;
	for(int i=0;i<N;i++)
	{
		take_long(val[i]);
		sum+=val[i];
		p_mean[0]+=(i+1)*val[i];
	}
	long max=p_mean[0];
	for(int i=1;i<N;i++)
	{
		p_mean[i]=p_mean[i-1]+sum-N*val[N-i];
		if(p_mean[i]>max)
			max=p_mean[i];
	}
	print_long(max);
    return 0;
}
