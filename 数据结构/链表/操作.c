#include "listLnode.h"

Listnode_t* Creat_empty_list( datatype_t data){
    Listnode_t *head = NULL;
    head = (Listnode_t *) malloc (sizeof(Listnode_t));

    if(NULL == head){
        printf("Malloc fail");
        return NULL;
    }
    memset(head,0,sizeof(Listnode_t));
    return head;
}

// void head_insert(Listnode_t *head,datatype_t data){
//     if (head == NULL) {
//         printf("Invalid head pointer\n");
//         return;
//     }
//     Listnode_t *temp =(Listnode_t *)malloc(sizeof(Listnode_t));
//     if(NULL == temp){
//         printf("Malloc fail");
//         return;
//     }
//     temp->data = data;
//     temp->next = head->next;
//     head->next =temp;

//     return;

// }
void tail_insert(Listnode_t *head,datatype_t data){
    Listnode_t *temp = (Listnode_t *) malloc(sizeof(Listnode_t));
    if(NULL == temp){
        printf("内存申请错误.");
        return;
    }
    Listnode_t *p = head;
    temp->data = data;
    temp->next = NULL;
    while(p->next != NULL){
        p=p->next;
    }
    temp->next = p->next;
    p->next = temp;
}

void printf_linkList(Listnode_t *head){
    Listnode_t *p = head;
    if(NULL == head){
        printf("Malloc fail");
        return ;
    }
    while(p->next!=NULL){
        printf("%d ",p->next->data);
        p=p->next;
    }
    return;
}

int main(){
    Listnode_t *head =NULL;
    datatype_t data;
    int n=0,i=0;

    head = Creat_empty_list(data);
    printf("请输入你想插入的数字个数:\n");
    scanf("%d",&n);

    printf("请输入%d个数字: ",n);
    for(i=0;i<n;i++){
        scanf("%d",&data);
        tail_insert(head,data);
    }
    printf_linkList(head);

    Listnode_t *temp;
    while(head != NULL){
        temp = head->next;
        free(head);
        head = temp;

    }
    return 0;
}
