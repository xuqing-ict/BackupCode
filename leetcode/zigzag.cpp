  #include <iostream>
  #include <vector>
  #include <string>

  using namespace std;



    string convert(string s, int nRows) {
        if(s.empty() || nRows == 0) return "";
        if(nRows == 1) return s;

        vector<string> levels(nRows,"");
        int  i = 0;
        levels[0] += s[0];
        ++i;
        while( i < s.size())
        {
            int j = 1;
            while(i < s.size() && j <= (nRows-1))
            {
                levels[j] += s[i];
                ++j;
                ++i;
            }
            j = nRows-2;
            while(i < s.size() && j >= 0)
            {
                levels[j] += s[i];
                --j;
                ++i;
            }
        }
        string ret;
        for(int i = 0 ; i < levels.size(); ++i)
        {
            cout << levels[i] << endl;
            ret += levels[i];
        }
        return ret;
    }
    int main()
    {
        string s = "PAYPALISHIRING";
        cout << convert(s,3) << endl;
        return 0;
    }
