#include<stdio.h>
int main()
{
	int N,M,i,j,k;
	scanf("%d%d",&N,&M);
	int jing[N];
	for(i=N-1;i>=0;i--)
	{
		scanf("%d",jing+i);
	}
	for(i=N-2;i>=0;i--)
	{
		if(jing[i]>jing[i+1])
			jing[i]=jing[i+1];
	}
	int pos=0,num=0;
	for(i=0;i<M;i++)
	{
		scanf("%d",&k);
		while(k>jing[pos++] && pos<N);
		if(pos>N)break;
		if(k<=jing[pos-1])num++;
	}
	printf("%d",num);
	return 0;
}
	
