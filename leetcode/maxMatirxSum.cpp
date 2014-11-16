#include <iostream>
#include <vector>
#include <iterator>
#include <limits.h>

using namespace std;

void helper(vector<vector<int> > &matrix, int &ret, vector<bool> &visited, int curSum, int curRow, const int maxRow, const int maxColumn)
{
    if(curRow > maxRow)
    {
        if(curSum < ret)
        {
            ret = curSum;
        }
        return;
    }
    for(int i = 0 ; i <= maxColumn ; ++i)
    {
        if(visited[i])
        {
            continue;
        }
        curSum += matrix[curRow][i];
        visited[i] = true;
        helper(matrix,ret,visited,curSum,curRow+1,maxRow, maxColumn);
        visited[i] = false;
    }
}

int minSum(vector<vector<int > > & matrix)
{
    int row = matrix.size();
    if(row == 0) return 0;
    int column = matrix[0].size();
    vector<bool> visited (row,0);
    int ret = INT_MAX;
    //cout << ret << endl;
    int curSum = 0;
    int curRow = 0;
    helper(matrix,ret,visited,curSum,curRow,row-1,column-1);
    return ret;
}
int main()
{
    vector<vector<int> > matrix;
    vector<int> a;
    a.push_back(-1);
    a.push_back(2);
    matrix.push_back(a);
    a.clear();
    a.push_back(3);
    a.push_back(5);

    matrix.push_back(a);
    for(int i = 0 ; i < matrix.size(); ++i)
    {
        copy(matrix[i].begin(), matrix[i].end(),ostream_iterator<int>(cout,"\t"));
        cout << endl;
    }
    cout << "result : " << minSum(matrix) << endl;
    return 0;
}
