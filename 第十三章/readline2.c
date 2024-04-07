#include <stdio.h>
#include <ctype.h>

int read_line(char str[],int n);

int main(){

}

int read_line(char str[],int n){
    int ch,i=0;

    while(isspace(getchar())){
        ;
    }

    while((ch=getchar()) != '\n' && !isspace(ch)){
        str[i++] = ch;
    }

    if(ch == '\n'){
        str[i++] == '\n';
    }

    str[i++] = '\0';
    return i;
}