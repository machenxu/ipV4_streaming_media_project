#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


// 程序功能 :
// 使用fgetc();测试一个文件中有效字符个数
// 假设文件中有效字符个数不超过int可以表示的范围

int main(int argc,char **argv)
{
    FILE *fp;

    // 假设文件中有效字符个数不超过int可以表示的范围
    int count = 0;

    if(argc != 2)
    {
        fprintf(stderr,"Usage:%s <file> \n",argv[0]);
        exit(1);
    }

    fp = fopen(argv[1],"r");
    if(fp == NULL)
    {
        // 根据错误代号在标准错误上打印出可读的错误信息
        fprintf(stderr,"fopen() : %s\n",strerror(errno));

        exit(1);
    }

    while(fgetc(fp) != EOF)
    {
        count++;
    }

    printf("count = %d\n",count);

    fclose(fp);

    exit(0);

    return 0;
}
