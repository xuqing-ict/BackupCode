// Last Update:2014-08-29 16:23:34
/**
 * @file pthread.c
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
#include <semaphore.h>

void *thread(void *vargp);
volatile int cnt=0;
sem_t mutex;

int main(int argc, char **argv)
{
    sem_init(&mutex,0,1);

    int niters;
    pthread_t tid1, tid2;
    if(argc!=2)
    {
       printf("usage : %s,niters.\n",argv[1]);
       exit(0);
    }
    niters = atoi(argv[1]);
    pthread_create(&tid1,NULL,thread,&niters);
    pthread_create(&tid2,NULL,thread,&niters);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    if(cnt != (2*niters))
        printf("BOOM : cn = %d\n",cnt);
    else

        printf("BINGO: cn = %d\n",cnt);
    exit(0);
}

void *thread(void *vargp)
{
    int i, niters = *(int *)vargp;
    sem_wait(&mutex);
    for(i=0;i<niters;++i)
        cnt++;
    sem_post(&mutex);
    return NULL;
}
 
