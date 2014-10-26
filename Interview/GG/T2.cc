/**
 * @file T2.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-16
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

vector<int>  printMaxTwo(const vector<int> &A , const int k)
{
    typedef map<int,int>::value_type Elem;
    const int n = A.size();
    map<int,int> idxs;
    for(int i=0;i<n;++i)
    {
        if(idxs.find(A[i]) != idxs.end())
        {
            ++idxs[A[i]];
        }
        else
        {
            idxs.insert(Elem(A[i],1));
            if(idxs.size() == k)
            {
                //if there is a full level in the box
                for(auto iter = idxs.begin(); iter != idxs.end();)
                {
                    --((*iter).second);
                    if((*iter).second == 0) iter = idxs.erase(iter);
                    else ++iter;
                }
            }       
        }
    }
    //If there exists no element in the final box
    vector<int> ret;
    for(auto a: idxs) a.second = 0;
    for(auto a: A)
    {
        if(idxs.find(a) != idxs.end())
            ++idxs[a];
    }
    for(auto a: idxs)
        if(a.second >= n/k) ret.push_back(a.first);
    return ret;
}
int main(void)
{
    int n;
    int k = 3;
    cin >> n;
    vector<int> A;
    A.resize(n);
    for(int i=0;i<n;++i)
        cin >> A[i];

    vector<int> ret = printMaxTwo(A,k);
    for(auto a: ret)
        cout << a << " ";
    cout << endl;
    return 0;
}
