#include <stdio.h>
#include <ctype.h>
#define N 50
int censor(char str[]);

int main(){
    char input[N];
    int i;

    for(i=0;i<N;i++){
        scanf("%c",&input[i]);
    }
    
    printf("Before :%s\n",input);
    
    censor(input);

    printf("After: %s\n",input);

    return 0;
}

int censor(char str[]){
    char *s = str;
    while(*(s+2)){
        if(*s == 'f' && *(s+1) == 'o' && *(s+2) == 'o'){
            *s = *(s+1) = *(s+2) = 'x';
        }

        s++;
    }
    

}