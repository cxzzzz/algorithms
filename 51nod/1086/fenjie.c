#include<stdio.h>
long fenjie(long num,long *shuzu_baocun)
{
	long i=1,k=0;
	while(i<num){
		num-=i;
		shuzu_baocun[k++]=i;
		i*=2;
	}
	shuzu_baocun[k++]=num;
	return k;
}

int main(){
	long num;
	long a[100];
	scanf("%ld",&num);
	long c=fenjie(num,a);
	long k;
	for(k=0;k<c;k++)
		printf("%ld\n",a[k]);
}

	
