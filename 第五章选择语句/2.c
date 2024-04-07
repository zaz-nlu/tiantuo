#include <stdio.h>
#include <string.h>

int main(void) {
    int hour, min;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &min);

    char period[3];
    if(hour<12){
        strcpy(period,"AM");
    }
    else
        strcpy(period,"PM");
    
    if(hour==0){
        hour=12;
    }
    else if(hour>12){
        hour=hour-12;
    }
    printf("Equivalent 12-hour time: %d:%02d %s", hour, min, period);
    return 0;
}
