#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// fgets,fputs 每次一行I/O

// 程序功能 :
// 使用fgets,fputs函数完成文件拷贝功能

#define BUFFSIZE 1024

int main(int argc,char **argv)
{
    FILE *fps,*fpd;
    char buf[BUFFSIZE];

    if(argc != 3)
    {
        fprintf(stderr,"Usage:%s <src_file> <dest_file>\n",argv[0]);
        exit(1);
    }

    fps = fopen(argv[1],"r");
    if(fps == NULL)
    {
        // 根据错误代号在标准错误上打印出可读的错误信息
        fprintf(stderr,"fopen() : %s\n",strerror(errno));

        exit(1);
    }


    fpd = fopen(argv[2],"w");
    if(fpd == NULL)
    {
        // 根据错误代号在标准错误上打印出可读的错误信息
        fprintf(stderr,"fopen() : %s\n",strerror(errno));

        // 关闭已经打开成功的文件
        fclose(fps);

        exit(1);
    }

    // 目的 缓冲区大小 源文件
    while(fgets(buf,BUFFSIZE,fps) != NULL)
    {
        // 源　目的
        fputs(buf,fpd);
    }

    // 先关闭依赖别人的对象
    fclose(fpd);

    // 再关闭被依赖的对象
    fclose(fps);

    exit(0);

    return 0;
}
