#include <stdio.h>
#include <ctype.h>

int capitalize(char str[]);

int main(){

}

// int capitalize(char str[]){
//     int i;
//     while(str[i] != '\0'){
//         if(isalpha(str[i])){
//             str[i] = toupper(str[i]);
//         }
//         i++;
//     }
// }


int capitalize(char *s){
    while(*s){
        if(isalpha(*s)){
            *s = toupper(*s);
        }
        s++;
    }
}