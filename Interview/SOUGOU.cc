/**
 * @file SOUGOU.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-25
 */
//测试搜狗的题目
#include <bits/stdc++.h>
using namespace std;

//此处必须传p的指针，因为我们需要改变的是p的指向！！
void GetMem(char **p)
{
    *p = (char *)malloc(100);
}

void Test(void)
{
    char *str = nullptr;
    GetMem(&str);
    strcpy(str,"hello world!");
    printf(str);
    free(str);
    str=nullptr;
}

char *GetMem2()
{
    char p[] = "Hellp world!!";
    return p; //返回的是局部变量的地址，是不正确的
}

void Test2(void)
{
    char *str = nullptr;
    str = GetMem2();
    char *p = str;
    printf(p);
}

void GetMem3(char **p, int num)
{
    *p = (char *)malloc(num);
}
void Test3()
{
    char *str = nullptr;
    GetMem3(&str, 100);
    strcpy(str, "Hello");
    printf(str);
}
int main(void)
{
    //Test();
    //Test2();
    Test3();
    return 0;
}
