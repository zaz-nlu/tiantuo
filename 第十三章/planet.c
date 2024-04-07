#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 9

int main(int argc, char *argv[]) {
    char *planets[] = {"Mercury", "Venus", "Earth",
                       "Mars", "Jupiter", "Saturn",
                       "Uranus", "Neptune", "Pluto"};
    int i, j;

    // 遍历命令行参数
    for (i = 1; i < argc; i++) {
        // 遍历行星数组
        for (j = 0; j < NUM_PLANETS; j++) {
            // 比较命令行参数和行星名称
            if (strcmp(argv[i], planets[j]) == 0) {
                // 如果匹配，打印行星信息并跳出内循环
                printf("%s是第%d颗行星\n", argv[i], j + 1);
                break;
            }
        }

        // 如果内循环完整执行（未中断），说明参数不是任何一个行星
        if (j == NUM_PLANETS) {
            printf("%s不是一个行星。\n", argv[i]);
        }
    }

    return 0;
}
