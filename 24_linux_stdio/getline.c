#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


// 程序功能 :
// getline()函数例程
// 一行一行读取出文件所有内容

int main(int argc,char **argv)
{
    FILE *fp;

    // 一定要初始化,不然会产生BUG
    char *linebuf = NULL;
    size_t linesize = 0;
    ssize_t read = 0;

    if(argc != 2)
    {
        fprintf(stderr,"Usage:%s <file> \n",argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1],"r");
    if(fp == NULL)
    {
        // 根据错误代号在标准错误上打印出可读的错误信息
        fprintf(stderr,"fopen() : %s\n",strerror(errno));
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        // 一次读一行
        // getline会在linebuf所指向的内存不够用时,再动态分配
        read = getline(&linebuf,&linesize,fp);
        if(read < 0)
        {
            break;
        }

        printf("read = %zu\n",read);
        printf("linebuf = %s\n",linebuf);
    }

    free(linebuf);
    linebuf = NULL;

    fclose(fp);

    exit(EXIT_SUCCESS);

    return 0;
}
