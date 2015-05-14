#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

bool ifPowerof2(unsigned long int t)
{
	return t&(t-1);
}


int ln2(unsigned long int t)
{
	const unsigned long b[] = {0x2, 0xC, 0xF0, 0xFF00, 0xFFFF0000,0xFFFFFFFF00000000};
	const unsigned int S[] = {1, 2, 4, 8, 16,32};
	int i;
	int r = 0; // result of log2(v) will go here
	for (i = 5; i >= 0; i--) // unroll for speed...
	{
	  if(t&b[i])
	  {
		t>>=S[i];
		r|=S[i];
	  } 
	}
	return r;
}

unsigned long int Powerof2(unsigned long int t)
{
	int k;
	
	k=ln2(t);
	//printf("k=%d\n",k);
	t=1;
	t=t<<k;
	return t;
}

void winner(unsigned long int t)
{	
	int i=0;
	char player[][8]={"Louise","Richard"};
	if(t==1)
		printf("Richard\n");
	else
	{
		while(t!=1)
		{
			if(ifPowerof2(t)==0)
			{
				int k=ln2(t);
				if(k%2==0)
				{
					i++;
				}
				t=1;
			}
			else
			{
				t-=Powerof2(t);
				if(t!=1) i++;
			}
			//printf("N: %lu\n",t);
			//i++;
		}
		printf("%s\n",player[i%2]);

	}
}


int main() 
{
	int T;
	scanf("%d",&T);
	unsigned long int N;
	while(T-->0)
	{
		scanf("%lu",&N);
		//printf("%lu\n",Powerof2(N));
		winner(N);
	}
}
