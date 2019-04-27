#include<stdio.h>
int main(){
    int cnt[26];
    for(int i=0;i<26;i++)
        cnt[i]=0;
    char t;
    int cntall=0;
    while( (t=getchar()) !='\n'){
        cntall++;
        cnt[t-'a']++;
    }
    for(int i=0;i<26;i++){
        if( cnt[i]> (cntall+1)/2){
            printf("Impossible");
            return 0;
        }
    }
    printf("Possible");
    return 0;
}