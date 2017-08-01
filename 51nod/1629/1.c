#include<stdio.h>
#include<math.h>
int main()
{
	long long S;
	scanf("%lld", &S);
	double V = 1;
	V = sqrt(S * S * S / 72.0 / M_PI);
	printf("%.6lf", V);
}
