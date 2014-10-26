/**
 * @file balanceArraySum.32.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-28
 */
/*32.(数组、规划)
 * 有两个序列 a,b,大小都为 n,序列元素的值任意整数,无序;
 * 要求:通过交换 a,b 中的元素,使[序列 a 元素的和]与[序列 b 元素的和]之间的差最小。
 * 例如:
 * var a=[100,99,98,1,2,3];
 * var b=[1,2,3,4,5,40];
 * /
 */
#include <bits/stdc++.h>
using namespace std;

int balance(const vector<int> &A, const vector<int> &B)
{
    const int n = A.size();
    assert(n == B.size());
    vector<int> C;
    for(auto a: A)C.push_back(a);
    for(auto a: B)C.push_back(a);

    cout << "C : " ;
    copy(C.begin(),C.end(),ostream_iterator<int>(cout,"\t"));
    cout << endl;

    //DP
    int sum = accumulate(A.begin(),A.end(),0);
    cout << "sum : " << sum << endl;

    int f[2*n+1][n+1][sum/2+1];
    //f[i][j][k]:从前i个元素中选择j个的最大和不超过k的最大值
    fill_n(&f[0][0][0],(2*n+1)*(n+1)*(sum/2+1),0);

    for(int i=1;i<=2*n;++i)
        for(int j=1;j<=min(i,n);++j)
            for(int k=C[i-1];k<=sum/2;++k)
                f[i][j][k] = max(f[i-1][j-1][k-C[i-1]] + C[i-1], f[i-1][j][k]);
    cout << "f[2n][n][sum/2] : " << f[2*n][n][sum/2] << endl;
    //backtrack
    int i=2*n,j=n,k=sum/2;
    cout << "result : " ;
    while(i>0)
    {
        if(f[i-1][j-1][k-C[i-1]] == f[i][j][k]-C[i-1])
        {
            cout << C[i-1] << endl;
            k-=C[i-1];
            --j;
        }
        --i;
    }
    return (sum-f[2*n][n][sum/2])-(f[2*n][n][sum/2]);
}

int main(void)
{
    vector<int> A = {100,99,98,1,2,3};
    vector<int> B = {1,2,3,4,5,40};
    cout << balance(A,B) << endl;
    return 0;
}
