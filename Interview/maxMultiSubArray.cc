/**
 * @file maxSubArray.cc
 * @brief max sub array
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-15
 */

//最大子数组乘积
#include <bits/stdc++.h>
using namespace std;

long long maxSubArray2(const vector<long> &A)
{
    const int n = A.size();
    long long ret=LONG_MIN,tmp=1;
    for(int i=0;i<n;++i)
    {
        for(int j=i;j<n;++j)
        {
            tmp=1;
            for(int k=i;k<=j;++k)
            {
                tmp*=A[k];
            }
            if(tmp>ret) ret=tmp;
        }
    }
    return ret;
}

long long maxSubArray(const vector<long> &A)
{
    const int n = A.size();
    //vector<long long> minC(n,0),maxC(n,0);
    //maxC[0]=minC[0]=A[0];
    long long maxC=1,minC=1;
    long long ret=LONG_MIN;;
    for(int i=0;i<n;++i)
    {
        //minC[i]=min(minC[i-1]*static_cast<long long>(A[i]),min(maxC[i-1]*static_cast<long long>(A[i]),static_cast<long long>(A[i])));
        //maxC[i]=max(minC[i-1]*static_cast<long long>(A[i]),max(maxC[i-1]*static_cast<long long>(A[i]),static_cast<long long>(A[i])));
        long long tmp2=min(minC*static_cast<long long>(A[i]),min(maxC*static_cast<long long>(A[i]),static_cast<long long>(A[i])));
        long long tmp1=max(minC*static_cast<long long>(A[i]),max(maxC*static_cast<long long>(A[i]),static_cast<long long>(A[i])));
        maxC=tmp1;
        minC=tmp2;
        if(maxC > ret) ret=maxC;
    }
    return ret;
}

int main(void)
{
    /*
    srand(time(NULL));
    int k=100;
    vector<long> A;
    cout << LONG_MAX << endl;
    while(k--)
    {
        int n = rand()%20+1;
        A.resize(n);
        for(int i=0; i<n; ++i)
        {
            A[i]=rand()%30-20;
        }
        for(int i=0;i<n;++i)
            cout << A[i] << "\t";
        cout << endl;
        long long ret1=maxSubArray2(A);
        long long ret2=maxSubArray(A);
        cout << ret1 << "\t" << ret2 << endl;
        assert(ret1==ret2); 
    }
    */
    vector<long> A = {1,-9,-3,-4,2,-5,-10,0};
    long long ret1=maxSubArray2(A);
    long long ret2=maxSubArray(A);
    cout << ret1 << "\t" << ret2 << endl;
    assert(ret1==ret2); 
    return 0;
}
