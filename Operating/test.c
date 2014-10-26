// Last Update:2014-08-08 14:17:27
/**
 * @file test.c
 * @brief 
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
  static int beeps=0;
  printf("Beep.\n");
  if(++beeps < 5)
  {
    alarm(1);
  }
  else
  {
    printf("end.\n");
    exit(0);
  }
}
void handler2(int sig)
{
  printf("SIGINT signal...\n");
  exit(0);
}
int main(void)
{
    int x=0;
   /* pid_t pid,pid2;
    pid=Fork();
    
    if(pid==0)
        printf("I am parent : %d\n",x++);
    else
        printf("I am Child : %d\n",--x);
    Fork();
    printf("Hello world...\n");
    
    if(pid == 0)
        printf("a\n");
    else 
    {
        printf("b\n");
        pid2=waitpid(-1,NULL,0);
        assert(pid==pid2);
    }
    printf("c\n");
    
    pid_t pid[2];
    int status;
    int i=0;
    for(i=0;i<2;++i)
    {
      if((pid[i]=Fork()) == 0)
      {
          exit(100+i);
      }
    }
    pid_t ret_pid;
    i=0;
    while((ret_pid = waitpid(pid[i++], &status,0)) > 0)
    {
        if(WIFEXITED(status))
          printf("child %d exited normally\n",ret_pid);
        else
          printf("child %d exited abnormally\n",ret_pid);
    }
    
    
    signal(SIGALRM,handler);
    alarm(1);
    while(1){;}
    exit(0);
    */
    if(signal(SIGINT,handler2) == SIG_ERR)
      unix_error("signal error!!!\n");
    pause(); //waiting for a signal
    exit(0);
}
