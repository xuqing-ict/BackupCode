// Last Update:2014-07-03 09:09:41
/**
 * @file FindTheNumberInMatrix.cpp
 * @brief 
 * @author Qing Xu xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-08
 */
#include <bits/stdc++.h>
using namespace std;

pair<int,int> search(const vector<vector<int> > &matrix, const int target)
{
  int m = matrix.size();
  if(m == 0) return make_pair(-1,-1);
  int n = matrix[0].size();
  int up = 0 , down = m-1, left = 0 , right = n-1;
  while(true)
  {
    while(right >= left && matrix[up][right] > target)
    {
      right--;
    }
    if(right < left) return make_pair(-1,-1);
    if(matrix[up][right] == target) return make_pair(up,right);
    while(up <= down && matrix[up][right] < target)
    {
      up++;
    }
    if(up > down) return make_pair(-1,-1);
    if(matrix[up][right] == target) return make_pair(up, right);
  }
  //  cout << "never be here..." << endl;
  //return make_pair(-1,-1);
}
pair<int,int> search2(const vector<vector<int> > &matrix, const int target)
{
  int m = matrix.size();
  if( m == 0) return make_pair(-1,-1);
  int n = matrix[0].size();
  int up = 0 ,down = m-1, left = 0 , right = n-1;
  while(true)
  {
    while(down >= up && matrix[down][left] > target) --down;
    if(down < up) return make_pair(-1,-1);
    if(matrix[down][left] == target) return make_pair(down,left);
    while(left <= right && matrix[down][left] < target) ++left;
    if(left > right) return make_pair(-1,-1);
    if(matrix[down][left] == target) return make_pair(down,left);
  }
}

int main()
{
  // vector<vector<int> > matrix = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{5,8,11,15}};
  //vector<vector<int> > matrix = {{1,2,8,9}};
  vector<vector<int> > matrix;
  srand (time(NULL));
  int row = rand()%10 +1;
  int column = rand() %10+1;
  
  for(int  i = 0; i < row; ++i)
  {
    matrix.push_back(vector<int>());
    matrix[i].push_back(i+1);
    for(int j= 1 ; j < column ; ++j)
    {
      matrix[i].push_back(rand()%100 +(i+1) + matrix[(i-1)>=0?(i-1):0][j]); 
    }
  }
  for(int i = 0 ;  i< row ; ++i)
  {
    sort(matrix[i].begin(), matrix[i].end());
  }
  for(int  i = 0; i < row; ++i)
  {
    for(int j= 0 ; j < column ; ++j)
      cout << matrix[i][j] << " ";
    cout << endl;
  }
  int row_1 = rand()%row;
  int column_1 = rand() %column;
  int target = matrix[row_1][column_1];
  cout << "target : " << target << endl;

  pair<int,int> ret = search(matrix, target);
  pair<int,int> ret2 = search2(matrix, target);
  cout << ret.first << " " << ret.second << endl;
  cout << ret2.first << " " << ret2.second << endl;
  
  return 0;
}

