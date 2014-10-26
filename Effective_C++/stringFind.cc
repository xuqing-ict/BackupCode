//string find_first of
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string delim = "\t ";

int main()
{
	/*
	 * string s = "sec1\tsec2\tsec3";
	size_t left, right;
	left = 0;
	right = s.find_first_of(delim);
	while(string::npos != right)
	{
		cout << s.substr(left, right-left) << endl;
		left = right + 1;
		right = s.find_first_of("\t ",left);
	}
	cout << s.substr(left, right-left) << endl;
	return 0;
	*/
    /*
	ifstream in("./tt");
	int num1,num2;
	string line;

	while(!in.eof())
	{
		in >> num1 >> num2;
		if(in.eof())break;
		in >> line;
		cout << num1+num2 << endl;
	}
    */

    string s = "\t_90_876\t  \t";
    size_t split=s.find_first_of("_");
    string key;
    key.assign(s.begin(),s.begin()+split);
    cout<<key << "\t" << key.size() << endl;
    string value;
    value.assign(s.begin()+split+1,s.end());
    cout << value << "\t" << value.size() << endl;
    size_t left= s.find_first_not_of(" \t");
    cout << s.size() << endl;
  //  s.assign(s.begin()+left,s.end());
   // cout << s<< endl;
    //cout << s.size() << endl;
    size_t right= s.find_last_not_of(" \t");
    //s.erase(s.begin()+right+1, s.end());
    s.assign(s.begin()+left,s.begin()+right+1);
    cout << s << endl;
    cout << s.size() << "\t" << s.length() << endl;
	return 0;
}
