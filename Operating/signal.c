// Last Update:2014-08-08 14:46:50
/**
 * @file signal.c
 * @brief signal
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-08
 */
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <signal.h>
#include <unistd.h>

const unsigned int MAX = 1024;

void unix_error(char *msg)
{
    fprintf(stderr, "%s : %s\n",msg,strerror(errno));
    exit(0);
}

pid_t Fork()
{
    pid_t pid;
    if((pid=fork()) < 0)
      unix_error("Fork error!!");
    return pid;
}
void handler(int sig)
{
  pid_t pid;
  while((pid = waitpid(-1,NULL,0)) > 0)
    printf("handler reaped child %d\n", (int)(pid));
  if(errno != SIGCHLD)
      unix_error("waitpid error.\n");

  sleep(2);
  return;
}

int main(void)
{
  int i, n;
  char buf[MAX];
  if(signal(SIGCHLD,handler) == SIG_ERR)
    unix_error("signal error!!!\n");
    
  for(i=0;i<3;++i)
  {
    if(Fork() == 0)
    {
      printf("Hello from pid : %d\n",(int)(getpid()));
      sleep(1);
      exit(0);
    }
  }
  while(n == read(STDIN_FILENO,buf,sizeof(buf)) < 0)
      if(errno != SIGINT)
        unix_error("read");
  printf("Parent processing input.\n");
  while(1){;}

  exit(0);
}
