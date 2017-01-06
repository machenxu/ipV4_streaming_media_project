#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


// 程序功能 :
// fflush函数例程

/*
*
* 缓冲区刷新函数：
* fflush();
*
* 缓冲区的作用：
* 大多数情况下是好事,合并系统调用。
*
* 行缓冲：
* 换行时候刷新，满了的时候刷新，强制刷新 （标准输出是这样的，因为是中断设备）
*
* 全缓冲：
* 满了的时候刷新，强制刷新  （默认，只要不是终端设备）
*
* 无缓冲：
* 比如 stderr，需要立即输出的内容
*
*/


int main(int argc,char **argv)
{
    int i;

    // printf,不加换行符,会打印不出　Before while()
    printf("Before while()");

    // 因为printf往标准终端输出时,
    // 标准终端只有当一行满的时候或者碰到换行符,才会刷新缓冲区

    // 强制刷新缓冲区,也会使　Before while() 被打印出
    fflush(NULL);

    while(1);

    printf("After while()");
    fflush(NULL);

    exit(0);

    return 0;
}
