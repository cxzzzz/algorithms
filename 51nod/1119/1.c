//逆元？
#include<stdio.h>
#define lll long long 
#define max 1000000007
lll extgcd(long long a,long long b,long long *x,long long *y)
{
	long long d=a;
	if(b!=0)
	{
		d=extgcd(b,a%b,y,x);
		(*y)=(*y)-(a/b)*(*x);
	}else
	{
		(*x)=1;(*y)=0;
	}
	return d;
}
lll mod_inverse(lll a,lll m)
{
	lll x,y;
	extgcd(a,m,&x,&y);
	return (m+x%m)%m;
}

int main()
{
	lll M,N,alll,i,j,k,l;
	scanf("%lld%lld",&M,&N);
	N--;M--;
	alll=M+N;
	k=M<N?M:N;

	long long sum=1;
	for(i=1;i<=k;i++)
	{
		j=mod_inverse(i,max);
		l=alll-(i-1);
		sum*=((j*l)%max);
		sum%=max;
	}
	printf("%lld\n",sum);
	return 0;
}



		
