/**
 * @file priority_queue.cc
 * @brief priority queue
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-30
 */

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

/*
bool cmp(const int &i1, const int & i2)
{
    return s[i1].size() < s[i2].size();
}
*/
void func()
{vector<string> s;
s.push_back("123");
s.push_back("1234");
s.push_back("12345");
 
class cmp
{
  private:
      bool reverse;
  public:
      cmp(bool _reverse= false):reverse(_reverse){}
      bool operator ()(const int &lhs, const int &rhs)
      {
        if(reverse) return s[lhs].size() > s[rhs].size();
        else return s[lhs].size() < s[rhs].size();
      }
};
}
int main()
{
   cout << s.size() << endl;
  priority_queue<int,vector<int>, cmp> uniq;
  for(int i = 0;  i < s.size(); ++i)
  {
    uniq.push(s[i].size());
  }
  while(!uniq.empty())
  {
    cout << uniq.top() << endl;
    uniq.pop();
  }
  return 0;
}
