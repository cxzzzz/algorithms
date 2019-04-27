#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int max = 0;
    int last = 9;
    int weight = 1;
    while(n){
        int t=n%10;
        if(t<=last){
            max += t*weight;
            last = t ;
        }
        else {
            max = (n%10)*weight - 1;
            last = t - 1;
        }
        weight *= 10;
        n /= 10;
    }
    printf("%d",max);
    return 0;
}