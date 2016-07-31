#include<stdio.h>
#define MAX 1000

int main()
{
	int value_nu,value[MAX],num,opt[MAX][2];
	int i,j,k,l;
	for(i=1;i<MAX;i++)
		opt[i][0]=0;
	opt[0][0]=1;
	scanf("%d%d",&value_nu,&num);
	for(i=0;i<value_nu;i++)
		scanf("%d",value+i);
	for(i=0;i<value_nu;i++)
		for(j=num;j>=1;j--)
		{
			if(opt[j][0]!=0)continue;
			for(k=1;value[i]*k<=j;k++)
				if(opt[j-value[i]*k][0]!=0)
				{
					opt[j][0]=k;
					opt[j][1]=value[i];
					break;
				}
		}

	if(!opt[num][0]){
		printf("error");
		return 0;
	}

	i=num;
	while(i>0)
	{
		printf("%d*%d+",opt[i][0],opt[i][1]);
		i-=opt[i][0]*opt[i][1];
	}
}


