#include <iostream>
#include <vector>
#include <iterator>
//#include <algorithm>
#include<string>

using namespace std;

int main()
{
	istream_iterator<int> cin_int(cin);
	istream_iterator<int> eof;
	ostream_iterator<int> cout_int(cout,"\n");
	//vector<int> vec;
	while(cin_int != eof)
	{
		//vec.push_back(*cin_int++);
		*cout_int++ = *cin_int++;
	}
	/*
	vector<int> vec(cin_int,eof);
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout," "));
	*/
	string str = "012345678";
	cout << str << endl;
	str.resize(str.size()-5);
	cout << str << endl;
	return 0;

}
