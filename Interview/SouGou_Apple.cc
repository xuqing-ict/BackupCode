/**
 * @file SouGou_Apple.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-26
 */
//把M个同样的苹果放在N个同样的盘子里， 允许有点盘子空着不放， 问共有多少种不同的方法；（用K表示）如5,1,1和1,5,1是同一种分法；
//Input第一行是测试数据的数目t（0<=t<=20），以下每行均包含二个整数M和N，以空格分开；1<=M,N<=10；
//对输入的每组数据M和N，用一行输出相应的k
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

const int N = 11;
int f[N][N];

int apple(const int apple, const int n)
{
    fill_n(&f[0][0], N*N, INT_MIN);
    f[0][0] = 1;

    for(int i=0;i<apple+1;++i)
        f[i][0]=0;
    for(int j=0;j<=n;++j)
        f[0][j]=1;

    for(int i=1;i<apple+1;++i)
    {
        for(int j=1;j<n+1;++j)
        {
            if(i < j) f[i][j]=f[i][i];
            else f[i][j] = f[i][j-1]+f[i-j][j];
        }
    }
    return f[apple][n];
}
int main(void)
{
    int t;
    cin >> t;
    int M,N;
    for(int i=0;i<t;++i)
    {
        cin >> M >> N;
        cout << apple(M, N) << endl;
    }
    return 0;
}
