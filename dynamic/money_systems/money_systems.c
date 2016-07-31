#include<stdio.h>
#define MAX 1000

int main()
{
	int value_nu,value[MAX],num,opt[MAX];
	int i,j,k,l;
	for(i=1;i<MAX;i++)
		opt[i]=0;
	opt[0]=1;
	scanf("%d%d",&value_nu,&num);
	for(i=0;i<value_nu;i++)
		scanf("%d",value+i);
	for(i=0;i<value_nu;i++)
		for(j=num;j>=1;j--)
			for(k=1;value[i]*k<=j;k++)
				opt[j]+=opt[j-value[i]*k];
	printf("%d",opt[num]);
}


