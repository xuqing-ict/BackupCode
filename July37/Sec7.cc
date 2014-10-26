/**
 * @file Sec7.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-15
 */

#include <bits/stdc++.h>
using namespace std;

//1000w的数据量，保证生成不重复的数据量
const int COUNT=10000000;
int num[COUNT];
void Random()
{
    for(int i=1;i<COUNT;++i)
        num[i-1]=i;
    srand((unsigned)time(NULL));
    long long i,j;
    for(int n=0;n<COUNT;++n)
    {
      i=(rand()*RAND_MAX+rand())%COUNT;
      j=(rand()*RAND_MAX+rand())%COUNT;
      cout << i << "\t" << j << endl;
      assert(i>=0 && i<COUNT && j>=0 && j<COUNT);
      swap(num[i],num[j]);
    }
    ofstream out("data.txt");
    for(int i=0;i<COUNT;++i)
        out << num[i] << endl;
    out.close();
    out.clear();
}

int main(void)
{
  Random();
  return 0;
}
