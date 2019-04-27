#include <stdio.h>
#define MAX 30005
int main()
{
    int n;
    scanf("%d", &n);
    int inputs[n];
    int results[n+1];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", inputs + i);
        results[i]=0;
    }
    int S;
    scanf("%d", &S);

    int res_last = 0;
    int cnt = 0;
    results[0] = 1;
    for (int i = 0; i < n; i++)
    {
        res_last += inputs[i];
        if (res_last >= S)
        {
            cnt += results[res_last - S] ;
        }
        results[res_last]++;
    }
    printf("%d", cnt);
    return 0;
}