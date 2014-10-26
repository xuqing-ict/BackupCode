#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

bool helper(const vector<vector<char> > &board, const string &word, const int maxRow, const int maxColumn, int row, int column, int curIndex , vector<vector<bool > > & visited)
{
	if (curIndex == word.size())
	{
		return true;
	}
	//from the upper
	if(row > 0 &&  visited[row-1][column] == false && board[row-1][column] == word[curIndex])
	{
		visited[row-1][column] = true;
			
		if(helper(board, word, maxRow, maxColumn, row-1,column,curIndex+1 ,visited))
		{
			return true;
		}
		else
		{
			visited[row-1][column] = false;
		}
	}

	if(row < maxRow - 1 && visited[row+1][column] == false && board[row+1][column] == word[curIndex])
	{
		visited[row+1][column] = true;
			
		if ( helper(board, word, maxRow, maxColumn, row+1,column,curIndex+1 ,visited))
		{
			return true;
		}
		else
		{
			visited[row+1][column] = false;
		}

		//visited[row+1][column] = false;
	}

	if(column > 0 &&  visited[row][column-1] == false && board[row][column-1] == word[curIndex])
	{
		visited[row][column-1] = true;
			
		if ( helper(board, word, maxRow, maxColumn, row,column-1,curIndex+1 ,visited))
		{
			return true;
		}
		else
		{
			visited[row][column-1] = false;
		}
	}

	if(column < maxColumn - 1 && visited[row][column+1] == false && board[row][column+1] == word[curIndex])
	{
		visited[row][column+1] = true;
			
		if ( helper(board, word, maxRow, maxColumn, row,column+1,curIndex+1 ,visited))
		{
			return true;
		}
		else
		{
			visited[row][column+1] = false;

		}
	}
	
    return false;
}

bool exist(const vector<vector<char> > &board, const string & word)
{
	if(word.empty())
	{
		return true;
	}
	int row = board.size();
	if (row == 0)
	{
		if (word.empty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int column = board[0].size();
	//visited
	//find enterance
	vector<vector<bool> > visited (row, vector<bool>(column, false));
	for(int i = 0 ; i < row ; ++i)
	{
		for(int j = 0 ; j < column ; ++j)
		{
			if (board[i][j] == word[0])
			{
				//clear
				for(int k = 0 ; k < row ; ++k)
				{
					for(int l = 0 ; l < column; ++l)
					{
						visited[k][l] = false;
					}
				}

				visited[i][j] = true;

				if(helper(board, word, row, column, i, j, 1, visited))
				{
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
  string word = "ABCB";
	   char s1[] = "ABCE";
	   char s2[] = "SFCS";
	   char s3[] = "ADEE";
	//string word = "aaaaa";
	//char s1[] = "aa";
	//char s2[] = "aa";
	//	char s3[] = "aaaa";
	vector<vector<char> > board;
	board.push_back(vector<char>(s1, s1+4));
	board.push_back(vector<char>(s2, s2+4));
	board.push_back(vector<char>(s3, s3+4));

	if(exist(board, word))
	{
		cout << word << " YES" << endl;
	}
	else
	{
		cout << word << " NO" << endl;
	}
	return 0;
}
