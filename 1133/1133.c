#include<stdio.h>
#define MAX 10001
int main(){
	long num;
	int i,j,k;
	scanf("%ld",&num);
	long begin[num],end[num];
	long begin_temp,end_temp;
	long max=0,max_end,min_begin;
	scanf("%ld%ld",&begin_temp,&end_temp);
	begin[0]=(begin_temp<end_temp)?begin_temp:end_temp;
	end[0]=(begin_temp>=end_temp)?begin_temp:end_temp;
	max_end=end[0];
	min_begin=begin[0];

	
	for(i=1;i<num;i++){
		scanf("%ld%ld",&begin_temp,&end_temp);
		begin[i]=(begin_temp<end_temp)?begin_temp:end_temp;
		end[i]=(begin_temp>=end_temp)?begin_temp:end_temp;
		max_end=(max_end>end[i])?max_end:end[i];
		min_begin=(min_begin<begin[i])?min_begin:begin[i];
			
	}
	max_end++;

	long min_end=min_begin;
	while(1){
		long new_end=max_end;
		for(i=0;i<num;i++)
			if(end[i]<new_end&&begin[i]>=min_end)
				new_end=end[i];
		if(new_end==max_end)
			break;
		max++;
		min_end=new_end;
	}
	printf("%ld",max);
}
