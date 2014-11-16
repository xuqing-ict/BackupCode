#include <iostream>
#include <vector>

using namespace std;

void helper(int cur_x, int cur_y, int cur_number, const int max_number, const int count_x, const int count_y, vector<vector<int> > &ret)
{
    if(cur_number == max_number)
    {
        ret[cur_x][cur_y] = max_number;
    }
    if(cur_number > max_number)
        return;
    //right
    for(int i = 0 ; i < count_y; ++i)
    {
        ret[cur_x][cur_y+i]=cur_number;
        cur_number++;
    }
    for(int i = 1 ; i < count_x; ++i)
    {
        ret[cur_x+i][cur_y+count_y-1]=cur_number;
        cur_number++;
    }
    for(int i = 1 ; i < count_y; ++i)
    {
        ret[cur_x+count_x-1][cur_y+count_y-1-i]=cur_number;
        cur_number++;
    }
    for(int i = 1 ; i < count_x-1; ++i)
    {
        ret[cur_x+count_y-1-i][cur_y]=cur_number;
        cur_number++;
    }
    cur_x++;
    cur_y++;
    helper(cur_x,cur_y,cur_number, max_number,count_x-2,count_y-2,ret);
    return;
}
vector<vector<int> > generateMatrix(int n) {
    if(n == 0 ) return vector<vector<int> > ();
    vector<vector<int> > ret(n,vector<int> (n,-1));
    int max = n*n;
    helper(0,0,1,max,n,n,ret);
    return ret;
}

int main()
{
    vector<vector<int> > ret = generateMatrix(4);
    for(int i=0; i < ret.size(); ++i)
    {
        for(int j = 0 ; j < ret[i].size(); ++j)
        {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
