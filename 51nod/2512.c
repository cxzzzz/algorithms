#include <stdio.h>

int table[] = {100000000, 10, 111001100, 100110, 10000, 100000110, 212010011, 1000031011, 2201000, 401001001, 102221100, 1020210, 1111101111, 101011010, 1100100, 1000010, 1100, 1010000, 1001010001, 120011220, 32000120, 10001121, 100, 1100000110, 1010100211, 100010101, 200110200, 111110011, 223100, 10111};

int pow_10( int i){
    int t=1;
    for( int j=0;j<i;j++)
    t*=10;
    return t;
}

int main(){
    int n;
    scanf("%d",&n);
    int reg=0;
    while(n!=0){
        int t= n%10; 
        reg +=  pow_10(t);
        n /= 10;
    }

    for (int i = 0; i < sizeof(table) / sizeof(int); i++)
    {
        if (reg == table[i])
        {
            printf("true");
            return 0;
        }
    }
    printf("false");
    return 0;
}