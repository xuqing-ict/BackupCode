#include <iostream>
#include <vector>
#include <assert.h>
#include <set>
#include <algorithm>

using namespace std;

void helper(const vector<int> &A, int cur_index, const int max_index, int cur_sum , vector<int> &cur_set, set<vector<int> > & ret)
{
    if(cur_sum > 0 ) return;
    if(cur_index > max_index)
    {
        if(cur_set.size() == 3 && cur_sum == 0 )
        {
            ret.insert(cur_set);
        }
        return;
    }
    cur_set.push_back(A[cur_index]);
    helper(A,cur_index+1, max_index, cur_sum+A[cur_index],cur_set,ret);
    cur_set.pop_back();
    helper(A,cur_index+1,max_index,cur_sum,cur_set,ret);
    return;
}

vector<vector<int> > threeSum(vector<int> &num)
{
    vector<vector<int> > ret;
    if(num.empty()) return ret;

    sort(num.begin(), num.end());

    int max_index = num.size()-1;

    vector<int> cur;
    set<vector<int> > ret2;

    helper(num, 0, max_index, 0, cur, ret2);
    cout << ret2.size() << endl;

    for(auto a:ret2)
    {
        ret.push_back(a);
    }
    return ret;
}
int findAnother(const vector<int> &A, int target)
{
    if(A.empty()) return -1;
    int left=0,right=A.size()-1;
    while(left <= right)
    {
        int mid=left+(right-left)/2;
        if(A[mid] == target) return mid;
        if(A[mid] < target) left = mid+1;
        else right=mid-1;
    }
    return -1;
}
vector<vector<int> > threeSum2(vector<int> &num)
{
    vector<vector<int> > ret;
    if(num.empty()) return ret;
    set<vector<int> > ret2;
    int n = num.size();
    sort(num.begin(), num.end());
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            int sum2 = num[i]+num[j];
            int index = findAnother(num,0-sum2);
            if(index != -1 && index != i && index != j )
            {

                if(index > j)
                {
                    vector<int> temp = {num[i],num[j],-sum2};
                    ret2.insert(temp);
                }
                else if(index > i)
                {
                    vector<int> temp = {num[i],-sum2,num[j]};
                    ret2.insert(temp);
                }
                 else
                {
                    vector<int> temp = {-sum2,num[i],num[j]};
                    ret2.insert(temp);
                }
            }
        }
    }
    for(auto a : ret2)
        ret.push_back(a);
    return ret;
}



int main()
{
    vector<int> A={-1,0,1,2,-1,-4};
    vector<vector<int> > ret = threeSum2(A);
    for(int i=0; i < ret.size(); ++i)
    {
        for(int j = 0 ; j < ret[i].size(); ++j)
        {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
