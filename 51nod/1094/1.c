#include<stdio.h>
//二分法
int pos_begin=100000,pos_end=100000;
int divide(int *array,begin,end,K)
{
	int mid=(begin+end)/2,i,j;
	//then?

}
int main()
{
	int N,K,i,j,k;
	scanf("%d",&N);
	int A[N];
	for(i=0;i<N;i++)
	{
		scanf("%d",A+i);
	}
	divide(A,begin,end,K);	
	if(pos_begin>N)
		printf("No Solution\n");
	else
	{
		printf("%d %d\n",pos_begin,pos_end);
	}
}
	
