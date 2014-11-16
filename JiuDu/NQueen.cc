   #include <bits/stdc++.h>
using namespace std;

    bool isSafe(const int cur_row, const int cur_column, const vector<int> &column)
    {
        if(cur_row == 0) return true;
        //detect the conflict of the queues in previous lines and currrent queue
        for(int i=0;i<cur_row;++i)
        {
            if(column[i] == cur_column || abs(column[i]-cur_column) == abs(i-cur_row))
                return false;
        }
        return true;
    }
    void print(vector<vector<string> > &ret, const vector<int> &column)
    {
       int i=0;
       const int n = column.size();
       vector<string> cur;
       string line;
        for(int i=0;i<n;++i)
        {
            line.clear();
            line += string(column[i],'.');
            line += 'Q';
            line += string(n-column[i]-1,'.');
            cur.push_back(line);
        }

        ret.push_back(cur);
    }
    void helper(int cur_index, const int max_index, vector<int> &column, vector<vector<string> >& ret )
    {
        //locate end
        if(cur_index > max_index)
        {
            print(ret,column);
            return;
        }
        //locate the cur-index-th queue ,enumerate the column index of locate the cue_index-th queue
        for(int i=0 ; i<=max_index ; ++i)
        {
            //not locate any queue yet and safe for all prev queues
            if(isSafe(cur_index,i,column))
            {
                column[cur_index]=i;
                helper(cur_index+1,max_index,column,ret);
                //column[cur_index]=-1;
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<int> column(n,-1);
        vector<vector<string> > ret;
        helper(0,n-1,column,ret);
        return ret;
    }

int main(void)
{
    vector<vector<string> > ret = solveNQueens(4);
    cout << ret.size() << endl;
    for(int i=0;i<ret.size();++i)
    {
        for(int j=0;j<ret[i].size();++j)
            cout << ret[i][j] << endl;
        cout << endl;
    }
    return 0;
}
