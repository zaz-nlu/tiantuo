#include <stdio.h>

int main(){
    int max,min,max1,min1,max2,min2,n1,n2,n3,n4;

    printf("Enter four integers:");
    scanf("%d %d %d %d",&n1,&n2,&n3,&n4);
    if(n1>n2){
        max1=n1;
        min1=n2;
    }
    else{
        max1=n2;
        min1=n1;
    }

    if(n3>n4){
        max2=n3;
        min2=n4;
    }
    else{
        max2=n4;
        min2=n3;
    }

    if(max1>max2){
        max=max1;
    }
    else
        max=max2;

    if(min1>min2){
        min=min2;
    }
    else{
        min=min1;
    }

    printf("largest:%d\n",max);
    printf("Smallest:%d\n",min);

    return 0;
}