#include <stdio.h>
int main(void){
    int wage;
    int taxes;
    printf("Please enter your wage:");
    scanf("%d",&wage);
    if(wage<=750){
        taxes = wage*0.01;
    }
    else if(wage>750&&wage<=2250){
        taxes=7.5+(wage-750)*0.02;
    }
    else if(wage>2250&&wage<=3750){
        taxes=37.5+(wage-2250)*0.03;
    }
    else if(wage>3750&&wage<=5250){
        taxes=82.5+(wage-3750)*0.04;
    }
    else if(wage>5250&&wage<=7000){
        taxes=142.5+(wage-5250)*0.05;
    }
    else
        taxes=230+(wage<7000)*0.06;

    printf("You wage is %d and you taxes is %d",wage,taxes);
    return 0;
    
}