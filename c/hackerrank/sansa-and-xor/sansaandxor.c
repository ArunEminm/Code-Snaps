#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define take(i) scanf("%d",&i);
#define print(i) printf("%d\n",i);

void printArray(int  arr[],int i,int j)
{
	for(;i<=j;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}


int takeXORofArray(int *arr,int l,int h)
{
	int res=0;
	for(int i=l;i<=h;i++)
	{
		res^=arr[i];
	}
	return res;
}

//k^k^k^k.. n times so if n=0 return value is 0
int selfXOR(int k,int n)
{
	int ret=0;
	while(n-->0)
		ret^=k;
	return ret;
}

//continuous numbers XOR
int continuousXOR(int l,int h)
{
	int ret=l;
	while(++l<=h)
		ret^=l;
	return ret;
}

//no of times ith elements comes in all contiguous sub array of array a from index l to h
int Rep_of_ele_in_all_cont_sub_Arrays(int l,int h,int query)
{
	int N=h-l+1;
	h=h-l+1;
	query=query-l+1;
	l=1;
	if(query<1 || query>h)
		return 0;
	else
	{
		int rep;
		int mid=(l+h)/2;
		query=query>mid?h+l-query:query;
		rep=2*(query-1)+query*(N-2*(query-1));
		return rep;
	}
}

int solution(int *arr,int l,int h)
{
	int res=0;
	for(int i=l;i<=h;i++)
	{
		int p;
		p=Rep_of_ele_in_all_cont_sub_Arrays(l,h,i);
		p=p%2;
		if(p==1)
			res^=arr[i];
	}
	return res;
}

int main() 
{
	int T,N;
	int *val;
	take(T);
	while(T-->0)
	{
		take(N);
		val=(int *)malloc(N*sizeof(int));
		for(int i=0;i<N;i++)
			take(val[i]);
		print(solution(val,0,N-1));
	}
    return 0;
}
