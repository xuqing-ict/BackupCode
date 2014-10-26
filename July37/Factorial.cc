#include <bits/stdc++.h>
using namespace std;

//¼ÆËã1/1£¡+ 1/2! + 1/3! + ... + 1/n!
double Factorial(const int n)
{
    double res=0;
    for(int i=n;i>=1;--i)
    {
        res = (1/(static_cast<double>(i)))*(1+res);
        cout << i << "\t" << res << endl;
    }
    return res;
}
//error version : big numbers eats the small number
double Factorial2(const int n)
{
    double ret=0;
    double tmp=1;
    for(int i=1;i<=n;++i)
    {
        tmp*=(1/(static_cast<double>(i)));
        ret += tmp;
    }
    return ret;
}

int main(void)
{
    int n;
    cin >>n;
    double ret1=Factorial(n);
    double ret2=Factorial2(n);
    printf("%10.100f\n%10.100f\n",ret1,ret2);
    return 0;
}


//From Rand5 to Rand7
int Rand5()
{
    return rand()%5+1;
}

int Rand7()
{
    while(1)
    {
        int group=Rand5();
        int offset=Rand5();
        int idx=(group-1)*5+offset;
        if(idx <= 21) return idx%7;
    }
}
/*
int main(void)
{
    for(int i=0;i<100;++i)
        cout << Rand7() << endl;
    return 0;
}
*/

//
