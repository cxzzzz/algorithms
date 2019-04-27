#include <stdio.h>

int main()
{
    int cnt;
    scanf("%d", &cnt);
    getchar();
    int pairs[cnt];
    int array[cnt];
    int max = 0;
    for (int i = 0; i < cnt; i++)
    {
        //array[i]=getchar()-'0';
        scanf("%d", array + i);
        if (i == 0)
            pairs[i] = 1;
        else if ( pairs[i-1] -1 < 0 || array[pairs[i - 1] - 1] == array[i])
        {
            int not_pair = 1;
            int p;
            for (p = pairs[i - 1]; p < i; p++)
            {
                if (array[p] == array[i])
                    not_pair--;
                else
                    not_pair++;
                if (not_pair == 0)
                    break;
            }
            pairs[i] = p + 1;
        }
        else
        {
            if( pairs[i-1] - 2 < 0)
                pairs[i] = pairs[i-1] - 1;
            else
                pairs[i] = pairs[pairs[i - 1] - 2];
        }
        int len = i - pairs[i] + 1;
        max = len > max ? len : max;
    }

    printf("%d",max);

    return 0;
}