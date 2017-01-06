#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


// 程序功能 :
// atoi,sprintf例程

int main()
{
    char str1[] = "123456";
    char str2[] = "123a456";

    int year = 2014;
    int month = 12;
    int day = 5;

    char buf[1024];

    // atoi 将数字组成的字符串转化为int类型
    printf("str1 : %d\n",atoi(str1));

    // 如果字符串中有字符,则将字符之前的数字转化为int型
    printf("str2 : %d\n",atoi(str2));

    printf("%d-%d-%d\n",year,month,day);

    sprintf(buf,"%d-%d-%d",year,month,day);
    printf("buf : %s\n",buf);

    exit(0);

    return 0;
}
