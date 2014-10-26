/**
 * @file int2Str.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-09
 */
//int to string
#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;

string int2Str(long number)
{
    char ret[MAX];
    bool flag=false;
    if(number<0)
    {
        flag = true;
        number = -number;
    }
    int digits = 0;
    long tmp = number;
    do
    {
        digits++;
        tmp /=10;
    }while(tmp);
    int idx=0;
    if(flag)ret[idx++]='-';
    for(int i = digits + idx - 1; i >= idx; --i)
    {
        ret[i] = static_cast<char>(number%10 + '0');
        number/=10;
    }
    ret[digits+idx]='\0';
    cout << "ret = " << ret << endl;
    return string(ret);
}
int main(void)
{
    long number;
    cin >> number;
    cout << int2Str(number) << endl;
    return 0;
}
