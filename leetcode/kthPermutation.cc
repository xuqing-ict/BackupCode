/**
 * @file kthPermutation.cc
 * @brief The k-th permutation
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-31
 */

#include <bits/stdc++.h>
using namespace std;
string getPermutation(int n, int k){
    string str;
    for(int i=1;i<=n;++i) str+=(i+'0');
    int base=1;
    for(int i=n-1;i>=1;--i) base*=i; //(n-1)!
    --k; 
    string ret;
    for(int i=n-1;i>=1;--i)
    {
        cout << base << endl;
        int pos=k/base;
        ret+=str[pos];
        str.erase(pos,1);
        k=k%base;
        base/=i;
    }
    while
    return ret;
}

int main(void)
{
    getPermutation(2,1);
    return 0;
}
