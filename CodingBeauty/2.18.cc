#include <bits/stdc++.h>
using namespace std;

int minDev(const vector<int> &A)
{
    const int N = A.size();
    if( N < 2) return 0;
    const int n = N/2;

    int sum = accumulate(A.begin(),A.end(),0);
    cout << "sum : " << sum << endl;

    bool f[n+1][sum/2+1];
    fill_n(&f[0][0],(n+1)*(sum/2+1),false);

    f[0][0] = true; // 选取0个数的和为0.

    for(int i=1; i<=N; ++i) //依次考察每一个数，选或者不选
    {
        for(int j = min(n,i); j >= 1; --j) //选择的数的个数,只能最多选n/2个。
        {
            for(int s = 1; s <= sum/2; ++s) //选取数的和
            {
                //能不能选择i。
                if(s >= A[i-1] && f[j-1][s-A[i-1]])
                {
                    f[j][s] = true;
                }

            }
        }
    }
    int v = sum/2;
    while(v >= 0 && !f[n][v])--v;
    cout << "v : " << v << endl;
    cout << "ret : " << sum - 2*v << endl;
    return sum-2*v;
}

//01 bag Problem
//print optimal solution
int minDev2(const vector<int> &A)
{
    const int N = A.size();
    const int n = N/2;

    int sum= accumulate(A.begin(), A.end(),0);
    //dp[i][j][v] : 从i个数中选出k个数的和不超过v但是最大的和
    int dp[N+1][n+1][sum/2+1];

    fill_n(&dp[0][0][0],(N+1)*(n+1)*(sum/2+1),0);
    dp[0][0][0] = 0;

    for(int i=1; i<=N; ++i) //A[i-1]
    {
      for(int j=1; j <= min(n,i); ++j)//select j numbers
      {
        for(int v = A[i-1]; v <= sum/2; ++v) //sum //minimum sum is A[i-1]
        {
          dp[i][j][v] = max(dp[i-1][j-1][v-A[i-1]]+A[i-1],dp[i-1][j][v]);
        }
      }
    }
    //print result
    int i=N,j=n,v=sum/2;
    while(i>0)
    {
        if(dp[i][j][v] == dp[i-1][j-1][v-A[i-1]]+ A[i-1])
        {
          cout << A[i-1] << "\t";
          --j;
          v -= A[i-1];
        }
        --i;
    }
    cout << endl;
    cout << dp[N][n][sum/2] << endl;
    return dp[N][n][sum/2];
}

//split A into two subarrays
int minDev3(const vector<int> &A)
{
    const int N = A.size();
    for(int i=0; i<N ;++i)
        cout << A[i] << "\t";
    cout << endl;

    int sum = accumulate(A.begin(),A.end(),0);
    int dp[N+1][N+1][sum/2+1];
    fill_n(&dp[0][0][0],(N+1)*(N+1)*(sum/2+1),0);

    for(int i=1; i<=N; ++i)
    {
        for(int j=1; j<=i; ++j)
        {
            for(int v=A[i-1]; v<=sum/2; ++v)
            {
                dp[i][j][v] = max(dp[i-1][j-1][v-A[i-1]]+A[i-1],dp[i-1][j][v]);
            }
        }
    }
   
    cout << dp[N][N][sum/2] << endl;
    int i = N ,j = N, v = sum/2;
    while(dp[i][j][v] > 0)
    {
        if(dp[i][j][v] == dp[i-1][j-1][v-A[i-1]] + A[i-1])
        {
            cout << A[i-1] << "\t";
            j--;
            v-=A[i-1];
        }
        --i;
    }
    cout << endl;
    return sum-dp[N][N][sum/2];
}
int main(void)
{
    int n;
    cin >> n;
    vector<int> A(n,0);
    for(int i=0; i<n; ++i)
        cin >> A[i];
    cout << minDev(A) << endl;
    cout << minDev2(A) << endl;
    cout << "minDev3 : " << endl;
    cout << minDev3(A) << endl;
    return 0;
}
