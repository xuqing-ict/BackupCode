// Last Update:2014-07-15 21:46:43
/**
 * @file Print1ToN.cpp
 * @brief print 1 to Maximum interget
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-15
 */

#include <bits/stdc++.h>
using namespace std;

bool Increment(char *str)
{
    bool isOverflow = false;
    int index = -1, cur = -1;
    char *tmp = str;
    while(*str)
    {
        ++index;
        if(*str != '9') cur = index;
        ++str;
    }
    cout << "cur = " << cur << endl;
    str = tmp;
    if(cur == -1) isOverflow = true; 
    else
    {
        *(str+cur) = *(str+cur)+1;
        while(*(str+cur+1))
        {
            *(str+cur+1) = '0';
            ++cur;
        }
    }
    return isOverflow;
}

void helper(const int N , string &ret,int index )
{
    if(index >= N)
   {
       auto found = ret.find_first_not_of('0');
       if(found == string::npos)
           cout << string(N,'0') << endl;
       else
          cout << ret.substr(found) << endl;
       return;
    }
    for(int i=0; i<=9; ++i)
    {
        ret[index] = '0'+i;
        helper(N,ret,index+1);
    }
}
void print(const int N)
{
    string cur(N,'0');
    helper(N,cur,0);
    return;
}
int main()
{
    char s[] = "19999";
    Increment(s);
    cout << s << endl;
    print(2);
    
    return 0;
}
