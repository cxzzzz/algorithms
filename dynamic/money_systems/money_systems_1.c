#include<stdio.h>
#define MAX 1000

int print(int ceng,int* value,int* guocheng,int value_nu){
	int i;
	for(i=value_nu-1;i>=ceng;i--)
	{
		if(guocheng[i]==0)continue;
		printf("%d*%d+ ",value[i],guocheng[i]);
	}
	printf("\n");
	return 0;
}

int bianli(int ceng,int num_last,int* guocheng,int *value,int value_nu)
{
	int k;
	if(ceng<0)return 0;
	for(k=0;k*value[ceng]<=num_last;k++){
		guocheng[ceng]=k;
		if(k*value[ceng]==num_last)
			print(ceng,value,guocheng,value_nu);
		else
			bianli(ceng-1,num_last-k*value[ceng],guocheng,value,value_nu);
	}
	return 0;
}

int main()
{
	int value_nu,value[MAX],num;
	int guocheng[MAX];
	scanf("%d%d",&value_nu,&num);
	int opt[value_nu][num+1];
	int i,j,k;
	for(i=0;i<value_nu;i++)
		for(j=1;j<num+1;j++)
			opt[i][j]=0;
	for(i=0;i<value_nu;i++)
		opt[i][0]=1;
	for(i=0;i<value_nu;i++)
		scanf("%d",value+i);
	for(i=0,j=num;j>=1;j--)
		for(k=1;value[i]*k<=j;k++)
			opt[i][j]+=opt[i][j-value[i]*k];
		
	for(i=1;i<value_nu;i++)
		for(j=num;j>=1;j--)
		{	opt[i][j]+=opt[i-1][j];
			for(k=1;value[i]*k<=j;k++)
				opt[i][j]+=opt[i-1][j-value[i]*k];
		}
	printf("%d\n",opt[value_nu-1][num]);
	bianli(value_nu-1,num,guocheng,value,value_nu);
}


