#include<stdio.h>//使用回溯法
int huisu(long shuliang,long value,long weight1);
long value[10000];
long weight[10000];
long mall;
long num;
long max=0;


int main(){
		scanf("%ld%ld",&num,&mall);
	long i, j;
	for(j=0;j<num;j++)
		scanf("%ld%ld",&weight[j],&value[j]);
	huisu(0,0,0);
	printf("%ld",max);

}
int huisu(long shuliang,long value1,long weight1){
	if (shuliang>=num)
		max=(max>value1)?max:value1;
	else{
	huisu(shuliang+1,value1,weight1);
	if(mall>=weight1+weight[shuliang])
	huisu(shuliang+1,value1+value[shuliang],weight1+weight[shuliang]);
	}
}

		
