#include <stdio.h>
#include <stdbool.h>
int main(){
    bool digit_seen[12]={false};
    bool repeated[10]={false};
    int digit,i;
    long n;

    printf("Please enter number:");
    scanf("%ld",&n);

    while(n>0){
        digit=n%10;//用这个方法来获得输入数字的最后一位。
        if(digit_seen[digit])//如果检查到这个数组为true，则说明重复了，被检查过了
            repeated[digit]=true;
        digit_seen[digit]=true;
        n/=10;   
     }
    
    printf("Repeated digits:");
    for(int i=0;i<10;i++){
        if(repeated[i]){
            printf("%d",i);
        }
    }
    return 0;
}
