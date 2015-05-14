#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define print(x) printf("%d\n",x)
#define take(x) scanf("%d",&x)

//array print i and j both are included
void printArray(int arr[],int i,int j)
{
	for(;i<=j;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
	int N,T;
	take(N);take(T);
	int *val;
	val=(int *)malloc(N*sizeof(int));
	int *first_occ,*last_occ;
	first_occ=(int *)malloc(3*sizeof(int));
	last_occ=(int *)malloc(3*sizeof(int));
	for(int i=0;i<3;i++)
	{
		first_occ[i]=-1;
		last_occ[i]=-1;
	}
	for(int i=0;i<N;i++)
	{
		take(val[i]);
		if(last_occ[val[i]-1]==-1)
		{
			first_occ[val[i]-1]=i;
			last_occ[val[i]-1]=i;
		}
		else
		{
			int p=last_occ[val[i]-1];
			last_occ[val[i]-1]=i;
			val[p]=i;
		}
		val[i]=-1;
	}
// 	printArray(val,0,N-1);
// 	printArray(first_occ,0,2);
// 	printArray(last_occ,0,2);
	while(T-->0)
	{
	        int i,j,min;
		take(i);take(j);
		for(min=0;min<2;min++)
		{
			int seek;
			if(first_occ[min]!=-1)
			{
				seek=first_occ[min];
				do
				{
					//it is jumping to indexes where min+1=1,2,3 could be found
					if(seek>=i && seek<=j)
					{
						print(min+1);
						min=3;
						break;
					}
					seek=val[seek];
				}while(seek!=-1);
			}
		}
		if(min==2)
			print(min+1);
	}
	return 0;
}
