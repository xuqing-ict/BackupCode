/**
 * @file LongestConsetiveSeq.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-14
 */
#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &num) {
    //O(nlogn)
    sort(num.begin(), num.end());

    const int n=num.size();
    if(n < 2) return n;
    int ret=0, tmp=1,prev=num[0];

    for(int i=0;i<n;++i)
    {
        if(num[i] > prev+1)
        {
            if(tmp>ret)
            {
                ret=tmp;
            }
                tmp=1;
            prev = num[i];
            continue;
        }
        if(num[i]==prev+1){++tmp;++prev;}
    }
    if(tmp>ret) ret=tmp;
    return ret;
}
int main(void)
{
  vector<int> A = {9,1,-3,2,4,8,3,-1,6,-2,-4,7};
  cout << longestConsecutive(A) << endl;
  return 0;
}
