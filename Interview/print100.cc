/**
 * @file print100.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-12
 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<int> A(101,1);
    for(int i=2;i<=100;++i)
    {
        for(int j=i;j<=100;j+=i)
            A[j]++;
    }
    for(int i=1;i<=100;++i)
        if(A[i] == 12)
            cout << i << "\t";
    cout << endl;
    return 0;
}
