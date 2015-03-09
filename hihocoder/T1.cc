/**
 * @file T1.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2015-03-09
 */

#include <bits/stdc++.h>
using namespace std;

int findTarget(const vector<int> & vec, const int target)
{
    const int n = vec.size();
    int i = 0;
    bool find = false;
    for(int  k = 0 ; k < n ; ++k)
    {
        if(vec[k] == target){find = true;} 
        if(vec[k] < target) ++i;
    }
    return find?(i+1):-1;
}
int main(void)
{
    int n, target;
    cin >> n >> target;
    vector<int> vec(n,0);
    for(int i =0;i<n;++i)
    {
        cin >> vec[i];
    }
    cout << findTarget(vec,target) << endl;
    return 0;
}

