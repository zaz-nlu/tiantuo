#include <stdio.h>
int main(void){

    int i,fib_number[40];
    fib_number[0]=0;
    fib_number[1]=1;
    for(i=2;i<40;i++){
        fib_number[i]=fib_number[i-1]+fib_number[i-2];
    }
    printf("%2d",fib_number[i]);

    return 0;
}