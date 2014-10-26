#include <bits/stdc++.h>
using namespace std;

//select M from N
const int N = 300000;
const int M = 100000;
const int OFFSET = 60000;
const int GROUP = 5;

//��������rand�����γ����յĽ��Ϊ0��RAND_MAX���������ｫstl���е�rand�������и��죬�������ȵ�rand������
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
