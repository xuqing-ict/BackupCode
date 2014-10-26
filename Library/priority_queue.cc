/**
 * @file priority_queue.cc
 * @brief priority queue
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-30
 */

#include <queue>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
bool mycomparison(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
*/

class mycomparison
{
    bool reverse;
public:
    mycomparison(const bool& revparam=false)
    {reverse=revparam;}
    bool operator() (const string& lhs, const string&rhs) const
    {
        if (reverse) return (s[lhs].size() > s[rhs].size());
        else return (s[lhs].size() < s[rhs].size());
        
        //if (reverse) return (lhs.size() > rhs.size());
        //else return (lhs.size() < rhs.size());
    }
};

void func()
{
vector<string> s;
    string s1 = "123";
    string s2 = "234q";
    string s3 = "345qq";
    s.push_back(s1);
    s.push_back(s2);
    s.push_back(s3);

    priority_queue<string,vector<string>, mycomparison > uniq;
    for(int i = 0;  i < s.size(); ++i)
    {
        uniq.push(s[i]);
    }
    while(!uniq.empty())
    {
        cout << uniq.top() << endl;
        uniq.pop();
    }
 

}


int main()
{

    func();
   return 0;
}
