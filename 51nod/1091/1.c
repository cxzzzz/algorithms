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


int main()
{
	int N,i,j,k,max_len=0;
	scanf("%d",&N);
	Line array[N],max_end={0,0};
	for(i=0;i<N;i++)
		scanf("%d%d",&(array[i].begin),&(array[i].end));
	quick_sort(array,0,N-1);
	for(i=0;i<N;i++)
	{
		//printf("%d %d\n",array[i].begin,arry[i].end);
		int len=min(array[i].end,max_end.end)-max(array[i].begin,max_end.begin);
		max_len=max_len>len?max_len:len;
		max_end=array[i].end>max_end.end?array[i]:max_end;
	}
	printf("%d\n",max_len);
}

