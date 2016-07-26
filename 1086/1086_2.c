#include<stdio.h>
long fenjie(long num,long *shuzu_baocun)
{
	long i=1,k=0;
	while(i<num){
		num-=i;
		shuzu_baocun[k++]=i;
		i*=2;
	}
	shuzu_baocun[k++]=num;
	return k;
}

int main(){
	long value;
	long weight;
	long mall;
	long num,num_wupin;
	long max[5000];
	long num_se[5000],num_se_len;
	scanf("%ld%ld",&num,&mall);
	long i, j,k;

	for(i=0;i<5000;i++)
		max[i]=0;
	for(i=1;i<=num;i++){
		scanf("%ld%ld%ld",&weight,&value,&num_wupin);
		num_se_len=fenjie(num_wupin,num_se);
					
		for(k=0;k<num_se_len;k++){
			for(j=mall;j>0;j--)
			{
				if(j-weight*num_se[k]<0)continue;
				long max_with_i=max[j-weight*num_se[k]]+value*num_se[k];
				max[j]=(max_with_i>max[j])?max_with_i:max[j];
			}
		}
	}
	printf("%ld",max[mall]);

}

