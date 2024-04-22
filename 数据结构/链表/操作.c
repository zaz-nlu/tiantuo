#include "linkList.h"

linknode_t* creat_empty_linklist(){
    linknode_t *head = NULL;
    head = (linknode_t *) malloc (sizeof(linknode_t));

    if(NULL == head){
        printf("Malloc fail!");
        return NULL;
    }
    memset(head,0,sizeof(linknode_t));
    return head;
}

void insert_head_linklist(linknode_t *head,datatype_t data){
    linknode_t *temp = (linknode_t *)malloc(sizeof(linknode_t));
    if(NULL == temp){
        printf("malloc is fail!");
        return;
    }

    temp->data = data;

    temp->next = head ->next;
    head->next = temp;
    return;
}   

void printf_linklist(linknode_t *head){
    linknode_t *p = head;
    if(p==NULL){
        printf("The list empty.\n");
    }
    while(p->next != NULL){
        printf("%d",p->next->data);
        p=p->next;
    }
    return;
}