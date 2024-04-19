#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef int datatype_t;

typedef struct {
    int id;
    char name[20];
    int score;
} STU;

typedef struct {
    datatype_t buf[MAX]; // 定义数组存储数据
    int n;               // 数组中有效元素个数
} seqlist_t;

seqlist_t *create_empty_list() {
    seqlist_t* l = (seqlist_t *) malloc(sizeof(seqlist_t));
    if (l == NULL) {
        printf("Malloc error\n");
        return NULL;
    }
    memset(l, 0, sizeof(seqlist_t));
    return l;
}

void insert(seqlist_t *l, datatype_t data) {
    if (l->n < MAX) {
        l->buf[l->n] = data;
        l->n++;
    } else {
        printf("List is full\n");
    }
}

void print_seqlist(seqlist_t *l) {
    for (int i = 0; i < l->n; i++) {
        printf("%d ", l->buf[i]);
    }
    printf("\n");
}

int is_full_seqlist(seqlist_t *l) {
    return l->n == MAX;
}

int main() {
    seqlist_t *l = create_empty_list();
    if (l == NULL) return -1;
    
    datatype_t data;
    printf("Please enter numbers (up to 10):\n");
    while (!is_full_seqlist(l)) {
        if (scanf("%d", &data) != 1) {
            printf("Invalid input\n");
            break;
        }
        insert(l, data);
    }
    print_seqlist(l);
    free(l);
    l = NULL;
    return 0;
}
