/*N个骰子，每个骰子有C面，现在求各个可能出现的数的概率*/

#include <bits/stdc++.h>
using namespace std;

const int C = 7;
void printProb(const int N)
{
    if(N <= 0 )
    {
        cout << N << " dices..." << endl;
        return;
    }
    vector<int> prev (C*N+1,0);
    vector<int> next (C*N+1,0);

    for(int i=1;i<=C;++i) prev[i] = 1;

    for(int k = 2; k <= N;++k)
    {
        //K个骰子时，1-(K-1)的取值都应该清为0
        for(int i=0;i<k;++i) next[i] = 0;

        //每加入一枚骰子，可以改变的点数的范围是[k,C*k]
        for(int i=k;i<=C*k;++i)
        {
            //怎么影响的呢，当前的值 = 色子的点数 + prev[当前的点数-骰子的点数];
            for(int j=1; j<=i && j<=C ; ++j)
                next[i] += prev[i-j];
        }

        prev.swap(next);
        fill(next.begin(),next.end(),0);
        cout << "k = " << k << endl;
        for(int i=0;i<=C*N;++i)
            cout << prev[i] << "\t";
        cout << endl;
    }
    vector<double> prob(C*N+1,0);
    int sum = accumulate(prev.begin(),prev.end(),0);
    for(int i=N;i<=C*N;++i)
    {
        prob[i] = static_cast<double> (prev[i])/sum;
    }
    for(int i=0;i<C*N+1;++i)
    {
        cout << i << "\t" << prob[i] << endl;
    }
}
int main(void)
{
    printProb(4);
    return 0;
}
