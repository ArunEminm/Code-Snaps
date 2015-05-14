//https://www.hackerrank.com/challenges/sherlock-and-watson
#include<stdio.h>
#include<stdlib.h>
#define print(x) printf("%d\n",x)

/*Fuction to get gcd of a and b*/
int gcd(int a,int b)
{
   if(b==0)
     return a;
   else
     return gcd(b, a%b);
}

//array print i and j both are included
void printArray(int arr[],int i,int j)
{
	for(;i<=j;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

//a is the array i is start point of array, j is end point, k is no of rotation
void RightCircularRotation(int *a,int l,int h,int k)
{
	int L=h-l+1;
	k=k%L;
	if(k!=0)
	{	
		int comm_mul=gcd(L,k);
		int buffer1,buffer2;
		int p;
		int counter;
		int new_p;
		int sets=L/comm_mul;
		for(int i=0;i<comm_mul;i++)
		{
			p=l+i;
			buffer1=a[p];
			buffer2=buffer1;
			counter=0;
			while(counter<sets)
			{
				new_p=(p+k)>h?p+k-L:p+k;
				buffer1=a[new_p];
				a[new_p]=buffer2;
				buffer2=buffer1;
				p=new_p;
				counter++;
			}
		}
	}
}

void LeftCircularRotation(int *a,int l,int h,int k)
{
	int L=h-l+1;
	k=k%L;
	if(k!=0)
	{	
		int comm_mul=gcd(L,k);
		int buffer1,buffer2;
		int p;
		int counter;
		int new_p;
		int sets=L/comm_mul;
		for(int i=0;i<comm_mul;i++)
		{
			p=l+i;
			buffer1=a[p];
			buffer2=buffer1;
			counter=0;
			while(counter<sets)
			{
				new_p=(p-k)<l?p-k+L:p-k;
				buffer1=a[new_p];
				a[new_p]=buffer2;
				buffer2=buffer1;
				p=new_p;
				counter++;
			}
		}
	}
}

int main(void)
{
	int n,k,q;
	scanf("%d %d %d",&n,&k,&q);
	int *a;
	a=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	RightCircularRotation(a,0,n-1,k);
	for(int i=0;i<q;i++)
	{
		int query;
		scanf("%d",&query);
		print(a[query]);
	}
}