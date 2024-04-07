#include <stdio.h>

int main(int argc,char *argv[]){
    int ages[] = {23, 43, 25, 30, 47, 50};
    char *names[] = {"Liu", "Ma", "Du", "Wang", "Chen", "Zhang"};

    int count = sizeof(ages) / sizeof(int);
    int i=0;

    for(i=0;i<count;i++){
        printf("%s has %d years alive.\n",names[i],ages[i]);
    }

    printf("-------------------------\n");

    char **cur_names =  names;
    int *cur_ages = ages;

    for(i=0;i<count;i++){
        printf("%s has %d years alive.\n",*(cur_names+i),*(cur_ages+i));//指针的运算
    }

    printf("--------------------------\n");

    for(i=0;i<count;i++){
        printf("%s has %d years alive.\n",cur_names[i],cur_ages[i]);
    }

    printf("---------------------------\n");

    for(cur_ages = ages,cur_names = names;(cur_ages-ages)<count;cur_ages++,cur_names++){
        printf("%s has %d years alive.\n",*cur_names,*cur_ages);
        
    }
    return 0;
}