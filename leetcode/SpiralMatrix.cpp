#include <iostream>
#include <vector>
#include <iterator>
#include <assert.h>

using namespace std;

/*
 vector<int> spiralOrder(vector<vector<int> > &matrix) {
       // const int X[4] = {0,1,0,-1};
        //const int Y[4] = {1,0,-1,0};
        const int RIGHT = 0;
        const int DOWN = 1;
        const int LEFT = 2;
        const int UP = 3;

        vector<int> ret;
        int m = matrix.size();
        if(m==0)return ret;
        int n = matrix[0].size();

cout << m << " " << n << endl;

        int cur_x = 0, cur_y = 0 ;
        vector<vector< bool > > visited(m , vector<bool>(n,false));
        int label = 0;
        int k = RIGHT;
        bool KK = false;

        while(label < m*n)
        {
            cout << label << endl;

            if(k == RIGHT)
            {
                for(; cur_y < n; ++cur_y)
                {
                    //assert(visited[1][1] == false);
                    if(visited[cur_x][cur_y] == false)
                    {
                        visited[cur_x][cur_y] = true;
                        ret.push_back(matrix[cur_x][cur_y]);
                        cout << "RIGHT : push back " << matrix[cur_x][cur_y] << endl;
                        ++label;
                        cout <<label << endl;
                    }
                    else
                    {
                        break;
                    }
                }
                --cur_y;
                ++cur_x;

                k = DOWN;
                cout << "exit 1" << endl;
                copy(ret.begin(), ret.end(),ostream_iterator<int>(cout,"\t"));
                cout << endl;
                cout << "RIGHT : label = " << label << endl;
                //if(KK)
                  //  break;
            }
            else if(k ==  DOWN)
            {
                for(; cur_x < m; ++cur_x)
                {
                    if(visited[cur_x][cur_y] == false)
                    {
                        visited[cur_x][cur_y] = true;
                        ret.push_back(matrix[cur_x][cur_y]);
                        cout << "DOWN : push back " << matrix[cur_x][cur_y] << endl;
                        ++label;
                    }
                    else
                    {
                        break;
                    }
                }

                --cur_x;
                --cur_y;

                k = LEFT;
                cout << "exit 2" << endl;
                copy(ret.begin(), ret.end(),ostream_iterator<int>(cout,"\t"));
                cout << endl;
                cout << "DOWN : label : " << label << endl;
            }
            else if(k ==  LEFT)
            {
                for(; cur_y >= 0 ; --cur_y)
                {
                    if(visited[cur_x][cur_y] == false)
                    {
                        visited[cur_x][cur_y] = true;
                        ret.push_back(matrix[cur_x][cur_y]);
                        cout << "LEFT : push back " << matrix[cur_x][cur_y] << endl;
                        ++label;
                    }
                    else
                    {
                        break;
                    }
                }
                ++cur_y;
                --cur_x;
                k = UP;
                cout << "exit 3" << endl;
                copy(ret.begin(), ret.end(),ostream_iterator<int>(cout,"\t"));
                cout << endl;
                cout << "LEFT : label : " << label << endl;
            }
            else if(k ==  UP)
            {
                for(; cur_x >= 0 ; --cur_x)
                {
                    if(visited[cur_x][cur_y] == false)
                    {
                        visited[cur_x][cur_y] = true;
                        ret.push_back(matrix[cur_x][cur_y]);
                        cout << "UP : push back " << matrix[cur_x][cur_y] << endl;
                        ++label;
                    }
                    else
                    {
                        break;
                    }
                }
                ++cur_x;
                ++cur_y;

                k = RIGHT;
                cout << "exit 4" << endl;
                copy(ret.begin(), ret.end(),ostream_iterator<int>(cout,"\t"));
                cout << endl;
                cout << "UP : label : " << label << endl;
                //KK=true;
            }

        }
        return ret;
    }
*/
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int m = matrix.size();
        if(m == 0) return vector<int>();
        int n = matrix[0].size();
        vector<int> ret;
        int row=0,column=0;
        while(m > 0 && n > 0)
        {
            if(m == 1 || n == 1)
            {
                if(m == 1 )
                {
                    for(int j=column;j<column+n;++j)
                        ret.push_back(matrix[row][j]);
                }
                else if(n == 1)
                {
                    for(int i=row;i<row+m;++i)
                        ret.push_back(matrix[i][column]);
                }
                break;
            }
            for(int j=column;j<column+n-1;++j)ret.push_back(matrix[row][j]);
            for(int i=row;i<row+m-1;++i) ret.push_back(matrix[i][column+n-1]);
            for(int j=column+n-1;j>column;--j) ret.push_back(matrix[row+m-1][j]);
            for(int i=row+m-1;i>row;--i) ret.push_back(matrix[i][column]);
            ++row;++column;
            m-=2;n-=2;
        }
        return ret;
    }

int main()
{
    vector<vector<int> > matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    int m=matrix.size();
    int n = matrix[0].size();

    for(int i =0 ; i< m; ++i)
    {
        for(int j = 0 ; j < n ;++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> ret=spiralOrder(matrix);
    for(int i = 0 ; i < ret.size(); ++i)
        cout << ret[i] <<" ";
    cout << endl;
    return 0;
}
