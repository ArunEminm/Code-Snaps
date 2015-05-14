#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	int size;
	scanf("%d",&size);
	int arr[size];
	char str[20];
	for(int i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
		fgets(str,20, stdin);
	}
	int count[100];
	for(int i=0;i<100;i++)
	{
		count[i]=0;
	}
	for(int i=0;i<size;i++)
	{
		count[arr[i]]++;
	}
	printf("%d ",count[0]);
	for(int i=1;i<100;i++)
	{
		int sum;
		count[i]=count[i]+count[i-1];
		printf("%d ",count[i]);
	}
	
}

// int main() 
// {
// 	int size;
// 	scanf("%d",&size);
// 	int arr[size];
// 	for(int i=0;i<size;i++)
// 		scanf("%d",&arr[i]);
// 	int *count;
// 	count=(int *)calloc(0,100*sizeof(int));
// // 	for(int i=0;i<100;i++)
// // 	{
// // 		count[i]=0;
// // 	}
// 	for(int i=0;i<size;i++)
// 	{
// 		count[arr[i]]++;
// 	}
// 	for(int i=0;i<100;i++)
// 	{
// 		printf("%d ",count[i]);
// 	}
// 	
// }