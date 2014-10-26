/**
 * @file StrSeries.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-19
 */
//字符串操作函数

#include <bits/stdc++.h>
using namespace std;

//Strncpy
char *Strncpy(char *dst, const char *src, size_t n)
{
    assert(dst!=nullptr && src!=nullptr);
    char *ret = dst;
    //Version 1
   /* while(n-- && *src != '\0')
        *dst++ = *src++;
    *dst = '\0';
    */
    //Version 2
    while(n && (*dst++ = *src++))n--;
    if (n) 
    {
        while(n--)*dst++='\0';
    }
    return ret;
}

char *Strstr(char *str, int c)
{
    assert(str !=nullptr);
    for(;*str != (char)c; ++str)   
        if(*str == '\0')
            return nullptr;
    return str;
}
int main(void)
{
    char dst[] = "12345";
    const char *src = "abcd";
    cout << dst << "\t" << strlen(dst) << endl;
    char *ret=Strncpy(dst,src,3);
    cout << dst << "\t" << strlen(dst) << endl;
    cout << ret << "\t" << strlen(ret) << endl;
    return 0;
}
