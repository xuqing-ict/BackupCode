//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
LL print(LL p[],const LL k)
{
    //cout << p[0] << " " << p[1] << " " << p[2] << " " << k << endl;
    vector<LL> vec(k+1,0);

    sort(p,p+3);
    vec[0] = 1;
    LL prev1 = 0, prev2 = 0, prev3 = 0;
    for(int i=1;i<=k;++i)
    {
        vec[i] = min(vec[prev1]*p[0],min(vec[prev2]*p[1],vec[prev3]*p[2]));
        while(vec[prev1]*p[0] <= vec[i]) ++prev1;
        while(vec[prev2]*p[1] <= vec[i]) ++prev2;
        while(vec[prev3]*p[2] <= vec[i]) ++prev3;
    }
    //cout << "vec = ";
    //for(auto a: vec)cout << a << " ";
    //cout << endl;

    return vec[k];
}
int main(void)
{
    LL p[3],k;
    while(cin >> p[0] >> p[1] >> p[2] >> k)
    {
        cout << print(p,k) << endl;
    }
    return 0;
}
