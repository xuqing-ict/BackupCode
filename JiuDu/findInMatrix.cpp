//Search a specific number in Young Matrix
#include <bits/stdc++.h>
using namespace std;

bool searchInMatrix(const vector<vector<int> > &matrix, const int target)
{
    if(matrix.empty()) return false;
    const int row = matrix.size(), column = matrix[0].size();
    int i = 0 , j = column-1;
    while(true)
    {
        if(matrix[i][j] == target) return true;
        while(j >= 0 && i < row && matrix[i][j] > target) --j;
        while(j >= 0 && i < row && matrix[i][j] < target) ++i;
        if(j < 0 || i >= row) break;
    }
    return false;
}
int main()
{
    int row,column,target;
    while(scanf("%d\t%d\n",&row,&column)!= EOF)
    {
        scanf("%d\n",&target);
        //cout << row << column << target << endl;
        vector<vector<int> > matrix(row,vector<int>(column));
        for(int i =0; i< row; ++i)
            for(int j = 0 ; j < column; ++j)
                scanf("%d",&matrix[i][j]);

        if(searchInMatrix(matrix,target))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
