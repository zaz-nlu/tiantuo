#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int datatype_t;
typedef struct node{
    datatype_t data; //指针域保存有效数字
    struct node *next;
}linknode_t;

#endif