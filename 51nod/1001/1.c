#include<stdio.h>
#define SWAP(i,j) tmp=(i);(i)=(j);(j)=tmp;
int quick_sort(int * array,int begin,int end)
{
	if(begin>=end)return 0;
	int i=begin,j=begin;
	int tmp;
	for(;i<=end;i++)
	{
		if(array[i]<=array[end])
		{	
			tmp=array[i];array[i]=array[j];array[j]=tmp;
			j++;
		}
	}
	quick_sort(array,begin,j-2);
	quick_sort(array,j,end);
	return 0;
}
	

int main()
{

	int K,N,i,j,num=0;
	scanf("%d%d",&K,&N);
	int array[N];	
	for(i=0;i<N;i++)
		scanf("%d",array+i);
	quick_sort(array,0,N-1);
	/*for(i=0;i<N;i++)
		printf("%d ",array[i]);
		*/
	i=0;j=N-1;
	while(i<j)
	{
		if(array[i]+array[j]==K)
		{	num++;
			printf("%d %d\n",array[i],array[j]);
			i++;
			continue;
		}
		if(array[i]+array[j]>K)
		{
			j--;
		}
		if(array[i]+array[j]<K)
		{
			i++;
			j++;
		}
	}
	if(num==0)
		printf("No Solution");
}
			
	
