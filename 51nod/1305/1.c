#include<stdio.h>
int main()
{
	int nu1=0,nu2=0,nuo=0,N,i,k;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&k);
		if(k==1)nu1++;
		else if(k==2)nu2++;
	}
	nuo=N-nu1;
	printf("%d\n",(nu1*(nu1-1)+nu2*(nu2-1)/2+nuo*nu1));
	return 0;
}
