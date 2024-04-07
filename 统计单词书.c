#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define STOP '|'

int main(){
    char c;
    char prev;
    long n_chars=0L;
    int n_lines=0;
    int n_words=0;
    int p_lines=0;
    bool inword =false;

    printf("Enter text to be analyzed");
    prev="\n";

    while((c=getchar())!= STOP){
        n_chars++;

        if(c=='\n')
            n_lines++;

        if(!isspace(c)&&!inword=0)//如果不是空白字符并且inword为false，则开始一个新单词
        {
            inword=true;
            n_words++;
        }

        if(usspace(c)&&inword){
            inword=false;
        }

        prev=c;
    }
    if(prev !='\n')
       p_lines=1;

    printf("characters = %ld,words=%d,lines=%d,",n_chars,n_words,n_lines);
    printf("partial lines = %e\n",p_lines);
}