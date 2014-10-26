/**
 * @file deleteChars.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-26
 */
/*删除字符串中的“b”和“ac”，需要满足如下的条件：
 *
 *
 *     字符串只能遍历一次
 *
 *         不能够使用额外的空间*/
#include <bits/stdc++.h>
using namespace std;

//从s中删除字符c
void deleteOneChar(char *s, const char c)
{
    if(s == nullptr ||  c == 0) return;
    int i=0,j=0;
    for(int j = 0; s[j] != '\0'; ++j)
    {
        if(s[j] != c) s[i++] = s[j];
    }
    s[i] = '\0';
}

//删除'b' 和 "ac"
void deleteChars(char *s)
{
    cout << "s : " << s << endl;

    if(s == nullptr ) return;
    int i = 0 ; //下一个合法字符已经存放的位置
    int PREV = false; // 前一个字符是A的情况
    int k = 0;
    for(k = 0 ; s[k] != '\0'; ++k)
    {
        cout << s[k] << endl;
        if(PREV == false && s[k] != 'a' && s[k] != 'b')
        {
            s[i++] = s[k];
        }
        if(PREV  && s[k] != 'c')
        {
            s[i++] = 'a';
            if(s[k] != 'a' && s[k] != 'b')
            {
                s[i++] = s[k];
            }
        }
        PREV = (s[k] == 'a');
        if(i > 1 && s[i-2] == 'a'  && s[i-1] == 'c')
            i-=2;
    }

    if(PREV) // 说明还有最后一个'a'需要写到合理的位置
        s[i++] = 'a';
    s[i] = '\0';
}   

int main(void)
{
    char s[100];
    cout << "string : ";
    cin >> s;
    deleteChars(s);
    cout << "ret : " << s << endl;
    return 0;
}
