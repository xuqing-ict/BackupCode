#include <bits/stdc++.h>
using namespace std;

int minMultiply(const int n)
{
    if(n <= 2) return n;
    vector<int> vec(n,0);
    for(int i=0;i<n;++i) vec[i] = i + 1; //generate the [1...n] numbers
    int ret = 1;
    for(int i=1;i<n;++i) //vec[0] = 1, we can ignore
    {
        for(int j = i+1; j < n ; ++j)
        {
            if(vec[j] % vec[i] == 0) vec[j] /= vec[i];
        }
        ret *= vec[i];
    }
    return ret;
}

int main(void)
{
    int n ;
    cin >> n;
    cout << minMultiply(n) << endl;
    return 0;
}
