/**
 * @file QinheShu.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-04
 */
//亲和数  两个数 a 和 b，使得a的真因子之和等于b，b的真因子之和等于a
//产生式模型
#include <bits/stdc++.h>
using namespace std;

const int N = 5000001;
int sum[N];

int main(void)
{
    int i,j;
    fill_n(&sum[0],N,1);
    for(int i=2;i+i<=N;++i)
    {
        j=i+i;
        while(j <= N)
        {
            sum[j]+=i;
            j+=i;
        }
    }
    for(int i=1;i<N;++i)
    {
        if(sum[i]>i && sum[i]<=N && sum[sum[i]]==i)
            cout << i << "\t" << sum[i] << endl;
    }
    return 0;
    
}
