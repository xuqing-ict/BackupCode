//Given n. print the n-bit number which the digit is consecutive number.
//for example, 123,234,345,....
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void helper(int cur_digit, int cur_cnt, const int max_cnt, string &cur)
{
        if(cur_cnt == max_cnt)
        {
            cout << cur << endl;
            return;
        }
    cur.push_back('0' + cur_digit);
    helper(cur_digit+1,cur_cnt+1,max_cnt,cur);
    cur.pop_back();
}

void print(const int n)
{
    if(n <= 0 ) return;
    string cur;
    //the first digit
    for(int i=1;i<=10-n;++i)
        helper(i,0,n,cur);
}

int main(void)
{
    int n =
    print(n);
    return 0;
}
