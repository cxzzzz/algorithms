#include<stdio.h>
int main()
{
	long nu,i,j=0;
	long long a[50000];
	scanf("%ld",&nu);
	for(i=0;i<nu;i++){
		scanf("%lld",&a[i]);
	};
	long long max=a[0];
	long long b2,b1=0;
	for(i=0;i<nu;i++){
		b2=(b1>0)?(b1+a[i]):a[i];
		b1=b2;
		if (b2>max)
			max=b2;
	}
	if (max<0)
		max=0;
	long long b[50000],c[50000];
	long long max1=0,max2=0,sum1=0,sum2=0;
	sum1=a[0];
	b[0]=a[0]>0?a[0]:0;
	for(i=1;i<nu;i++)
	{
		sum1+=a[i];
		b[i]=b[i-1]>sum1?b[i-1]:sum1;
	}
	sum2=a[nu-1];
	c[nu-1]=a[nu-1]>0?a[nu-1]:0;
	for(i=nu-2;i>=0;i--)
	{
		sum2+=a[i];
		c[i]=c[i+1]>sum2?c[i+1]:sum2;
	}
	long max3=0;
	for(i=0;i<nu-1;i++)
	{
		max3=max3>b[i]+c[i+1]?max3:b[i]+c[i+1];
	}
	printf("%lld",max>max3?max:max3);
	return 0;
}

		
		




