#include <iostream>
#include <vector>
#include <iterator>
#include <stdlib.h>
#include <queue>

using namespace std;

void quickSort(vector<int> &A, int l ,int r)
{
    if(l >= r)
    {
        return;
    }
    int  i = l, j = r-1,pivot = A[r];
    while(i < j)
    {
        while(i < j && A[l] <= pivot)++i;
        while(j > i && A[r] > pivot)--j;
        if(i <= j )
        {
            swap(A[i++],A[j++]);
        }
    }
    swap(A[j],A[r]);
    quickSort(A,l,j-1);
    quickSort(A,i,r);
}



int FindKMin(const vector<vector<int> > &matrix, int K)
{
    if(matrix.empty())
    {
        return 0;
    }
    priority_queue<int> pq;
    int row = matrix.size();
    int column = matrix[0].size();

    for(int i = 0 ; i < row ; ++i)
    {
        //vector<int> &array = matrix[i];
        quickSort(matrix[i], 0, K-1);
        cout << "after sort" << endl;
        for(int i = 0 ; i < K ; ++i)
        {
            for(int j = 0 ; j < K ; ++j)
            {
                cout << matrix[i][j] << " " ;
            }
            cout << endl;
        }
    }
    int sum = 0;
    //第一个数组的K个数
    for(int i = 0 ; i < K ; ++i)
    {
        sum = array[0][i];
        //其他数组的K-1的元素
        for(int j = 1 ; j < K ; ++j)
        {
            sum += matrix[j][0];
        }
        pq.insert(sum);
    }
}
int main()
{
    int K = 5;
    vector<vector<int> > arrays(K, vector<int>(K,0));
    for(int i = 0 ; i < K ; ++i)
    {
        for(int j = 0 ; j < K ; ++j)
        {
            arrays[i].push_back(rand()%10);
        }
    }
    for(int i = 0 ; i < K ; ++i)
    {
        for(int j = 0 ; j < K ; ++j)
        {
            cout << arrays[i][j] << " " ;
        }
        cout << endl;
    }
    cout << FindKMin(arrays) << endl;

    return 0;
}
