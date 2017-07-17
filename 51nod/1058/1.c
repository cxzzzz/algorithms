#include<stdio.h>
#include<math.h>
//斯特林公式
int main()
{
	long N;
	double len;
	scanf("%ld",&N);
	len=(double)N*log10((double)N/M_E)+0.5*log10(2*M_PI*(double)N);
	printf("%lld",(long long)len+1);
	return 0;
}
	
