#include<stdio.h>
int main(){
	long value;
	long weight;
	long mall;
	long num;
	long max[1000];
	scanf("%ld%ld",&num,&mall);
	long i, j;
	for(i=0;i<1000;i++)
		max[i]=0;
	for(i=1;i<=num;i++){
		scanf("%ld%ld",&weight,&value);
		for(j=mall;j>0;j--)
		{
			long max_with_i=(j-weight>=0)?max[j-weight]+value:0;
			long max_without_i=max[j];
			max[j]=(max_with_i>max_without_i)?max_with_i:max_without_i;
		}
	}
	printf("%ld",max[mall]);

}

