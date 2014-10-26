#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>

using namespace std;


int main()
{
	int matrix[][4] = { {1, 3,  5,  7},  {10, 11, 15, 20}, {23, 30, 34, 50} };
	int target = 14;
	int row = sizeof(matrix)/sizeof(int)/4;
	int column = 4;
	cout << "row = " << row << endl;
	cout << "column = " << column << endl;
	for(int i = 0 ;i < row; i++)
	{
		for(int j = 0;j < column;++j)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	int begin = 0, end = row*column-1;
	int pos1, pos2;
	while(begin <= end)
	{
		int mid = begin+ (end-begin)/2;
		pos1 = mid/column;
		pos2 = mid%column;
		
		cout << "begin = " << begin << "end = " << end << endl;
		cout << "pos1 = " << pos1 << "pos2 = " << pos2 << "\t" << matrix[pos1][pos2] << endl;
		cout << endl;

		if (matrix[pos1][pos2] == target)
		{
			cout  << "find " << "pos1 = " << pos1 << "\tpos2 = " <<  pos2 << endl;
			break;		
		}
		else if (matrix[pos1][pos2] > target)
		{
			end = mid-1;
		}
		else
		{
			begin = mid+1;
		}
	}
	cout << "begin = " << begin << "end = " << end << endl;
	return 0;
}
