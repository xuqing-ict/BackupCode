
//给定数字N,打印出N的所有的正数的组合。 如 15 = 1 + 2 + 3 + 4 +5 = 4 + 5 + 6 = 7 + 8
#include <bits/stdc++.h>
using namespace std;

void print(const int l,const int r, const int N)
{
    for(int i=l;i<r;++i)cout << i << " + ";
    cout << r << " = " << N << endl;
}

void printAllCombination(const int N)
{
    if(N < 2) return;
    int sum = 0, r = 0;
    const int right = (N+1)/2;

    for(int l=1;l <= right;++l)
    {
        while(r <= right && sum < N)
        {
            ++r;
            sum += r;
        }
        if(sum == N) print(l,r,N);
        sum -= l;
    }
}

void printAllCombination2(const int N)
{
    if( N < 2) return ;
    int j = (sqrt(8*N+1)-1)/2;
    cout << "j = " << j << endl;
    for(int i=1;i<=j;++i)
    {
        double a = (static_cast<double>(N))/(i+1) - (static_cast<double>(i))/2;
        if(a == (int)a && (int)a > 0) print(a,a+i,N);
    }
}
int main(void)
{
    int N;
    cin >> N;
    printAllCombination(N);
    printAllCombination2(N);
    return 0;
}

