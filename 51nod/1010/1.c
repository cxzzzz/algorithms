#include<stdio.h>
#include<limits.h>

unsigned long long  find2(unsigned long long* array,unsigned long long num,unsigned long long begin,unsigned long long end)
{
	if(begin>=end)	return array[begin]>=num?array[begin]:array[begin+1];
	unsigned long long mid=(begin+end)/2;
	if(array[mid]==num)return array[mid];
	if(array[mid]<num)return find2(array,num,mid+1,end);
	if(array[mid]>num)return find2(array,num,begin,mid-1);
}
unsigned long long main()
{
	unsigned long long T,i,j,k,l;
	scanf("%d",&T);
	unsigned long long num;
	unsigned long long n2[61];
	for(i=0;i<61;i++)
	{
		n2[i]=((unsigned long long)1)<<i;
	}
	for(i=0;i<T;i++)
	{
		scanf("%lld",&num);
		unsigned long long n3=1,n5=1,n=LLONG_MAX;
		while(n5<num*5)
		{
			n3=1;
			while(n5*n3<num*5)
			{
				unsigned long long p=num/(n5*n3);
				unsigned long long p1=num%(n5*n3);
				if(p==0)
					n=n<n5*n3?n:n5*n3;
				else
				{
					if(p1!=0)p++;
					unsigned long long num1=n5*n3*find2(n2,p,0,60);
					n=n<num1?n:num1;
				}
				n3=n3*3;
			}
			n5=n5*5;
		}
		printf("%lld\n",n>=2?n:2);
	}
	return 0;
}


