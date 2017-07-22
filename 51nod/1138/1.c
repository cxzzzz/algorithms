#include<stdio.h>
#include<math.h>
int main()
{
	int N,i,j,k=0;
	scanf("%d",&N);
	for(i=(int)(2*sqrt(N/2)+1);i>1;i--)
	{
		if(i%2)//奇数	
		{
			if(N%i==0)
			{
				j=N/i;
				if(j-i/2>0)
				{
					printf("%d\n",j-i/2);
					k++;
				}
			}
		}
		else
		{
			if(N%i==i/2)
			{
				j=N/i;
				if(j-i/2+1>0)
				{
					printf("%d\n",j-i/2+1);
					k++;
				}
			}
		}
	}
	if(k==0)
		printf("No Solution\n");
	return 0;
}	
