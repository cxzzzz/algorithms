#include<stdio.h>
#define MAX(i,j) ((i)>(j)?(i):(j))
#define MIN(i,j) ((i)<(j)?(i):(j))
int main()
{
	int N,i,j,k,max=0,min=0,L;
	scanf("%d%d",&N,&L);
	for(i=0;i<N;i++)
	{
		scanf("%d",&j);
		int a=L-j;
		max=MAX(a,j)>max?MAX(a,j):max;
		min=MIN(a,j)>min?MIN(a,j):min;
	}
	printf("%d %d",min,max);
	return 0;
}

