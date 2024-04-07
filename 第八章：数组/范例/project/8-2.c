#include <stdio.h>
#include <stdbool.h>
int main(void){
    int digit,i;
    long n;
    int count_num[10]={0};

    printf("Please enter number:");
    scanf("%ld",&n);

    while(n>0){
        digit=n%10;
        count_num[digit]++;
        n=n/10;

    }
    printf("Digit:\t\t0 1 2 3 4 5 6 7 8 9\n");
    printf("Occurrences:\t");
    for(int i=0;i<10;i++){
        printf("%2d",count_num[i]);
    }
    printf("\n");
    return 0;

}