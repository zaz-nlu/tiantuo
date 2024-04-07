#include <stdio.h>
#include <string.h>

int strcmp1(const char *s,const char *t);

int main(){
    char *str1= "Hello";
    char *str2= "HELLO";
    char *str3= "World";

    printf("Comparsion 1:%d\n",strcmp1(str1,str2));
    printf("Comparsion 2:%d\n",strcmp1(str1,str3));

    return 0;
}

int strcmp1(const char *s,const char *t){
    int i;
    while (*s == *t){
        if(*s){
            return 0;
        }
        s++;
        t++;
    }

    return *s-*t;
}