//数组A中是否存在几个数的和为sum的
//output all combinations
#include <iostream>
#include <vector>

using namespace std;

bool helper(const vector<int> &A, int index, int sum)
{
	if(index == A.size())
		return sum == 0;

	if (helper(A,index+1,sum)) return true;
	
	if (helper(A,index+1, sum-A[index])) return true;
	return false;
}
bool findSum(const vector<int> & A,const int sum)
{
	return helper(A, 0, sum);
}

void helper2(const vector<int> &A,vector<int> &cur,int cur_index,int cur_sum,const int sum,vector<vector<int> > &ret)
{
  if(cur_index == A.size())
  {
    if(cur_sum == sum)
    {
      ret.push_back(cur);
    }
    return;
  }
  //select 
  cur.push_back(A[cur_index]);
  helper2(A, cur,cur_index+1,cur_sum+A[cur_index],sum,ret);
  //not select
  cur.pop_back();
  helper2(A, cur,cur_index+1,cur_sum,sum,ret);
}

vector<vector<int > > findSum2(const vector<int> &A, const int sum)
{
  vector<vector<int> > ret;
  if(A.empty()) return ret;
  vector<int> cur;
  helper2(A,cur,0,0,sum,ret);
  return ret;
}
int main()
{
	int data[] = {1,2,4,7,4,-2};
	vector<int> A(data,data+sizeof(data)/sizeof(int));
    cout << A.size() << endl;
	int sum = 13;
	if(findSum(A,sum))
	{
		cout << "true" << endl;
	}

    vector<vector<int> > ret = findSum2(A,sum);
    cout << ret.size() << endl;
    for(int i = 0; i < ret.size(); ++i)
    {
      for(int j = 0 ; j < ret[i].size(); ++j)
      {
        cout << ret[i][j] << " ";
      }
      cout << endl;
    }

	return 0;
}
