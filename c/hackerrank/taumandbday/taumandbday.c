#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define print(x) printf("%d\n",x)
#define take(x) scanf("%ld",&x)


int main()
{
	long t,b,w,x,y,z;
	take(t);
	while(t-->0)
	{
		take(b);take(w);take(x);take(y);take(z);
		long cost;
		if(x>y+z)
		{
			cost=w*y+b*(y+z);
			printf("%ld\n",cost);
			continue;
		}
		if(y>x+z)
		{
			cost=w*(x+z)+b*(x);
			printf("%ld\n",cost);
			continue;
		}
		cost=w*y+b*x;
		printf("%ld\n",cost);
	}
}
