/**
 * @file FindTwoNumberOccurOnce.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-19
 */

#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> P;

P findTwoUniqueNumber(const vector<int> &A)
{
    const int n = A.size();
    P ret;
    ret.first = ret.second = -1;

    if(n < 2) return ret;
    int tmp = 0 ;
    for(int i=0;i<n;++i)
        tmp &= A[i];
    if(tmp == 0) return ret;
    

}
int main(void)
{
    int n;
    vector<int> A;
    while(scanf("%d",&n) != EOF)
    {
        A.resize(n);
        P ret = findTwoUniqueNumber(A);
        cout << ret.first << " " << ret.second << endl;
    }
    return 0;
} 
