/**
 * @file wideStringMatch.cc
 * @brief wide char match
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-29
 */
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
/*
bool isMatch(const char *s, const char *p) {
    if(p == '\0') return s == '\0';

    if(*p == '*')
    {
        while(*s != '\0' && (*(p+1) == *s || *(p+1) == '?'))
        {
            if(isMatch(s+1,p+2)) return true;
            ++s;
        }
        return isMatch(s,p+1);
    }
    else
    {
        if(*s != '\0' && (*p == *s || *p == '?'))
            return isMatch(s+1,p+1);
    }
    //  return false;
}
*/

bool isMatch(const char *s, const char *p) {
    if(s == NULL && p == NULL ) return true;
    if(s == NULL) return false;
    if(p == NULL) return true;


    const char *str = s, *ptr = p; //record the previous position

    bool star = false;
    //the char of s must be matched end...
    while(*s)
    {
        if(*p == '?') 
        {
            ++s;
            ++p;
        }
        else if(*p == '*')
        {
            star = true;
            str = s; //str表示当前的这个s还没有找到匹配!!
            ptr = p;
            while(*ptr == '*') ++ptr;
            if(*ptr == '\0') return true; //直接全是*
            p = ptr;  //这是个要匹配的位置（非*的位置！！）
        }
        else
        {
            if(*p == *s) {s++;p++;continue;}
            if(star == false) return false;
            s=str++;//str当前位置的这个字符匹配不了，果断与*进行匹配,将s++，进入下面的匹配！！
            p=ptr; //那么此时的p就必须指向最近的*的后面的那个不是*的字符！！！
        }
    }
    while(*p == '*') ++p;
    return *p == '\0';
}

int main()
{
    const char *s ="ababa";
    const char *p = "a*a";
    if(isMatch(s,p)) cout << "match..." << endl;
    else cout << "fail..." << endl;
    return 0;
}

