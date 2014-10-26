/**
 * @file mmap.cc
 * @brief mmap and munmap
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-11
 */

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

const int BUF_SIZE=100;
int main(int argc, char **argv)
{
  int fd,nread,i;
  struct stat sb;
  char *mmaped;
  char buf[BUF_SIZE];
  for(int i=0; i<BUF_SIZE; ++i)
      buf[i]='#';
  if((fd=open(argv[1],O_RDWR))<0)
      perror("open");
  if(fstat(fd,&sb)==-1)
     perror("fstat");
  
     if((mmaped=(char *)mmap(NULL,sb.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0))==(void*)(-1))
     perror("mmap");

     //map end , close the file
     close(fd);

    mmaped[20]='9';
    return 0;
}
