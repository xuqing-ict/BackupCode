   #include <bits/stdc++.h>
   using namespace std;

    bool isValidSudoku(vector<string > &board)
    {
        //row
        unordered_set<char> exist;
        //all row
        for(int i = 0 ; i < 9; ++i)
        {
            cout << i << endl;
            //each row, clear the exist
            exist.clear();
            for(int j = 0 ; j < 9 ; ++j)
            {
                if(exist.find(board[i][j]) != exist.end())
                {
                    cout << board[i][j] << "\tcase1" << endl;
                    return false;
                }
                else
                    exist.insert(board[i][j]);
            }
        }

          for(int i = 0 ; i < 9; ++i)
          {//each column, clear the exist
             exist.clear();
                for(int j = 0 ; j < 9 ; ++j)
                {
                    if(exist.find(board[j][i]) != exist.end())
                    {
                        cout << "case2" << endl;
                        return false;
                    }
                    else
                        exist.insert(board[j][i]);
                }
          }
          //3*3
        for(int i = 0 ; i < 3 ; ++i)
        {
            for(int j = 0 ; j < 3 ; ++j)
            {
                //for each 3*3 clear the exist
                exist.clear();
                for(int k = 3*i; k < 3*(i+1); ++k)
                {
                    for(int l = 3*j; l < 3*(j+1) ; ++l)
                    {
                        if(exist.find(board[k][l]) != exist.end())
                        {
                            cout << "case3" << endl;
                            return false;
                        }
                        else
                            exist.insert(board[k][l]);
                    }
                }
            }
        }
        return true;
    }
int main()
{
    vector<string > board = {".87654321","2........","3........","4........","5........","6........","7........","8........","9........"};
    cout << isValidSudoku(board) << endl;
    return 0;
}
