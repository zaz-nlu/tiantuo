#include <stdio.h>
#include <string.h>
int main(void){
    int number;
    int digits;
    printf("Enter a number:\n");
    scanf("%d",&number);
    if(number>=0&&number<10){
        digits=1;
    }
    if(number>=10&&number<100){
        digits=2;
    }
    if(number>=100&&number<1000){
        digits=3;
    }
    printf("The number %d has %d digits",number,digits);
    return 0;
}