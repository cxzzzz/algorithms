#include<stdio.h>
#define uint unsigned int
int main()
{
	uint X,N,Y,i,j;
	uint Xbit[32];
	uint bit[32];
	scanf("%u%u",&N,&X);		
	for(i=0;i<32;i++)	
	{
		if((X&(1<<i))!=0)
			Xbit[i]=1;
		else 
			Xbit[i]=0;
		bit[i]=0;
	}
	for(i=0;i<N;i++)
	{
		scanf("%u",&Y);
		if( (((Y|X)&X)==X) && ((Y|X)!=X))
			continue;

		for(j=0;j<32;j++)
		{
			if((Y&(1<<j))!=0)
				bit[j]=bit[j]+1;
		}
	}
	int min=1000000;
	for(i=0;i<31;i++)
	{
		if(Xbit[i]!=0) 
		{
			if(bit[i]==0)
			{
				printf("0\n");
				return 0;
			}
			else
			{
				min=min<bit[i]?min:bit[i];
			}

		}
	}
	printf("%d\n",min);
	return 0;
}

	


			
	
