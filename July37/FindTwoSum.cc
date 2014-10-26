/**
 * @file FindTwoSum.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-23
 */
//找两个数的和等于给定值sum
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> Pair;

vector<Pair> FindSum(vector<int> &vec, const int target)
{
    sort(vec.begin(),vec.end());
    const int n = vec.size();
    int left=0;
    int right=n-1;
    int tmp=0;
    vector<Pair> ret;
    Pair elem;
    while(left < right)
    {
        int tmp=vec[left]+vec[right];
        if(tmp == target) 
        {
            elem.first = vec[left];
            elem.second = vec[right];
            ret.push_back(elem);
        }
        if(tmp > target)
            --right;
        else ++left;
    }

    return ret;
}

//从整数1,2,3...,n之中选择和为target所有可能组合
void helper(int cur_number, const int max_number, const int target,int cur_sum, vector<int> &cur,vector<vector<int> > &ret)
{
    if(cur_number > max_number || cur_number > target)
    {
        if(cur_sum == target) ret.push_back(cur);
        return;
    }
    //select cur_number
    cur.push_back(cur_number);
    helper(cur_number+1,max_number,target,cur_sum+cur_number,cur,ret);
    cur.pop_back();
    //do not select cur_number
    helper(cur_number+1,max_number,target,cur_sum,cur,ret);

}
vector<vector<int> > FindSum(const int max_number, const int target)
{
    vector<int> cur;
    vector<vector<int> > ret;
    helper(1,max_number,target,0,cur,ret);
    return ret;
}

int main(void)
{
    vector<int> vec = {10,9,8,7,6,5,4,3,2,1,-1};
    vector<Pair> retPair = FindSum(vec,10);
    for(auto a : retPair)
        cout << a.first << "\t" << a.second << endl;
    cout << "Find Sum ..." << endl;
    vector<vector<int> > ret = FindSum(10,10);
    for(int i=0;i<ret.size();++i)
    {
        for(int j=0;j<ret[i].size();++j)
            cout << ret[i][j] << "\t";
        cout << endl;
    }
    return 0;
}
