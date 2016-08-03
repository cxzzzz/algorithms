#include<stdio.h>
#include<limits.h>
int main(){
	int num,m,t_all,value,t;
	int i,j,k,l;
	scanf("%d%d%d",&num,&m,&t_all);
	int p[m+1][t_all+1];
	for(i=0;i<=m;i++)
		for(j=0;j<=t_all;j++)
			p[i][j]=INT_MIN;
	for(i=0;i<=t_all;i++)
		p[0][i]=0;
	for(i=0;i<num;i++)
	{
		scanf("%d%d",&t,&value);
		for(j=m;j>0;j--)
			for(k=t_all;k>=t;k--)
				p[j][k]=(p[j][k]>p[j-1][k-t]+value)?p[j][k]:p[j-1][k-t]+value;
	}
	if(p[m][t_all]>0)
		printf("%d",p[m][t_all]);
	else
		printf("error");
	return 0;
}
