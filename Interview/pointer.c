// Last Update:2014-09-26 14:50:57
/**
 * @file pointer.c
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-26
 */
#include<stdio.h>
int main() 
{     
    int a[5]= {1,2,3,4,5};    
    int *p,**k;    
    p=a;    
    k=&p;     
    printf("%d",*(p++)); 
    printf("%d",**k);  
    
    printf("\n");   
    return 0; 
}

