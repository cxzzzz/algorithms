#include<stdio.h>

typedef struct work{
	long long time;
	long long money;
}Work;

#define SWAP(i,j) do{ Work tmp=(i);(i)=(j);(j)=tmp;}while(0);

int heap_num=0;

int heap_add(Work * heap,Work a)
{
	int i=heap_num;
	heap[heap_num++]=a;	
	while(i>0 && heap[i].money>heap[(i-1)/2].money)
	{
		SWAP(heap[i],heap[(i-1)/2]);
		i=(i-1)/2;
	}
}
Work heap_pop(Work* heap)
{
	Work tmp1=heap[0];
	if(heap_num==0){
		tmp1.money=0;
		return tmp1 ;
	}
	heap[0]=heap[--heap_num];
	int i=0;
	while(i<heap_num)
	{

		int m;
		if(2*i+1>=heap_num)break;
		if(2*i+2>=heap_num)	m=2*i+1;
		else
			m=heap[2*i+1].money>heap[2*i+2].money?2*i+1:2*i+2;
		if(heap[i].money<heap[m].money)
		{
			SWAP(heap[i],heap[m]);
			i=m;
			continue;
		}
		break;
	}
	return tmp1;
}


int quicksort(Work* array,int begin,int end)
{
	if(begin>=end)return 0;
	int i=begin,j=begin;
	for(;i<=end;i++)
	{
		if(array[i].time<=array[end].time)
		{
			Work tmp=array[i];
			array[i]=array[j];
			array[j++]=tmp;
		}
	}
	quicksort(array,begin,j-2);
	quicksort(array,j,end);
}





int main()
{
	int N,i,k;
	scanf("%d",&N);
	Work array[N];	
	Work heap[N];
	for(i=0;i<N;i++)
	{
		scanf("%lld%lld",&(array[i].time),&(array[i].money));
	}
	quicksort(array,0,N-1);
	long long max=0,sum=0,j=N-1;	
	for(i=array[N-1].time;i>=1;i--)
	{
		while(j>=0 && array[j].time>=i)
			heap_add(heap,array[j--]);
		Work tmp=heap_pop(heap);
		for(k=0;k<heap_num;k++){
			if(tmp.money<heap[k].money)
			{
				printf("errorfeeeeeeee\n");
				while(1);
			}
		}
		sum+=tmp.money;
	}
	printf("%lld",sum);
	return 0;
}

		




