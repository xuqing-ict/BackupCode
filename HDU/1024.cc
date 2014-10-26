#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

long maxMSubArray(const vector<int> &A, int m)
{
    const int n = A.size();
    if(m > n) m = n;

    vector<long> f(m+1,0);
    vector<long> g(m+1,0);

    for(int i=2;i<=n;++i)
    {
       f[1] = g[1] = A[0];
        for(int j=min(i,m); j>0; --j)
        {
            f[j] = max(f[j],g[j-1]) + A[i-1];
            g[j] = max(f[j],g[j]);
        }
    }
    return g[m];
}


int main(void)
{

    int n,m;
    while(scanf("%d %d",&m,&n) != EOF) {
        vector<int> A;
        A.resize(n);

        for(int i=0;i<n;++i)
            scanf("%d",&A[i]);

        cout << maxMSubArray(A,m) << endl;
    }
    return 0;
}
