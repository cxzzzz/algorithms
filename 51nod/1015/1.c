#include<stdio.h>
int pow1(int i,int j)
{
	int k,sum=1;
	for(k=0;k<j;k++)
		sum*=i;
	return sum;
}

int num(int i)
{
	int j,k,l=i,sum=0,bit;
	j=1,k=1;while(j<=i)j*=10,k++;j/=10,k--;
	bit=k;
	for(;k>0;k--,j/=10)		
	{
		sum+=pow1(l/j,bit);
		l=l%j;
	}
	return sum==i;
}

int main()
{
	int M,i,j,k;
	scanf("%d",&M);
	for(i=M;;i++)
	{
		if(num(i))
		{
			printf("%d",i);
			return 0;
		}
	}
}
