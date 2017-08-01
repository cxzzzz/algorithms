#include<stdio.h>
int scan_d(int *num)
{
	char in;
	*num = 0;
	int re = -1;
	in = getchar();
	while ((in < '0' || in > '9') && in != '-')
		in = getchar();
	if (in == '-') {
		re = 0;
		in = getchar();
	}
	while (in >= '0' && in <= '9')
    {
		*num = (*num) * 10 + in - '0';
        in=getchar();
    }
	if (re == 0)
		*num = 0 - *num;
	return re;
}

#define MAX 1000100
int num[MAX];
int main()
{
	int n, i, j, k;
	for (i = 0; i < MAX; i++)
		num[i] = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scan_d(&j);
		num[j]++;
	}
	int a, b, all = 0;
	for (i = 0; i < MAX; i++) {
		num[i + 1] =num[i+1]+ (num[i] / 2);
		num[i] = num[i] % 2;
		if (num[i] == 1)
			all++;
	}
	printf("%d", all);
}
