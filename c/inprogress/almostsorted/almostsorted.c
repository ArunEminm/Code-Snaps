#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


void AlmostSorted(int a[],int l,int h){
	int i1,i2,min,max,mmin,mmax;
	char sorted='N';
	max=l;min=h;
	int i=l;
	while(i<=h-1 && a[i+1]>=a[i]){
		max=i+1;
		i++;
	}
	if(i==h){
		printf("yes");
		return;
	}
	mmax=i+1;
	while(i<=h-1 && a[i+1]<=a[i]){
		mmin=i+1;
		i++;
	}
	min=i+1;
	while(i<=h-1 && a[i+1]>=a[i]){
		i++;
	}
	if(i==h && a[max]<=a[mmin] && a[mmin]<=a[mmax] && a[mmax]<=a[min]){
		sorted='Y';
		printf("yes");
		printf("reverse %d %d",++mmax,++mmin);
	}
}


int main(void){
	int n;
	scanf("%d",&n);
	int *val;
	val=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d",&val[i]);
	}
	AlmostSorted(val,0,n-1);
}

