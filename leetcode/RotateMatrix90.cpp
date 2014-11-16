#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

void rotate(vector<vector<int> > &matrix)
{
    if(matrix.empty()) return ;
    int m=matrix.size();
    int n=matrix[0].size();
    assert(m==n);
    int up=0,low=n-1;
    //上下翻折
    while(up<low)
    {
        matrix[up].swap(matrix[low]);
        ++up;--low;
    }
    //主对角线翻折
    for(int i = 0 ; i < n; ++i)
    {
        for(int j=0;j<i;++j)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    return ;
}

int main()
{
    vector<vector<int> > A={{1,2},{4,5}};
    int m = A.size(), n= A[0].size();
    for(int i=0; i < m;++i)
    {
        for(int j=0; j <n;++j)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    rotate(A);
    for(int i=0; i < m;++i)
    {
        for(int j=0; j <n;++j)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
