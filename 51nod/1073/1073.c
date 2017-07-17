//f(n)=(f(n-1)+k)/n,f(n)+1为结果
#include<stdio.h>
int main(){
	int n,k;
	int re=0;
	int i;
	scanf("%d",&n);
	scanf("%d",&k);
	for(i=2;i<=n;i++)
		re=(re+k)%i;
	printf("%d",re+1);
}



