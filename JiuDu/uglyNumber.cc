/**
 * @file uglyNumber.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-19
 */
//ugly number
#include <bits/stdc++.h>
using namespace std;
    typedef vector<int>::iterator iter;

int print(const int n)
{
    if(n < 0 ) return -1;

    vector<int> uglyNumber(n,0);
    iter prev2,prev3,prev5;
    prev2 = prev3 = prev5 = uglyNumber.begin();

    uglyNumber[0]=1;
    for(int i=1;i<n;++i)
    {
        uglyNumber[i] = min(*prev2*2 , min(*prev3*3, *prev5*5));
        prev2 = upper_bound(prev2,uglyNumber.begin()+i+1,uglyNumber[i]/2);
        prev3 = upper_bound(prev3,uglyNumber.begin()+i+1,uglyNumber[i]/3);
        prev5 = upper_bound(prev5,uglyNumber.begin()+i+1,uglyNumber[i]/5);
    }
    return uglyNumber[n-1];
}
int main(void)
{
    cout << print(10) << endl;
    return 0;
}
