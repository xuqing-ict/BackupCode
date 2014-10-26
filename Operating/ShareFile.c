// Last Update:2014-08-23 10:39:45
/**
 * @file ShareFile.c
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-23
 */
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

//tmp.txt 的内容是  ： 1234567890
int main(void)
{
    //同一个文件被打开两次，文件表项有两份，各自记录着当前描述符的读写位置，但是v-node表的表项是共享的。

    /*
    int fd1,fd2;
    char c;
    fd1 = open("tmp.txt",O_RDONLY,0);
    if(!fd1) printf("Open error\n");
    fd2 = open("tmp.txt",O_RDONLY,0);
    if(!fd2) printf("Open error\n");
    read(fd1,&c,1);
    printf("c = %c\n",c); //1
    read(fd2,&c,1);
    printf("c = %c\n",c); //1
    */
    /*
    //父子进程之间的文件描述符的关系。
    //父子进程共享文件表项，也就是说两者的文件描述符表虽然是一样的，但是指向的文件表项是统同一份，而文件表项中记录的又有该文件的读取位置，所以，下述的输出为 1 2 
    int fd;
    char c;
    fd = open("tmp.txt",O_RDONLY,0);
    if(fork() == 0 ) //Child 
    {
        read(fd,&c,1);
        printf("In Child : c = %c\n",c); // 1
        exit(0);
    }
    wait(NULL);
    
    read(fd, &c,1);
    printf("In parent : c = %c\n",c); // 2
    */
    int fd1,fd2;
    char c;
    fd1 = open("tmp.txt",O_RDONLY,0);
    if(!fd1) printf("Open error\n");
    fd2 = open("tmp.txt",O_RDONLY,0);
    if(!fd2) printf("Open error\n");
    read(fd2,&c,1);
    printf("c = %c\n",c); //0
    dup2(fd2,fd1); //此处会将描述符表项中的fd1与fd2都指向fd1的文件表的表项，也就是说现在fd1与fd2的读取位置以及所有的文件信息全部一样。
    read(fd1,&c,1);
    printf("c = %c\n",c); //1
    return 0;
}
