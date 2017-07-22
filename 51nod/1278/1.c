#include<stdio.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define SWAP(i,j) tmp=(i);(i)=(j);(j)=tmp;
typedef struct line{
	int begin;
	int end;
}Line;
int quick_sort(Line* array,int begin,int end)
{
	if(begin>=end)return 0;
	int i=begin,j=begin;
	Line tmp;
	for(;i<=end;i++)
	{
		if(array[i].begin<array[end].begin || (array[i].begin==array[end].begin && array[i].end<=array[end].end))
		{	
			tmp=array[i];array[i]=array[j];array[j]=tmp;
			j++;
		}
	}
	quick_sort(array,begin,j-2);
	quick_sort(array,j,end);
	return 0;
}
int findgt(Line* array,int len,int begin)
{
	int i=0,j=len-1,mid;
	while(i<j)
	{
		mid=(i+j)/2;	
		if(array[mid].begin==begin)
		{
			while(array[++mid].begin==begin)
			return mid;
		}
		else 
		if(array[mid].begin>begin)
		{
			i=mid+1;
		}
		else
		if(array[mid].begin<begin)
		{
			j=mid-1;
		}
	}
	while(array[i].begin<=begin && i<len)i++;
	return i;
}

int main()
{
	int N,i,j,k,sum=0,a,b;
	scanf("%d",&N);
	Line array[N],max_end={0,0};
	for(i=0;i<N;i++)
	{
		scanf("%d%d",&a,&b);
		array[i].begin=a-b;
		array[i].end=a+b;
	}	
	quick_sort(array,0,N-1);
	for(i=0;i<N;i++)
	{
		k=findgt(array,N,array[i].end);
		sum+=(N-k);
	}
	printf("%d\n",sum);
}

