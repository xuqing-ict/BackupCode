
#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ULL;

bool isPrime(ULL n, ULL &factor)
{
    for(ULL i=2;i*i<=n;++i)
        if(n%i==0) {factor=i;return false;}
    factor=1;
    return true;
}

int main(void)
{
    int n;
    cin >> n;
    ULL m;
    ULL factor=1;
    for(int i=0;i<n;++i)
    {
        cin >> m;
        if(isPrime(m,factor)) cout << "Prime" << endl;
        else cout << factor << endl;
    }
    return 0;
}
