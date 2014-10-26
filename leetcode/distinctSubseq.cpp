#include<iostream>
#include<cstdlib>
#include<ctime>
#include<climits>
#include<string>

using namespace std;

int numDistinct(string S, string T)
{
	int row = T.size()+1;
	int column = S.size()+1;
	cout << "row = " << row << endl;
	cout << "column = " << column << endl;
	//int **matrix = new int*[column]; 
	//for(int i = 0; i < column; i++) 
	//{ 
	//	matrix[i] = new int[row];  
	//}

	int matrix [row][column];
	for(int ii = 0 ; ii < row; ++ii)
		for(int jj = 0 ; jj < column; ++jj)
				matrix[ii][jj]  = 0;
	//int *temp = new int[column];
	//int **matrix = new [] int[temp];
	for(int i = 0 ; i < row; ++i)
		matrix[i][0] = 0;
	for(int j = 0; j < column; ++j)
		//matrix[0][j] = 0;
		matrix[0][j] = 1; //空的T在S中存在一次

	for(int i = 0; i < row-1; ++i)
	{
		for(int j = 0; j < column-1; ++j)
		{
			if (T[i] == S[j])
			{
				//matrix[i+1][j+1] = max(matrix[i+1][j]+1, 1);
				matrix[i+1][j+1] = matrix[i+1][j] + matrix[i][j]; //分为两部分，使用当前S中的字符加上不使用S的当前字符的数目相加
			}
			else
			{
				//matrix[i+1][j+1] = matrix[i+1][j];
				matrix[i+1][j+1] = matrix[i+1][j];
			}
			cout << "T[" << i << "] = " << T[i] << " S[" << j << "] = " << S[j] << endl;
			for(int ii = 0 ; ii < row; ++ii)
		 	{
				for(int jj = 0 ; jj < column; ++jj)
					cout << matrix[ii][jj] << " ";
				cout << endl;
			}
		}
	}
	for(int i = 0 ; i < row; ++i)
	{
		for(int j = 0 ; j < column; ++j)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	//for(int i = 0 ; i < column ; ++i)
		//delete [] matrix[i];
	//delete matrix;

	int count = matrix[row-1][column-1];
	return count;
}	



int main()
{

	string S("ccc");
	string T("c");
	int count = numDistinct(S,T);
	cout << "count = " << count << endl;
	return 0;
}
