#include <bits/stdc++.h>
using namespace std;

void helper(const vector<int> &candidates,const int max_index,int cur_index,int cur_sum,const int target,vector<int> &cur_set, vector<vector<int> > &ret)
{
    if(cur_index > max_index || cur_sum > target)
    {
        if(cur_sum == target) ret.push_back(cur_set);
        return;
    }

    int count = (target-cur_sum)/candidates[cur_index];
    for(int i=0;i<=count;++i)
    {
        cur_set.insert(cur_set.end(),i,candidates[cur_index]);
        helper(candidates,max_index,cur_index+1,cur_sum+i*candidates[cur_index],target,cur_set,ret);
        cur_set.resize(cur_set.size()-i);
    }
}


    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
       vector<vector<int> > ret;
        if(candidates.empty()) return ret;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> cur_set;
        helper(candidates,n-1,0,0,target,cur_set,ret);
        return ret;
    }

int main()
{
    vector<int> vec(2,1);
    vector<vector<int> > ret = combinationSum(vec,2) ;
    cout << ret.size() << endl;
    for(auto a:ret)
    {
        copy(a.begin(), a.end(), ostream_iterator<int>(cout,"\t"));
        cout << endl;
    }
    return 0;
}
