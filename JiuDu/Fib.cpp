#include <bits/stdc++.h>
using namespace std;

long long Fib1(const int n)
{
    if(n < 2) return n;
    return Fib1(n-2) + Fib1(n-1);
}

vector<vector<long long> > compute(const vector<vector<long long> > &lhs, const vector<vector<long long > > &rhs)
{
    vector<vector<long long > >ret;
    const int m = lhs.size(), n = lhs[0].size(), l = rhs[0].size();
    ret.resize(m, vector<long long >(l,0));
    assert(n == rhs.size());
    for(int i = 0 ; i < m; ++i)
    {
        for(int j = 0 ; j < l ; ++j)
        {
            ret[i][j] = 0;
            for(int k = 0 ; k < n ; ++k)
            {
                ret[i][j] += lhs[i][k] * rhs[k][j];
            }
        }
    }
    return ret;
}

void helper(int n, vector<vector<long long> > &ret)
{
    vector<vector<long long > > tmp;
    tmp.resize(2,vector<long long >(2,1));
    tmp[1][1] = 0;
    //根据n的二进制表示来做，但是需要每一步将低位的输出作为中间变量，以防高位为1！！
    while(n)
    {
        if(n & 1) ret = compute(ret,tmp);
        tmp = compute(tmp, tmp);
        n >>= 1;
    }
}

long long Fib2(const int n)
{
    if(n < 2) return n;
    vector<vector<long long> >  ret;
    ret.resize(2,vector<long long>(2,0));
    ret[1][1] = ret[0][0] = 1;

    helper(n-1, ret);
    return ret[0][0];
}

void helper2(int n, vector<vector<long long> > &ret, const vector<vector<long long> > & tmp)
{
    if(n == 1) //n=1,应该返回单位阵！！！
    {
        ret = tmp;
        return;
    }
    helper2(n/2,ret,tmp);
    ret = compute(ret,ret);
    if(n&1) ret = compute(ret,tmp);
    return;
}
vector<vector<long long> > helper3(const int n, const vector<vector<long long > > &tmp)
{
    if(n == 0)
    {
        return vector<vector<long long> >{{1,0},{0,1}};
    }
    if(n == 1 ) return tmp;
    auto ret = helper3(n/2,tmp);
    ret = compute(ret, ret);
    if(n&1) ret = compute(ret,tmp);
    return ret;
}
long long Fib3(const int n)
{
    if(n < 2) return  n;
    /*vector<vector<long long> > ret;
    ret.resize(2, vector<long long>(2,0));
    ret[1][1] = ret[0][0] = 1;
*/
    vector<vector<long long> > tmp;
    tmp.resize(2, vector<long long>(2,1));
    tmp[1][1] = 0;
    auto ret = helper3(n-1, tmp);
    return ret[0][0];
}

int main()
{
    int n;
    cin >> n;
    cout << Fib1(n) << endl;
    cout << Fib2(n) << endl;
    cout << Fib3(n) << endl;
    return 0;
}
