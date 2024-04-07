#include <stdio.h>
#define ROWS 8
#define LINE 8
int main(){
    int i,j;
    char checker_board[ROWS][LINE];
    for(i=0;i<ROWS;i++){
        for(j=0;j<LINE;j++){
            if((i+j)%2==0){
                checker_board[i][j]='B';
            }
            else
                checker_board[i][j]='R';
        }
    }
    for(i=0;i<ROWS;i++){
        for(j=0;j<LINE;j++){
            printf("%c",checker_board[i][j]);
        }
        printf("\n");
    }
}