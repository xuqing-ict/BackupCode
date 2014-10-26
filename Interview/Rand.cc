#include <bits/stdc++.h>
using namespace std;

//select M from N
const int N = 300000;
const int M = 100000;
const int OFFSET = 60000;
const int GROUP = 5;

//这里利用rand函数形成最终的结果为0到RAND_MAX，于是这里将stl库中的rand函数进行改造，产生均匀的rand函数。
int StdRand()
{
    int group=rand()%2;
    int offset=rand();
    return group*RAND_MAX+offset;
}

int Rand()
{
    return StdRand();
}

int Rand60K()
{
    while(1)
    {
        int ret = Rand();
        if(ret < OFFSET) return ret;
    }
}
int Rand5()
{
    while(1)
    {
        int ret = Rand();
        if(ret < 65535) return ret%5;
    }
}
int RandIndex()
{
    int group = Rand5();
    int offset = Rand60K();
    return group*OFFSET + offset;
}

vector<int> print()
{
    vector<bool> f(N,false);
    vector<int> ret;
    ret.resize(M);
    int i=0;
    while(i<M)
    {
        int idx=RandIndex();
        if(f[idx] == false)
        {
            ++i;
            f[idx] = true;
        }
    }
    int k=0;
    for(int i=0;i<N;++i)
        if(f[i])ret[k++]=i;

    assert(ret.size() == M && M == k);
    return ret;
}

int main(void)
{
    srand((unsigned)time(NULL));
    cout << RAND_MAX << endl;
    vector<int> ret = print();
    sort(ret.begin(), ret.end());
    for(auto a: ret) cout << a << endl;
    return 0;
}
