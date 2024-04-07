#include <stdio.h>
#include <stdbool.h>

int main(void){
    int digits;
    long n;
    bool repdigit[10]={false};
    bool repeated[10]={false}; 
    printf("Please enter number:");
    scanf("%ld",&n);

    while(n>0){
        digits=n%10;
        if(repdigit[digits]){
            repeated[digits]=true;
        }
        repdigit[digits]=true;
        n=n/10;
    }
    printf("Repeated number:");
    for(int i=0;i<10;i++){
        if(repeated[i]){
            printf("%d",i);
        }
    printf(" ");
    }
    return 0;

}