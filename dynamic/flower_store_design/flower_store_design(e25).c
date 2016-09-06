#include<stdio.h>
#include<limits.h>
int main(){
	int F,V,i,j,k;
	scanf("%d%d",&F,&V);
	int value[F+1][V+1];
	int p[F+1][V+1];
	int q[F+1],R,max=INT_MIN;
	for(i=0;i<=F;i++)
		for(j=0;j<=V;j++)
			if(i==0||j==0){
				value[i][j]=0;
				p[i][j]=0;
				continue;
			}
			else
			{
				scanf("%d",&(value[i][j]));
				p[i][j]=INT_MIN;
			}

	for(i=1;i<=F;i++)
		for(j=V;j>=i;j--)
			for(k=j-1;k>=i-1;k--)  
				p[i][j]=(p[i][j]>p[i-1][k]+value[i][j])?p[i][j]:p[i-1][k]+value[i][j];
	
/*	for(i=V;i>0;i--)
		if(max<p[F][i])
			max=p[F][i];

	printf("%d\n",max);
*/
	int max_1;
	R=V;
	for(i=F;i>0;i--){
		max=INT_MIN;
		for(j=R;j>=i;j--)
		{
			
			if(max<p[i][j])
			{
				max=p[i][j];
				R=j;
			}
		}
		if(i==F)max_1=max;
		q[i]=R--;
	}
	printf("%d\n",max_1);
	for(i=1;i<=F;i++)
		printf("%d ",q[i]);

}
	
