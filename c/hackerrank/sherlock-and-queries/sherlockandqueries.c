//https://www.hackerrank.com/challenges/sherlock-and-queries
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void printArray(long arr[],int i,int j)
{
	for(;i<=j;i++)
	{
		printf("%ld ",arr[i]);
	}
	printf("\n");
}


int main() 
{
	int N,M;
	long div=1000000007;
	long *A;
	long *B,*C,*rep;
	scanf("%d %d",&N,&M);
	
	A=(long *)malloc(N*sizeof(long));
	rep=(long *)malloc(N*sizeof(long));
	B=(long *)malloc(M*sizeof(long));
	C=(long *)malloc(M*sizeof(long));
	
	for(int i=0;i<N;i++)
	{
		scanf("%ld",&A[i]);
		rep[i]=1;
	}
	for(int i=0;i<M;i++)
		scanf("%ld",&B[i]);
	for(int i=0;i<M;i++)
	{
		scanf("%ld",&C[i]);
		rep[B[i]-1]=(rep[B[i]-1]*C[i])%div;
	}
	
	for(int i=1;i<=N;i++)
	{
		int loop=N/i;
		for(int j=1;j<=loop;j++)
		{
			A[i*j-1]=(A[i*j-1]*rep[i-1])%div;
		}
	}
	printArray(A,0,N-1);
    return 0;
}
