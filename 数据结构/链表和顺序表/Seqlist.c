#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void SeqList;
typedef void SeqListNode;

typedef struct head{
    int capacity; // 容量
    int length;   // 当前长度
    int *node;    // 指向元素的指针
} Head;

//创建顺序表
SeqList* SeqList_Create(int capacity){
    int ret;
    Head *temp = NULL;
    temp = (Head*)malloc(sizeof(Head));
    if(temp == NULL){//检查内存是否正常分配
        ret = 1;
        printf("fun create error:%d\n",ret);
        return NULL;
    }
    memset(temp,0,sizeof(Head));//用于内存初始化，将temp指向的结构体Head都初始化为0
    temp->capacity=capacity;//设置容量和长度
    temp->length=0;
    temp->node = (int*)malloc(sizeof(void*)*capacity);//给node分配capacity大小内存
    if(temp->node == NULL){
        ret = 2;
        printf("fun error:%d\n",ret);
        return NULL;
    }
    return temp;

}

int Seqlist_Capacity(SeqList* list){
    if(list == NULL){
        return 0;
    }
    return list->capacity;
}

int Seqlist_list(SeqList* list){
    if(list == NULL ){
        return 0;
    }
    return list->length;
}

int Seqlist_IsEmptu(Seqlist* list){
    if(list == NULL || list->lenght==0 ){
        return 1;
    }

    return 0;

}

int Seqlist_Insert(SeqList* list,SeqListNode* node,int pos){
    
}