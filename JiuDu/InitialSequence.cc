
//类内部的成员变量的初始化顺序
#include <bits/stdc++.h>
using namespace std;

class A
{
private:
    int n1;
    int n2;
public:
    A(int x=2):n1(x+1),n2(n1){}
    void print()
    {
        cout << n1 << " \t " << n2 << endl;
    }
};

enum Status {invalid, valid}; // 用来表示输入是否合法的全局变量
bool g_state = valid;

int strToInt(const char *s)
{
    g_state = invalid;

    if(s == nullptr) //关于此处，对于s为空的情况是atoi是通过设置一个全局变量的值来表示说当前的输入是不合法的。
    {
        exit(1);
    }
    long long number = 0 ; // 为了能够处理长整数的情况，使用long long来保存结果
    bool label = false; // + / -
    int n = strlen(s);
    if(n == 0)  //空字符串的话，那么设置全局变量，并且返回0;
    {
        exit(1);
    }

    int i = 0;
    if(s[i] == '+')
    {
        label = false;
        ++i;
    }
    else if(s[i] == '-')
    {
        label = true;
        ++i;
    }
    if(i == n)  //只有一个正号或者是负号，无数字部分，也是不合理的
    {
        return 0;
    }
    for( ; i < n; ++i)
    {
        if(!isdigit(s[i]))
        {
            number = 0;
            break;
        }
        number = number * 10 + (label?(-1):1)*(s[i]-'0');
        //判断是否溢出,溢出不会设置g_state, 而是给个随机值，或者是直接返回0
        if(number > INT_MAX || number < INT_MIN)
        {
            number = 0;
            break;
        }
    }

    if(i == n) g_state = valid;
    return number;
}

int main(void)
{
    A a(9);
    a.print();
    cout <<INT_MAX << "\t" << INT_MIN << endl;

    char str[100] = "2147483648";
    //cin >> str;
    int number = strToInt(str);
    if(g_state == invalid)
        cout << "illegel input..." << endl;
    else
        cout << number << endl;
    return 0;
}
