#include<stdio.h>
int main()
{
	int n, nu0, nu5, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int j;
		scanf("%d", &j);
		if (j == 0)
			nu0++;
		else
			nu5++;
	}
	if (nu5 >= 9 && nu0 > 0) {
		int k = (nu5 / 9) * 9;
		for (i = 0; i < k; i++)
			printf("5");
		for (i = 0; i < nu0; i++)
			printf("0");
	} else if (nu0 > 0) {
		printf("0");
	} else
		printf("-1");
	return 0;
}
