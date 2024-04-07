#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define frame_height 50
#define frame_width 50
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

int i, j, k, score,n,sp;
char ch = UP, state = UP, choo;
int grow = 0;

struct Snake {
    int x[100];
    int y[100];
    int len;
    int speed;
} snake;

struct Food {
    int x;
    int y;
} food;

void map(void);
void update_food(void);
int is_food_on_snake(void); // 修改了函数声明
void move_snake(void);
int alive(void);
void get_speed(void);
void gotoxy(int x, int y);

int main() {
    srand(time(NULL));
    do {
        score = 0;
        printf("Please choose the degree of difficulty:\n 1. Easy \n 2. Middle \n 3. Hard \n");
        n=getchar(); // 修改了读取方式

        switch (n) {
             case '1':
        { 
   
            sp=300;
            break;
        }
        case '2':
        { 
   
            sp=230;
            break;
        }
        case '3':
        { 
   
            sp=180;
            break;
        }
        default: {
            printf("You choose devil mode: Let's begin the crazy game!");
            sp = 100;
            break;
        }
        }
        system("cls"); // 清屏
        map();
        while(1)
        { 
   
            update_food();//生产食物
            get_speed();//获取速度
            move_snake();//移动
            Sleep(snake.speed);//延时函数,speed数值越大延时越长
            if(!(alive()))//判断蛇是否死亡
            { 
   
                break;//死亡则退出循环
            }
        }
        printf("Game Over!\n");
        printf("1:Restart\t2:exit");
        choo=getch();
    }
    while(choo=='1');
    return 0;
}





void map(){
    srand(time (NULL));
    //用于制作食物以及蛇
    do{
    food.x = rand() % (frame_height-2)+1;
    food.y = rand() % (frame_width-2) + 1;
    gotoxy(food.x,food.y);
    printf("$");}while(is_food_on_snake());

    snake.x[0] = frame_height / 2;//蛇的位置基本就是固定的
    snake.y[0] = frame_width / 2;
    gotoxy(snake.x[0],snake.y[0]);
    printf("@");
    snake.len = 3;
    snake.speed = 200;

    //绘制移动逻辑
    for(k=1 ; k < snake.len; k++){
        snake.x[k] = snake.x[k-1];
        snake.y[k] = snake.y[k-1];
        gotoxy(snake.x[k],snake.y[k]);
        printf("@");

    }

    //绘制墙体
    for(i=0;i<frame_width;i++){
        gotoxy(0,i);
        printf("-");
        gotoxy(frame_height-1,i);
        printf("-");
    }

    for(j=0;j<frame_height-1; j++){
        gotoxy(j,0);
        printf("|");
        gotoxy(j,frame_width-1);
        printf("|");
    }

    gotoxy(30,frame_width+32);
    if(n=='1') printf("Difficulty: easy");
    else if(n=='2') printf("Difficulty: middle");
    else if(n=='3') printf("Difficulty: difficult");
    else printf("Welcome to the Devil's difficulty");
    gotoxy(4,frame_width+3);
    printf("UP: w");
    gotoxy(6,frame_width+3);
    printf("DOWN: s");
    gotoxy(8,frame_width+3);
    printf("LEFT: a");
    gotoxy(10,frame_width+3);
    printf("RIGHT:d");
    gotoxy(12,frame_width+3);
    printf("Your score:%d",score);
    gotoxy(36,frame_width+3);
    printf("Made by Liuyuchen");
    
}



void update_food(){//食物更新的标志就是被蛇吃到，被蛇吃到才会开始更新
    if(snake.x[0] == food.x && snake.y[0] == food.y){
        score += 10;
        gotoxy(12,frame_width+3);
        printf("Your score:%d",score);
        srand(time(NULL));

        do{
            food.x = rand() % (frame_height-2) + 1;
            food.y = rand() % (frame_width - 2 ) + 1;
        }while(is_food_on_snake());

        gotoxy(food.x,food.y);
        printf("$");
        snake.len++;
        grow=1;
    }
}

int is_food_on_snake(){//检验食物是否在蛇的身上
    for(int i=0;i<snake.len;i++){
        if(food.x == snake.x[i] && food.y == snake.y[i]){
            return 1;
        }

        
    }
    return 0;
}
  



// void move_snake(void){
//     while(kbhit()){
       
//         ch = getch();
//     }
//     if(!grow){
//         gotoxy(snake.x[snake.len-1],snake.y[snake.len-1]);
//         printf(" ");
//     }
//     for(k=snake.len-1;k>0;k--){
//         snake.x[k] = snake.x[k-1];
//         snake.y[k] = snake.y[k-1];
//     }

//     switch(ch)
//     {
//         case UP:{
//             if(state == DOWN){
//                 snake.x[0]++;
//                 break;
//             }

//             else{
//                 snake.x[0]--;
//                 break;
//             }
//         }

//         case DOWN:{
//             if(state == UP){
//                 snake.x[0]--;
//                 break;
//             }
//             else{
//                 snake.x[0]++;
//                 break;
//             }
//         }

