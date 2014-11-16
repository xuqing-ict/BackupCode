
/*从扑克牌中随机抽出5张牌，看是不是顺子，大小王可以当做任何数字*/
#include <bits/stdc++.h>
using namespace std;

bool isContinuos(vector<int> & A)
{
    const int n = A.size();
    if(n < 2) return true;
    sort(A.begin(),A.end());
    int zeroCount = 0, gapCount=0;
    int i = 0;
    for(;i<n && A[i] == 0;++i) ++zeroCount;
    for( ; i+1<n ; ++i)
    {
        if(A[i+1] == A[i]) return false;
        gapCount += A[i+1]-A[i]-1;
    }
    return gapCount == zeroCount;
}

int main(void)
{
    int n;
    vector<int> A;
    while(scanf("%d",&n) != EOF)
    {
        A.resize(n);
        for(int i=0;i<n;++i)
            scanf("%d",&A[i]);
        if(isContinuos(A)) cout << "So Lucky!" << endl;
        else cout <<  "Oh My God!" << endl;
    }
    return 0;
}
