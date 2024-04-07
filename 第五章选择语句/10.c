#include <stdio.h>
int main(void){
    int grade;

    printf("Enter your socre:");
    scanf("%d",&grade);
    
    switch(grade/10){
        case 0:case1:case2:case3:case4:case5:
            printf("Letter grade:F");
            break;

        case 6:
            printf("Letter grade:D");
            break;

        case 7:
            printf("C");
            break;

        case 8:
            printf("B");
            break;

        case 9:case 10:
            printf("A");
            break;

        default:
            printf("Error");
            break;
    }

    return 0;
}