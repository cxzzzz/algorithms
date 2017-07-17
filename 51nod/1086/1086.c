#include<stdio.h>
int main(){
	long value;
	long weight;
	long mall;
	long num,num_wupin;
	long max[1000];
	scanf("%ld%ld",&num,&mall);
	long i, j,k;
	for(i=0;i<1000;i++)
		max[i]=0;
	for(i=1;i<=num;i++){
		scanf("%ld%ld%ld",&weight,&value,&num_wupin);
		for(j=mall;j>0;j--)
		{
			for(k=1;k<=num_wupin;k++){
				if(j-weight*k<0)break;	
				long max_with_i=max[j-weight*k]+value*k;
				max[j]=(max_with_i>max[j])?max_with_i:max[j];
			}
		}
	}
	printf("%ld",max[mall]);
}

