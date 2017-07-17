#include<stdio.h>
#include<math.h>
int main()
{
	int S,i,j;
	scanf("%d",&S);
	i=sqrt(S);
	for(j=i;j>0;j--)
	{
		if(S%j==0)
		{
			int k=S/j;
			printf("%d",(j+k)*2);
			return 0;
		}
	}
}
			