//         case LEFT:{
//             if(state == RIGHT){
//                 snake.y[0]--;
//                 break;
//             }
//             else{
//                 snake.y[0]++;
//                 break;
//             }
//         }

//         case RIGHT:{
//             if(state == LEFT){
//                 snake.y[0]++;
//                 break;
//             }

//             else{
//                 snake.y[0]--;
//                 break;
//             }
//         }

//         default:{
//             if(state==DOWN)
//         { 
   
//             snake.x[0]++;
//             break;
//         }
//         else if(state==UP)
//         { 
   
//             snake.x[0]--;
//             break;
//         }
//         else if(state==LEFT)
//         { 
   
//             snake.y[0]--;
//             break;
//         }
//         else if(state==RIGHT)
//         { 
   
//             snake.y[0]++;
//             break;
//         }

//         }
//     }
//     gotoxy(snake.x[0],snake.y[0]);
//     printf("@");//打印蛇头
//     grow=0;//初始成长状态为0
//     gotoxy(frame_height-1,0);//光标移动到地图左下角下方
// }
void move_snake()
{ 
   
    while(kbhit())//键盘有输入
    { 
   
        ch=getch();
    }
    if(!grow)//没有长
    { 
   
        gotoxy(snake.x[snake.len-1],snake.y[snake.len-1]);
        printf(" ");//走了，在数组的最后打印空格，清除原有的蛇尾
    }
    for(k=snake.len;k>0;k--)//更新蛇的坐标，除了蛇头,其余位置继承上一个点的坐标
    { 
   
        snake.x[k]=snake.x[k-1];
        snake.y[k]=snake.y[k-1];//移动位置
    }
    switch(ch)//改变方向
    { 
   
    case UP:
    { 
   
        if(state==DOWN)//如果此时方向向下，输入向上的作用要被无视
        { 
   
            snake.x[0]++;
            break;
        }
        else
        { 
   
            snake.x[0]--;
            state=UP;//其余的改变状态为向上
            break;
        }
    }
    case DOWN:
    { 
   
        if(state==UP)
        { 
   
            snake.x[0]--;
            break;
        }
        else
        { 
   
            snake.x[0]++;
            state=DOWN;
            break;
        }
    }
    case LEFT:
    { 
   
        if(state==RIGHT)
        { 
   
            snake.y[0]++;
            break;
        }
        else
        { 
   
            snake.y[0]--;
            state=LEFT;
            break;
        }
    }
    case RIGHT:
    { 
   
        if(state==LEFT)
        { 
   
            snake.y[0]--;
            break;
        }
        else
        { 
   
            snake.y[0]++;
            state=RIGHT;
            break;
        }
    }
    /*摁其余键,保持原有状态*/
    default:
    { 
   
        if(state==DOWN)
        { 
   
            snake.x[0]++;
            break;
        }
        else if(state==UP)
        { 
   
            snake.x[0]--;
            break;
        }
        else if(state==LEFT)
        { 
   
            snake.y[0]--;
            break;
        }
        else if(state==RIGHT)
        { 
   
            snake.y[0]++;
            break;
        }

    }
    }
    gotoxy(snake.x[0],snake.y[0]);
    printf("@");//打印蛇头
    grow=0;//初始成长状态为0
    gotoxy(frame_height,0);//光标移动到地图左下角下方
}



int alive(void) {
    // 检查蛇是否撞到上下边界
    if (snake.x[0] == 0 || snake.x[0] == frame_height - 1) {
        return 0;  // 蛇撞墙，游戏结束
    }

    // 检查蛇是否撞到左右边界
    if (snake.y[0] == 0 || snake.y[0] == frame_width - 1) {
        return 0;  // 蛇撞墙，游戏结束
    }

    // 检查蛇是否咬到自己
    for (int k = 1; k < snake.len; k++) {
        if (snake.x[0] == snake.x[k] && snake.y[0] == snake.y[k]) {
            return 0;  // 蛇咬到自己，游戏结束
        }
    }

    return 1;  // 蛇既没有撞墙也没有咬到自己，游戏继续
}



void get_speed(void){

     if(snake.len<=6)
        snake.speed=sp;
    else if(snake.len<=10)
        snake.speed=sp-20;
    else if(snake.len<=20)
        snake.speed=sp-50;
    else if(snake.len<=30)
        snake.speed=sp-60;
    else
        snake.speed=sp-70;
}


void gotoxy(int x,int y){
    HANDLE hout;  // 控制台输出句柄
    COORD cor;    // 用于储存坐标的结构体

    hout = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取标准输出设备的句柄

    // 设置坐标的X和Y值
    cor.X = y;  // 注意：这里将y赋给了cor.X
    cor.Y = x;  // 注意：这里将x赋给了cor.Y

    // 定位光标的函数，将光标移动到指定位置
    SetConsoleCursorPosition(hout, cor);

}

