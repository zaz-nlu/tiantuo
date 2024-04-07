#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50 //最大的提示信息数量
#define MSG_LEN 60 //提示信息长度

int read_line(char str[],int n);

int main(){
    char reminders [MAX_REMIND][MSG_LEN + 3];//存储提示信息的数组
    char day_str[3],msg_str[MSG_LEN+1];//存储天数和提示信息的字符数组
    int day,i,j,num_remind = 0;//天数，循环计数和提示信息

    for(;;){
        if(num_remind == MAX_REMIND){
            printf("-- No space left --\n");
            break;
        }
        printf("Enter day and reminder:");//输入天数和提示信息
        scanf("%2d",&day);
        if(day == 0){
            break;
        }
        sprintf(day_str,"%2d",day);
        read_line(msg_str,MSG_LEN);

        for(i=0;i<num_remind;i++){// 查找合适的插入位置
            if(strcmp(day_str,reminders[i])<0)
                break;
        }
        
        for(j = num_remind ;j>i;j--) // 向后移动数组元素为新提示信息腾出位置
            strcpy(reminders[j],reminders[j-1]);

        strcpy(reminders[i],day_str); // 插入新的提示信息
        strcat(reminders[i],msg_str);

        num_remind++;
    }
    printf("\nDay Reminder\n");   // 打印提示信息
    for(i=0 ; i<num_remind ; i++){
        printf("%s\n",reminders[i]);

    }

    return 0;
}

int read_line(char str[],int n){
    char ch;
    int i=0;
    while((ch = getchar()) != '\n'){
        if(i<n){
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}