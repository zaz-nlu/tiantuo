#include <stdio.h>
#define N 10

int main(){
    int a[N],i;

    printf("Please enter number in array:\n");
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
    }

    printf("Let us reserve array:");
    for(i=N-1;i>=0;i--){
        printf("%d ",a[i]);
    }
    printf("\n");

    return 0;
}