#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
    char name[20];
    int id;
    int score;
} STU;

typedef int datatype_t;

typedef struct {
    datatype_t buf[MAX];
    int n;
} Seqlist_t;

Seqlist_t *Creat_empty_() {
    Seqlist_t* l = (Seqlist_t *)malloc(sizeof(Seqlist_t));
    if (NULL == l) {
        printf("内存分配错误。");
        return NULL;
    }
    memset(l, 0, sizeof(Seqlist_t));
    return l; // 不要忘记返回创建的列表
}

void Insert_list(Seqlist_t *l, datatype_t data) {
    if (l->n < MAX) {
        l->buf[l->n] = data;
        l->n++;
    } else {
        printf("列表已满！");
    }
}

int Full_list(Seqlist_t *l) {
    return l->n == MAX ? 1 : 0;
}

int Empty_list(Seqlist_t *l) {
    return l->n == 0 ? 1 : 0; 
}

void printf_list(Seqlist_t *l) {
    for (int i = 0; i < l->n; i++) {
        printf("%d ",l->buf[i]);
    }
}

int Delete_list(Seqlist_t *l, datatype_t data) {
    if (Empty_list(l)) {
        return -1; // 表示列表为空
    }

    int i = 0,j = 0;
    for (int i = 0; i < l->n; i++) {
        if (l->buf[i] != data) { // 假设根据学号删除
            l->buf[j] = l->buf[i];
            j++;
        }
    }

    l->n = j;

    if (i == j) {
        return -2; // 表示未找到要删除的元素
    } else {
        printf("删除成功！\n");
    }

    return 0; // 表示成功
}

int main() {
    Seqlist_t *l = Creat_empty_();
    if (NULL == l) {
        return -1;
    }
    int data;
    int ret = 0;
    printf("请输入10条记录：\n");
    while(!Full_list(l)){
        scanf("%d",&data);
        Insert_list(l,data);
    }
    printf("==========================================\n");
    printf("列表中的记录：\n");
    printf_list(l);

    printf("==========================================\n");
    printf("请输入要删除的记录的学号：");
    scanf("%d", &data);

    ret = Delete_list(l, data);
    if (ret < 0) {
        printf("列表为空或未找到记录。\n");
        return -1;
    }
    printf("更新后的列表：\n");
    printf_list(l);

    free(l);
    l = NULL;
    return 0;
}
