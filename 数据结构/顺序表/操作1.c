//想实现的操作就是插入，删除，判满
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef int datatype_t;

typedef struct{
    int id;
    char name[20];
    int score;
}STU;

typedef struct{
    datatype_t buf[MAX];//定义数组存储数据
    STU n;//数组中有效元素个数
}seqlist_t;

seqlist_t *create_empty_list(){
    seqlist_t* l = (seqlist_t *) malloc(sizeof(seqlist_t))
    if(NULL = l){
        printf("Malloc error");
        return;
    }
    memset(l,0,siezof(seqlist_t));
    return l;
}

void  *insert(seqlist_t *l,datatype_t data){
    l->buf[l->n] = data;
    l->n++;
    return;
}

void printf_seqlist(seqlist_t *l){
    int i;
    for(i=0;i<l->buf[l->n];i++){
        printf("%d",l->buf[i]);

    }
    printf("\n");
}

int is_full_seqlist(seqlist_t *l){
    return l->n == MAX ?1:0;
}



int main(){
    seqlist_t *l =create_empty_list();
    datatype_t data;
    printf("Please enter number:\n");
    while(!is_full_seqlist){
    scanf('%d',&data);
    insert(l,data);
    }
    printf_seqlist(l);
    free(l);
    l = NULL;
    return 0
}