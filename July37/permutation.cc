/**
 * @file permutation.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-25
 */
//使用递归的方式求解premutation
#include <bits/stdc++.h>
using namespace std;
/*
typedef string::iterator iter;

void permutation(string s,iter it)
{
    if(s.empty())return;

    if(it == s.end())
        cout << s << endl;
    else
    {
        for(iter cur = it; cur != s.end();++cur)
        {
            char tmp=*cur;*cur=*it;*it=tmp; 
            permutation(s,it+1);
            tmp=*cur;*cur=*it;*it=tmp; 
        }
    }
}
int main(void)
{
    string s = "12";
    permutation(s,s.begin());
    return 0;
}
*/
void permutation(char *pStr, char *pBegin)
{
    if(!pStr || !pBegin)
        return;
    if(*pBegin == '\0')
        printf("%s\n",pStr);
    else
    {
        for(char *pCh = pBegin; *pCh != '\0'; ++pCh)
        {
            char temp=*pCh;*pCh=*pBegin;*pBegin==temp;
            permutation(pStr,pBegin+1);
            temp=*pCh;*pCh=*pBegin;*pBegin==temp;
        }
    }
}
int main(void)
{
    char s[] = "12";
    permutation(s,s);
    return 0;
}
