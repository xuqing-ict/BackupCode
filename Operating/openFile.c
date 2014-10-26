// Last Update:2014-08-29 15:06:53
/**
 * @file openFile.c
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-29
 */

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
    int fd1,fd2;
    fd1=open("t1.txt",O_RDONLY,0);
    fd2=open("t2.txt",O_RDONLY,0);
    close(fd2);
    fd2=open("t3.txt",O_RDONLY,0);
    printf("fd1=%d\n",fd1);
    printf("fd2=%d\n",fd2);
    return 0;
}

 
