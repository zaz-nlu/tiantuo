#include <stdio.h>

#define N 10

int read_line(char str[],int n);

int main(){
    char a[N];
    printf("Please enter something:");
    // read_line(a,N);
    // scanf("%s",a);
    gets(a);

    printf("The string content is : %s",a);
    
}
int read_line(char str[],int n){
    int ch,i=0;

    while((ch = getchar()) != '\n'){
        if(i<n){
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}