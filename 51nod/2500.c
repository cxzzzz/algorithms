#include <stdio.h>

#define MAX_LEN 120

int main()
{
    int n;
    scanf("%d", &n);
    int nums[n];
    int num_nexts[n];

    int pos[MAX_LEN];
    for (int i = 0; i < MAX_LEN; i++)
        pos[i] = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", nums + i);
        num_nexts[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        int value = nums[i];
        if (pos[value] >= 0)
            num_nexts[i] = pos[value];
        pos[value] = i;

        for (int j = 0; j < value; j++)
        {
            if (pos[j] >= 0)
            {
                int last = pos[j];
                do
                {
                    int t = last;
                    last = num_nexts[last];
                    num_nexts[t] = i - t;
                } while (last >= 0);
            }
            pos[j] = -1;
        }
    }
    for (int j = 0; j < MAX_LEN; j++)
    {
        if (pos[j] >= 0)
        {
            int last = pos[j];
            do
            {
                int t = last;
                last = num_nexts[last];
                num_nexts[t] = 0;
            } while (last >= 0);
        }
        pos[j] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", num_nexts[i]);
    }
    return 0;
}