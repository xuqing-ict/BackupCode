/**
 * @file istreambuf_iterator.cc
 * @brief istreambuf_iterator
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-15
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream f("data.txt");
    istreambuf_iterator<char> in(f);
    string s(in, istreambuf_iterator<char>());
    cout <<  s << endl;
    return 0;
}
