/**
 * @file Candy.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-30
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

using namespace std;

int canComplete(const vector<int> &gas, const vector<int> &cost)
{
    const int n = gas.size();
    assert(n == cost.size());
    int global = 0 ; //record the diff between cost and gas
    int start = 0 ; // start index
    int cur = 0 ; //current gas 
    for(int i = 0; i<n; ++i)
    {
        cur += (gas[i]-cost[i]);
        global += (gas[i] - cost[i]);
        if(cur < 0)
        {
            start = i+1;
            cur = 0;
        }
    }   
    return (global<0)?(-1):(start);

}


int main(void)
{
    vector<int> A = {};
    return 0 ;
}
