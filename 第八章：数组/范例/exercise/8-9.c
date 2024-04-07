#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define MONTH 30
#define HOUR 24
int main(){
    int i,j;
    double average=0.0;

    srand(time(NULL));

    double temperature_reading [MONTH][HOUR];
    for(i=0;i<MONTH;i++){
        for(j=0;j<HOUR;j++){
             temperature_reading[i][j] = rand() % 101 / 10.0;
        }
    }
    for(i=0;i<MONTH;i++){
        for(j=0;j<HOUR;j++){
            average+=temperature_reading[i][j];
        }
    }
    average/=MONTH*HOUR;
    printf("%3.2lf",average);
}