#include<stdio.h>
long long count(long long a,long long b,long long mod)
{
	long long base=a,result=1;
	while(b!=0){
		if(b&1)
			result*=(base%mod);
		b>>=1;
		base*=(base%mod);
	}
	return result;

}



				
			
int main(){
	int nu;
	scanf("%d",&nu);
	long long p[nu],m[nu];//n[nu];
	long long a=1,res=0;
	int i,j,k;
	for(i=0;i<nu;i++){
		scanf("%lld%lld",p+i,m+i);
		a*=(*(p+i));
	}
	for(i=0;i<nu;i++){
		long long a1=a/p[i];
		long long yushu=a1%p[i];
		long long a2=count(yushu,p[i]-2,p[i]);
		//n[i]=a1*a2*m[i];
		res+=a1*a2*m[i];
		res%=a;
	}
	printf("%lld",res);
		
}
