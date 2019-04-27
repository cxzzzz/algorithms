#include <stdio.h>
#include <limits.h>
int main(){
    int cnt;
    int zero_cnt=0,one_cnt=0;
    scanf("%d",&cnt);
    getchar();
    int min=INT_MAX;

    min = min >  (one_cnt - zero_cnt) ? ( one_cnt - zero_cnt) : min;
    for(int i=0;i<cnt;i++){
       char t=getchar() ;
       if( t =='0')
           zero_cnt++;
       else
           one_cnt++;
       min = min >  (one_cnt - zero_cnt) ? ( one_cnt - zero_cnt) : min;
    }

    min += zero_cnt;
    printf("%d",min);
}