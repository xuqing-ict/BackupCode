#include <iostream>
#include <vector>
#include <iterator>
#include <cassert>

using namespace std;

vector<vector<int > > Compute(const vector<vector<int> > &A, const vector<vector<int > > &B)
{
    int m = A.size(), n = A[0].size(), k = B[0].size();
    assert(n == B.size());
    vector<vector<int > > ret(m,vector<int>(k,0));
    for(int i = 0 ; i < m ; ++i)
    {
        for(int j= 0 ; j < k ; ++j)
        {
            for(int l = 0 ; l < n ; ++l)
            {
                ret[i][j] += (A[i][l] * B[l][j]);
            }
        }
    }
    return ret;
}

vector<vector<int> > Func(const vector<vector<int > > &A, int index)
{
    if(A.size() == 0) return vector<vector<int> >();
    assert(A.size() == A[0].size());

    if( index == 0 )
    {
        vector<vector<int > > ret(A.size(), vector<int>(A[0].size(),0));

        for(int i = 0 ; i < ret.size() ; ++i)
            for(int j = 0 ; j < ret[0].size() ; ++j)
                if(i == j ) ret[i][j] = 1;
                else ret[i][j] = 0;
        return ret;
    }

    if(index == 1) return A;
    vector<vector<int> > ret = Func(A,index/2);
    ret = Compute(ret,ret);
    if(index % 2)
    {
        ret = Compute(ret,A);
    }
    return ret;
}




int main()
{
    vector<vector<int> > A(2,vector<int>(2,2));
    //A[0][0] = A[1][1] =  2;
    vector<vector<int> > ret = Func(A,2);
    for(int i = 0 ; i < ret.size(); ++i)
    {
        copy(ret[i].begin(), ret[i].end(), ostream_iterator<int>(cout,"\t"));
        cout << endl;
    }
    return 0;
}
