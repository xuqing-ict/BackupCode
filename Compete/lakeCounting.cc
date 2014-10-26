//数一个区域的八联通的区域的个数
#include <iostream>
#include <vector>

//#include <stdlib.h>
#include <stdio.h>

using namespace std;

void dfs(vector<string> &field, const int row, const int column)
{
  field[row][column] = '.';
  int m = field.size(), n = field[0].size();

  for(int i = -1 ; i <= 1; ++i)
  {
    for(int j = -1 ; j <= 1; ++j)
    {
      int dx = row+i, dy = column+j;
      if(dx >= 0 && dx < m && dy >= 0 && dy < n && field[dx][dy] == 'W')
      {
        //field[dx][dy] = '.';
        dfs(field,dx,dy);
      }
    }
    
  }
}


int Count(vector<string> & field)
{
	int ret = 0;
	int m = field.size();
	if (m == 0) return 0;
	int n = field[0].size();
	for(int i = 0 ; i < m ; ++i)
		for(int j = 0 ; j < n ; ++j)
			if (field[i][j] == 'W')
			{
				dfs(field,i,j);
				ret++;
			}
	return ret;
}





int main()
{

    int m,n;
    vector<string> A;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        A.resize(m);
        for(int i=0;i<m;++i)
        {
            cin >> A[i];
        }
        cout << Count(A) << endl;
    }
    return 0;
}
