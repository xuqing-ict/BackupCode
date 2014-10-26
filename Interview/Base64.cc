/**
 * @file Base64.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-12
 */

#include <bits/stdc++.h>
using namespace std;

const size_t BEFORE_SIZE = 3;
const size_t AFTER_SIZE = 4;

const string code = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
const char pad = '=';

void convert(const unsigned char *before, unsigned char *after)
{
    int k = 0;
    after[k++] = before[0]>>2;
    after[k++] = ((before[0] & 3) << 4 ) ^  (before[1] >> 4);
    after[k++] = ((before[1] & 0xf) << 2) ^ (before[2] >> 6); 
    after[k++] = before[2] & (0x3f); 
}

string Base64(const char *s,size_t len)
{
    if(s == nullptr || len <= 0) return string("");
    string ret;
    int prev = len/3, next = len%3;
    unsigned char before[BEFORE_SIZE],after[AFTER_SIZE];

    for(int i=0;i<prev;++i)
    {
        before[0] = *(s+3*i);
        before[1] = *(s+3*i+1);
        before[2] = *(s+3*i+2);
        convert(before, after);
        for(int i=0;i<AFTER_SIZE;++i)
            ret += code[after[i]];
    }
    if(next == 0 ) return ret;

    int k=0;
    for(int i=next;i>0;--i)
        before[k++] = *(s+len-i);
    for(int i=next;i<BEFORE_SIZE;++i)
        before[i] = 0;
    convert(before, after);
    for(int i=0;i<AFTER_SIZE-1;++i)
        ret += code[after[i]];
    ret += string(BEFORE_SIZE-next,pad);

    /* 
       if(next == 1)
       {
       before[0] = *(s+len-1);
       before[1] = 0;
       before[2] = 0;
       convert(before, after);
       for(int i=0;i<AFTER_SIZE-2;++i)
       ret += code[after[i]];
       ret += string(2,pad);
       }
       else if(next == 2)
       {
       before[0] = *(s+len-2);
       before[1] = *(s+len-1);
       before[2] = 0;
       convert(before, after);
       for(int i=0;i<AFTER_SIZE-1;++i)
       ret += code[after[i]];
       ret += string(1,pad);
       }
       */
    return ret;
}

int main(void)
{
    string s1;
    string ans;
    getline(cin, s1);
    getline(cin, ans);
    cout << s1 << endl;
    const char *s = s1.c_str();
    size_t len = strlen(s);
    string ret = Base64(s,len);
    assert(ret == ans);
    return 0;
}
