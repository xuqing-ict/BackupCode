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
const int MAX_TIME = 2000000000000
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
  int ticks=0;
  while(ticks < MAX_TIME)
  {

  }
 /* 
     if((mmaped=(char *)mmap(NULL,sb.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0))==(void*)(-1))
     perror("mmap");

     //map end , close the file
     close(fd);
     printf("%s",mmaped);

   // mmaped[20]='9';
    if((msync((void *)mmaped,sb.st_size,MS_SYNC))==-1)
      perror("msync");
      //munmap
    if(munmap((void *)mmaped,sb.st_size)==-1)
      perror("munmap");
    while(1)
    {
      printf("%s\n",mmaped);
      sleep(2);
    }
    */
  return 0;
}
