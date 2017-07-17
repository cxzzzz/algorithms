#include<stdio.h>
#define STACK_IS_EMPTY (count_stack==0)
#define STACK_POP(i) (i)=stack[--count_stack];
#define STACK_ADD(i) stack[count_stack++]=(i);
typedef struct fish
{
	int size;
	int dir;
}Fish;


int main()
{
	int N,i,j,k;
	scanf("%d",&N);
	Fish stack[N];
	int count_stack=0;
	Fish fish1;
	for(i=0;i<N;i++)
	{
		scanf("%d%d",&(fish1.size),&(fish1.dir));
		if(fish1.dir==1)
		{
			STACK_ADD(fish1);
		}
		else{
			do{
				Fish fish2;
				if(STACK_IS_EMPTY)
				{
					STACK_ADD(fish1);
					break;
				}
				STACK_POP(fish2);
				if(fish2.dir==0)
				{
					STACK_ADD(fish2);
					STACK_ADD(fish1);
					break;
				}
				if(fish2.size>fish1.size)
				{
					STACK_ADD(fish2);
					break;
				}
				if(fish2.size<fish1.size)
				{
					continue;
				}
			}
		   while(1);
		}
	}
	printf("%d",count_stack);
	return 0;
}

		

