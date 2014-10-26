// Last Update:2014-08-23 16:21:26
/**
 * @file printDNS.c
 * @brief
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-23
 */
//检索并且打印一个打印DNS主机条目
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>


int main(int argc, char **argv)
{
    char **pp;
    struct in_addr addr; //IP地址
    struct hostnet *hostp; //DNS主机条目

    if(argc != 2)
    {   
        fprintf(stderr,"usage: %s <domain name or dotted-decimal>\n",argv[0]);
        exit(0);
    }
    //点分十进制转换为IP地址
    if(inet_aton(argv[1],&addr) != 0 )
        hostp = gethostbyaddr((const char *)&addr,sizeof(addr),AF_INET);
    else
        hostp = gethostbyname(argv[1]);
    printf("official name : %s\n",hostp->h_name);

    for(pp = hostp->h_aliases; *pp != NULL; pp++)
    {
        printf("alias : %s\n",*pp);
    }
    for(pp = hostp->h_addr_list; *pp != NULL; pp++)
    {
        addr.s_addr = ((struct in_addr *)*pp)->s_addr;
        printf("address : %s\n",inet_atoi(addr));
    }
    return 0;
}

