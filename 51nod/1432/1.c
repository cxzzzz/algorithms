#include<stdio.h>
#define SWAP(a,b) do{long long __tmp__ ;__tmp__=a;a=b;b=__tmp__;}while(0);
int quick_sort(long long *array, int begin, int end)
{
	if (begin < end) {
		int i = begin, j = begin;
		while (i <= end) {
			if (array[i] <= array[end]) {
				SWAP(array[i], array[j]);
				j++;
			}
			i++;
		}
		quick_sort(array, begin, j - 2);
		quick_sort(array, j, end);
	}
	return 0;
}

int main()
{
	int n, m, i, j, k, num = 0;
	scanf("%d%d", &n, &m);
	long long array[n];
	for (i = 0; i < n; i++) {
		scanf("%lld", array + i);
	}
	quick_sort(array, 0, n - 1);
	i = 0, j = n - 1;
	while (i < j) {
		if (array[i] + array[j] <= m) {
			num++, i++, j--;
		} else {
			num++, j--;
		}
	}
	if (i == j)
		num++;
	printf("%d", num);
}
