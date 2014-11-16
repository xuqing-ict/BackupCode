#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    scanf("%d",&n);
    vector<int> s(51,0);
    s[0] = 0;
    s[1] = 1;
    int sum = 1;
    for(int i=2;i<=n;++i)
    {
        s[i] = sum +1;
        sum += s[i];
    }
    cout << s[n] << endl;
    return 0;
}
