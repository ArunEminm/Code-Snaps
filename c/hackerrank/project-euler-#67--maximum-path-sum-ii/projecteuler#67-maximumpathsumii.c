//Project-Euler-#67--Maximum-path-sum-II

#include<stdio.h>
#include<stdlib.h>

void printArray(int A[], int l,int h)
{
    for (; l <=h; l++)
        printf("%d ", A[l]);
    printf("\n");
}

int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		int n,*a,sum=0;
		scanf("%d",&n);
		int total_elem=n*(n+1)/2;
		a=(int *)malloc((total_elem+1)*sizeof(int));
		for(int i=1;i<=total_elem;i++)
			scanf("%d",&a[i]);
		for(int i=n;i>=2;i--)
		{
			for(int j=1;j<=i;j++)
			{
				int s_1=(i*(i-1))/2;
				int max_ele=max(a[s_1+j],a[s_1+j+1]);
				int s_2=((i-1)*(i-2))/2;
				a[s_2+j]+=max_ele;
			}
		}
		printf("%d\n",a[1]);
	}
}
