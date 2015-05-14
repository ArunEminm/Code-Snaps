#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void CavityTrue(int **arr,int i,int j,char **poss)
{
	//printf("value: %d poss: %c\n",arr[i][j],poss[i][j]);
	
	if(poss[i][j]=='y' && arr[i][j]>arr[i][j-1] && arr[i][j]>arr[i][j+1] && arr[i][j]>arr[i-1][j] && arr[i][j]>arr[i+1][j])
	{
		poss[i][j-1]='n';poss[i][j+1]='n';poss[i-1][j]='n';poss[i+1][j]='n';
		//printf("true\n");
	}
	else
	{
		poss[i][j]='n';
		//printf("false\n");
	}
}

int main() 
{
	int n;
	scanf("%d",&n);
	int **map;
	char **possibility;
	possibility=(char **)malloc(n*sizeof(char *));
	for(int i=0;i<n;i++)
	{
		possibility[i]=(char *)malloc(n*sizeof(char));
	}
	for(int i=1;i<n-1;i++)
		for(int j=1;j<n-1;j++)
			possibility[i][j]='y';
	possibility[0][0]='n';possibility[0][n-1]='n';possibility[n-1][0]='n';possibility[n-1][n-1]='n';
	map=(int **)malloc(n*sizeof(int *));
	for(int i=0;i<n;i++)
	{
		map[i]=(int *)malloc(n*sizeof(int));
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%1d",&map[i][j]);
	for(int i=1;i<n-1;i++)
		for(int j=1;j<n-1;j++)
			CavityTrue(map,i,j,possibility);
	//printf("\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			{
				if(possibility[i][j]=='y')
					printf("X");
				else
					printf("%d",map[i][j]);
			}
		printf("\n");
	}
    return 0;
}
