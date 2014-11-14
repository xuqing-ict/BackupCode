/**
 * @file dice.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-11-02
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


void helper(const int n, const int m, int cur_index, int sum, vector<int> &cnt)
{
    if(cur_index > n) 
    {
        cnt[sum]++;
        return;
    }
    int tmp = sum;
    for(int i=1;i<=m;++i)
    {
        sum = tmp;
        sum += i; // add current dice's index
        helper(n,m,cur_index+1,sum,cnt);
    }
}

double win2(const int n, const int m, const int x)
{
    if(x < n || x > m*n) return 0;
    vector<int> cnt(n*m+1,0);
    helper(n,m,1,0,cnt);
    int cn = accumulate(cnt.begin()+x,cnt.end(),0);
    int sum = accumulate(cnt.begin(),cnt.end(),0);
    cout << cn << " " << sum << endl;
    return static_cast<double>(cn)/sum;
}


double win(const int n, const int m, const int x)
{
    if(x < n || x > m*n) return 0.0; // illegal x
    vector<int> prev(n*m+1,0);
    vector<int> next(n*m+1,0);
    //init
    for(int i=1;i<=m;++i) prev[i]=1;

    for(int k = 2;k <= n ; ++k) //dice count
    {
        //update each elem in next
        vector<int>(n*m+1,0).swap(next);
        for(int i=k;i<= m*k; ++i) //the updated index is in a range
        {
            //add prev m elems
            for(int j=1; j<=i && j<=m;++j)
            {
                next[i] += prev[i-j];
            }
        }
        prev.swap(next);
    }

    int cn = 0;
    for(int i=x;i<m*n+1;++i)
        cn += prev[i];
    int sum = accumulate(prev.begin(),prev.end(),0);
    cout << cn << " " << sum << endl;
    return static_cast<double>(cn)/sum;
}


int main(void)
{
    srand(time(nullptr));
    int k=100;
    while(k--)
    {
        int n,m; // n dices, each 1-m 
        //cin >> n >> m; //n dices, each with m
        n = rand()%10+1;
        m = rand()%10+3;
        int x;
        //cin >> x ; // greater than x win.
        x = rand()%(m*n)+n;
        double ret1=win(n,m,x);
        double ret2=win(n,m,x);
        assert(ret1 == ret2);
        cout << ret1 << " " << ret2 << endl;
    }
    return 0 ;
}
