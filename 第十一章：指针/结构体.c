#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct{//定义一个结构体，创建一个人
    char *name;
    int height;
    int weight;
    int age;
}Person;

Person *person_create(char *name,int height,int weight,int age)
{
    Person *who = malloc(sizeof(Person));//利用结构体Person创建一个变量，然后malloc用于分配内存，分配内存的大小等于sizeof（person），*who即让who指向这块内存
    assert(who != NULL);//确保分配的内存争取

    who->name = strdup(name);//因为name是*name在person里，所以不能直接赋值，要用strdup复制过来并返回一个字符串指针
    who -> age = age;
    who -> height = height;
    who -> weight = weight;

    return who;
}  

void person_destory(Person *who){//释放内存
    assert(who != NULL);

    free(who -> name);
    free(who);
}

void *person_printf(Person *who){//打印
    printf("The name is %s\n",who -> name);
    printf("The age is %d \n",who -> age);
    printf("The height is %d\n",who -> height);
    printf("The weight is %d\n",who -> weight); 
}

int main(int argc,char *argv[]){
    Person *Joe = person_create("Joe",24,178,180);
    Person *Jhon = person_create("Jhon",18,188,170);

    printf("Joe location is %p\n",Joe);
    person_printf(Joe);

    printf("Jhon location is %p\n",Jhon);
    person_printf(Jhon);

    Joe -> age += 20;
    Joe -> height -= 6;
    Joe -> weight +=10;

    person_printf(Joe);

    Jhon -> age += 9;
    Jhon -> height += 5;
    Jhon -> weight -= 8;

    person_printf(Jhon);

    person_destory(Joe);
    person_destory(Jhon);

    return 0;

}
