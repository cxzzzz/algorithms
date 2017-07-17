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


int find2(int *array,int N ,int K,int num1)
{

	int num=0;
	int i=0,j=N-1;
	while(i<j)
	{
		if(array[i]+array[j]==K)
		{	num++;
			printf("%d %d %d\n",num1,array[i],array[j]);
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
	return num;
}

int main()
{

	int N,i,j,k,num=0;
	scanf("%d",&N);
	int array[N];
	for(i=0;i<N;i++)
		scanf("%d",array+i);
	quick_sort(array,0,N-1);
	for(i=0;i<N;i++)
	{
		if(array[i]>=0)break;

		num+=find2(array+i+1,N-i-1,0-array[i],array[i]);
	}

	if(num==0)
		printf("No Solution\n");
}


