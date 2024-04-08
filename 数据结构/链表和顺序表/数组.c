#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义动态数组的结构
typedef struct {
    int *array;   // 动态数组指针
    size_t used;  // 数组中已使用的元素数量
    size_t size;  // 数组的总大小
} ArrayList;

// 初始化动态数组
void initArrayList(ArrayList *a, size_t initialSize) {
    a->array = (int *)malloc(initialSize * sizeof(int)); // 分配初始大小的内存
    a->used = 0; // 初始化时没有元素
    a->size = initialSize; // 设置数组的初始大小
}

// 向动态数组中插入元素
void insertArrayList(ArrayList *a, int element) {
    // 如果数组已满，扩大数组大小
    if (a->used == a->size) {
        a->size *= 2; // 将数组大小加倍
        a->array = (int *)realloc(a->array, a->size * sizeof(int)); // 重新分配内存
    }
    a->array[a->used++] = element; // 在数组末尾插入元素并更新已使用的元素数量
}

// 从动态数组中移除指定索引的元素
void removeArrayList(ArrayList *a, int index) {
    if (index >= a->used) {
        printf("Index out of bounds\n"); // 索引超出范围时的错误处理
        return;
    }
    // 将要删除元素之后的所有元素向前移动一位
    for (int i = index; i < a->used - 1; i++) {
        a->array[i] = a->array[i + 1];
    }
    a->used--; // 更新已使用的元素数量
}

// 获取动态数组中元素的数量
size_t countArrayList(const ArrayList *a) {
    return a->used; // 返回数组中已使用的元素数量
}

// 判断动态数组是否为空
bool emptyArrayList(const ArrayList *a) {
    return a->used == 0; // 如果没有使用的元素，则数组为空
}

// 释放动态数组占用的内存
void freeArrayList(ArrayList *a) {
    free(a->array); // 释放数组内存
    a->array = NULL; // 将指针设置为NULL
    a->used = a->size = 0; // 重置元素数量和数组大小
}

int main() {
    ArrayList myList;
    initArrayList(&myList, 5);  // 使用初始大小为5初始化动态数组

    // 向数组中插入元素
    insertArrayList(&myList, 10); 
    insertArrayList(&myList, 20);
    insertArrayList(&myList, 30);

    printf("Count before removal: %zu\n", countArrayList(&myList)); // 移除前的元素数量

    removeArrayList(&myList, 1);  // 移除索引为1的元素

    printf("Count after removal: %zu\n", countArrayList(&myList)); // 移除后的元素数量
    printf("Is list empty? %s\n", emptyArrayList(&myList) ? "Yes" : "No"); // 判断数组是否为空

    freeArrayList(&myList);  // 释放动态数组占用的内存
    return 0;
}
