#include<stdio.h>
#define MAX 10001


int main(){
    int n; 
    scanf("%d",&n);
    int inputs[n];
    int results[MAX];
    
    for(int i=0;i<n;i++)
        scanf("%d", inputs + i);

    int K;
    scanf("%d",&K);

    int sum=0;
    int cnt=0;
    results[0]=1;
    for(int i=0;i<n;i++){
        sum = ((sum + inputs[i])%K + K) % K;
        cnt += results[sum];
        results[sum]++;
    }
    printf("%d",cnt);
    return 0;
}