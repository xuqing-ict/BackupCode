/**
 * @file vector.cc
 * @brief vector, reverse two dimensional vector
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-27
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int > > vec = {{1,2,3},{4,5}};
    reverse(vec.begin(),vec.end());
    for(int i=0;i<vec.size();++i)
    {
      for(int j=0;j<vec[i].size();++j)
          cout << vec[i][j] << " ";
      cout << endl;
    }
    return 0;
}
