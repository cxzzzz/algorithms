#include<stdio.h>
#include<limits.h>
unsigned long a[40000];

int main()
{
	unsigned long everynum=10;
	while(UINT_MAX/everynum>10)
		everynum*=10;

	int num_bits=1;//位数	
	
	int N;
	scanf("%d",&N);

	unsigned long long result,tmp;

	int i,j;

	for(i=0;i<10000;i++)
		a[i]=0;
	a[0]=1;	

	for(i=1;i<=N;i++)
	{
		tmp=0;
		for(j=0;j<num_bits;j++)
		{
			result=(unsigned long long)a[j]*(unsigned long long)i+tmp;
			tmp=result/(unsigned long long )everynum;
			a[j]=(unsigned long)(result%(unsigned long long )everynum);
		}
		if(tmp)
			a[num_bits++]=tmp;
	}
	printf("%u",a[--num_bits]);
	for(i=--num_bits;i>=0;i--)
	{
		printf("%09u",a[i]);
	}
}


