#include<stdio.h>
int fenjie(long num_wupin,long * num_se);
int main(){
	long value;
	long weight;
	long mall;
	long num,num_wupin;
	long max[1000];
	long num_se[1000],num_se_len;
	scanf("%ld%ld",&num,&mall);
	long i, j,k;

	for(i=0;i<1000;i++)
		max[i]=0;
	for(i=1;i<=num;i++){
		scanf("%ld%ld%ld",&weight,&value,&num_wupin);
		num_se_len=fenjie(num_wupin,num_se);
					
		for(k=0;k<num_se_len;k++){
			if(num_se[k]==0)continue;
			if(j-weight*num_se[k]<0)break;
			for(j=mall;j>0;j--)
			{
				long max_with_i=max[j-weight*num_se[k]]+value*num_se[k];
				max[j]=(max_with_i>max[j])?max_with_i:max[j];
			}
		}
	}
	printf("%ld",max[mall]);

}
int fenjie(long num_wupin,long * num_se){
	long i=1;int a=0,len=0;
	while(i<num_wupin)i*=2,a++;
	len=a+1;
	for(;a>0;a--){
		i/=2;
		if(num_wupin>=i)num_wupin-=i,num_se[a]=i;
		else num_se[a]=0;
	}
		
	num_se[0]=num_wupin;

	return len;
}
