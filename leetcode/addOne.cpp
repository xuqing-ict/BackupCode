#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
   
 vector<int> plusOne(vector<int> &digits) {
        vector<int > ret = digits;
        if(ret.empty())
        {
            return ret;
        }
        int carryIndex = -1;
        int  i = 0;
        while( i < ret.size())
        {
            while(i < ret.size() && ret[i] == 9)
            {
                ++i;
            }
            if(i < ret.size() ) 
            {
                carryIndex = i;
            }
            ++i;
        }
		cout << "carryIndex : " << carryIndex << endl;
        i = ret.size() - 1;
        while( i > carryIndex)
        {
			cout << "DEBUG : " << i << "\t" << carryIndex << endl;
            ret[i] = 0;
            --i;
        }
		cout << "DEBUG end" << endl;
        if(carryIndex == -1)
        {
            ret.insert(ret.begin(), 0);  
			carryIndex = 0;
        }
        ret[carryIndex] += 1;
        return ret;
    }
int main()
{
	vector<int> A(1,9);
	vector<int> ret;
	ret = plusOne(A);
	copy(ret.begin(), ret.end(), ostream_iterator<int>(cout,"\t"));
	cout << endl;
	return 0;
}
