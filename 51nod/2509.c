#include <stdio.h>
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main(){
    int max=0;
    int n;
    scanf("%d",&n);


    int last = 1000000;
    int begin = 0 ;
    int enable = 0 ;
    int direction = -1;
    int i;
    for(i=0;i<n;i++){
        int input ; 
        scanf("%d",&input);
        int dir_t=input-last;
        if( dir_t ==0 ){
            if(enable){
                max = MAX(max, i - begin);
            }
            begin = i;
        }
        else if( direction < 0){
            if(dir_t <0);
            else if(dir_t > 0){
                if(enable){
                    max = MAX(max, i - begin);
                }
                begin = i - 1;
                enable = 1;
            }
        }
        else if(direction > 0 ){
            ;
        }
        direction = dir_t;
        last = input;
    }
    max = MAX(max,i - begin);
    if(max < 3)max = 0;
    printf("%d",max);
    return 0;
}