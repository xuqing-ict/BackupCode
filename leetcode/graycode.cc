    #include <bits/stdc++.h>
    using namespace std;
    ostream_iterator<int> out(cout, "\t");

    vector<int> grayCode(int n) {
        vector<int> ret;
        if(n == 0) return ret;
        ret.push_back(0);
        for(int i = 1; i < (1<<n) ; ++i)
        {
            ret.push_back((i>>1)^i);
        }
        return ret;
    }
    int main()
    {
        vector<int> ret = grayCode(2);
        copy(ret.begin(), ret.end(), out);
        cout << endl;
        return 0;
    }
