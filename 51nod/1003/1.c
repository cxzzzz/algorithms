#include<stdio.h>
int main()
{

	int N;
	scanf("%d",&N);
	int i=1,j=0,k;
	while(i<N)i=i*10,j++;
	int num_with_all=0,num_only_5=0;
	for(;j>0;j--)
	{
		num_with_all+=N/i;
		k=N/(i/2)-N/i;
		num_only_5+=k;
	}
	printf("%d",num_with_all+num_only_5);
}


	
		


