#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


int main()
{
    FILE *fp;

    fp = fopen("fopen_t","r");
    if(fp == NULL)
    {
        // 下面三种打印错误信息的方式:
        // 1   最不好,只能看见错误代号,不能看出可读的错误信息
        // 2 3 报错方式都比第一种准确,实用

        // 1.打印错误代号
        // fprintf(stderr,"fopen() failed! errno = %d\n",errno);

        // 2.将错误代号转化为可读的错误信息打印
        // perror("fopen()");

        // 3.根据错误代号在标准错误上打印出可读的错误信息
        fprintf(stderr,"fopen() : %s\n",strerror(errno));

        exit(1);
    }

    puts("ok!");

    exit(0);

    return 0;
}
