#include <bits/stdc++.h>
using namespace std;

void Func(const int target)
{
    int maxValue = target/2+1, l = maxValue, sum = l;

    for(int r = maxValue-1; r >= 1; --r)
    {
        sum += r;
        if(sum == target)
        {
            for(int i=l;i>r;--i)
                cout << i << " + ";
            cout << r << " = " << target << endl;
        }
        else if(sum > target)
        {
            sum -= l;
            --l;
        }
    }
    return;
}
int main(void)
{
    const int target = 100;
    Func(target);
    return 0;
}
