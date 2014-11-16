#include <bits/stdc++.h>
using namespace std;

int uglyNumber[1501];
/*
int getUglyNumber(const int N)
{
    if(N <=0 ) return 0; //不合法输入
    uglyNumber[0] = 1;
    int prevIndex2=1,prevIndex3=1,prevIndex5=1;
    if(uglyNumber[N] != 0) return uglyNumber[N-1];
    for(int i=1;i<N;++i)
    {
        uglyNumber[i] = min( min(prevIndex2*2,prevIndex3*3) ,prevIndex5*5);
        prevIndex2 = *upper_bound(uglyNumber,uglyNumber+i,uglyNumber[i]/2);
        prevIndex3 = *upper_bound(uglyNumber,uglyNumber+i,uglyNumber[i]/3);
        prevIndex5 = *upper_bound(uglyNumber,uglyNumber+i,uglyNumber[i]/5);
    }
    return uglyNumber[N-1];
}
*/

int getUglyNumber(const int N)
{
    if(N <=0 ) return 0; //不合法输入
    uglyNumber[0] = 1;
    int prevIndex2=0,prevIndex3=0,prevIndex5=0;
    if(uglyNumber[N] != 0) return uglyNumber[N-1];
    for(int i=1;i<N;++i)
    {
        uglyNumber[i] = min( min(uglyNumber[prevIndex2]*2,uglyNumber[prevIndex3]*3) ,uglyNumber[prevIndex5]*5);
        while(uglyNumber[prevIndex2]*2 <= uglyNumber[i])++prevIndex2;
        while(uglyNumber[prevIndex3]*3 <= uglyNumber[i])++prevIndex3;
        while(uglyNumber[prevIndex5]*5 <= uglyNumber[i])++prevIndex5;
    }
    return uglyNumber[N-1];
}
int main(void)
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        cout << getUglyNumber(N) << endl;
    }
    return 0;
}
