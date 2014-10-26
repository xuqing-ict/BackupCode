/**
 * @file 2.14.cc
 * @brief find the maximum sub array
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-05
 */

#include <bits/stdc++.h>
using namespace std;

ostream_iterator<int> out(cout,"\t");
vector<int> minSubArray(const vector<int> &A)
{
  int tmp=0; //local
  int gsum=A[0]; //global
  vector<int> ret;
  const int n = A.size();
  int start=0,end=0;
  int tmp_start = 0;

  for(int i=0;i<n;++i)
  {
    if(tmp <= 0)
    {
      tmp=0;
      tmp_start = i;
    }
    tmp += A[i];
    if(gsum < tmp)
    {
        gsum=tmp;
        start=tmp_start;
        end=i;
    }
  }
  cout << "gsum = " << gsum << endl;
  cout << start << "\t" << end << endl;
  for(int i=start;i<=end;++i)
  {
      cout << A[i] << "\t";
  }
  cout << endl;
  assert( accumulate(A.begin()+start,A.begin()+end+1,0) ==  gsum);
  return ret;
}
int main()
{
  srand(time(NULL));
  int n = rand()%20;
  vector<int> vec;
  for(int i=0; i<n;++i)
  {
    vec.push_back(rand()%100-50);
  }
  for(int i=0; i<n; ++i)
    cout << vec[i] << "\t";
  cout << endl;
  vector<int> ret = minSubArray(vec);
}
