#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void MinimumNo(int n,int k,char val[]);

int main(void){
	int T;
	//T is no of testcases
	scanf("%d",&T);
	while(T-->0){
		int n,k;
		//n is no of digits in the no.
		//k is no of digits to be deleted
		scanf("%d %d",&n,&k);
		char val[n];
		scanf("%1000s",val);
		n=strlen(val);
		MinimumNo(n,k,val);
	}
}

void MinimumNo(int n,int k,char val[]){
	printf("No: %s after %d deletion ",val,k);
	int low=0;//setting lower limit for initial inner loop
	for(int i=k;i<=n-1;i++){
		char min=val[low];//skip this index for further comparison
		low=low+1;//lower limit for inner loop should be 1 higher than previous min index
		for(int j=low;j<=i;j++){
			if(min>val[j]){
				min=val[j];
				low=j+1;
			}
		}
		printf("%c",min);
	}
	printf("\n");
}
