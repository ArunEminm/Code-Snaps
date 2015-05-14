#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main() 
{
	int size;
	scanf("%d",&size);
	int in;
	char *str[size];
	int count[100];
	int first_occ[100];
	int last_occ[100];
	int *index;
	index=(int*)malloc(size*sizeof(int));
	for(int i=0;i<100;i++)
	{
		count[i]=0;first_occ[i]=-1;
	}
	for(int i=0;i<size;i++)
	{
		str[i]=(char*)malloc(10*sizeof(char));
		scanf("%d %s",&in,str[i]);
		index[i]=-1;
		if(first_occ[in]==-1)
		{
			first_occ[in]=i;
			last_occ[in]=i;
		}
		else
		{
			int p=last_occ[in];
			
// 			while(index[p]!=-1)
// 			{
// 				p=index[p];
// 			}
			index[p]=i;
			last_occ[in]=i;
		}
		count[in]++;
		//printf("%s\n",str[i]);
	}
	int mid=size/2;
	for(int i=0;i<100;i++)
	{
		if(first_occ[i]!=-1)
		{
			if(first_occ[i]>mid-1)
				printf("%s ",str[first_occ[i]]);
			else
				printf("- ");
			int p=first_occ[i];
			while(index[p]!=-1)
			{
				if(index[p]>mid-1)
					printf("%s ",str[index[p]]);
				else
					printf("- ");
				p=index[p];
			}
		}
	}
	
}
