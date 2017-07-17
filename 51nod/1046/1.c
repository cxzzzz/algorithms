#include<stdio.h>
int main()
{
	long long a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	long long result=1,tmp=a;
	while(b)
	{
		if(b&1)
		{
			result=(result*tmp)%c;
		}
		tmp=(tmp*tmp)%c;
		b=b>>1;
	}
	printf("%lld\n",result);
	return 0;
}

