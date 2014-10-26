#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

string ComputeStrChar(string s1_t,char c);
string addString(string s1, string s2);
void addSameLenString(string s1, string s2, int cur_index, int &carry, string &ret);


string ComputeStrChar(string s1_t,char c)
{
	int index = c - '0';

	string ret;
	for(int i = 0 ;i < index; ++i)
	{
		ret = addString(ret,s1_t);
	}
	return ret;
}
string addString(string s1, string s2)
{
	if(s1.empty())return s2;
	if(s2.empty()) return s1;

	int n1 = s1.size(), n2 = s2.size();
	if (n1 < n2) swap(s1,s2);
	for(int i = 0 ; i < abs(n1-n2);++i)
		s2  = '0' + s2;

	int carry = 0;
	string ret(max(n1,n2),'0');
	addSameLenString(s1,s2,0,carry,ret);
	if(carry) ret = '1' + ret;
	return ret;
}
void addSameLenString(string s1, string s2, int cur_index, int &carry, string &ret)
{
	if(cur_index >= s1.size()) return;
	addSameLenString(s1,s2,cur_index+1,carry,ret);
	int sum = (s1[cur_index] - '0') + (s2[cur_index] - '0') + carry;
	carry = sum/10;
	ret[cur_index] = ( sum%10 + '0');
}
string ComputeString(const string &s1, const string &s2)
{
	int n1 = s1.size(), n2 = s2.size();
	if(n1 == 0 || n2 == 0)
	{
		cerr << "Input paramter illegal!!!" << endl;
		exit(1);
	}

	bool label = false;
	//+ /-
	int i=0,j=0;
	if(s1[0] == '-' || s2[0] == '-')
	{
		if(s1[0] == '-') {label = !label; ++i;}
		if(s2[0] == '-') {label = !label; ++j;}
	}
	string s1_t = s1.substr(i);
	string s2_t = s2.substr(j);
	if(s1_t.size() < s2_t.size())
		swap(s1_t,s2_t);

	int k = 0;
	int index = 0;
	for( k = 0 ; k < s1_t.size(); ++k)
	{
		if (s1_t[k] == '.')
		{
			break;
		}
	}
	if ( k < s1_t.size() )
	{
		index += (s1_t.size()-k-1);
		s1_t.erase(s1_t.begin()+k);
	}
	for( k = 0 ; k < s2_t.size(); ++k)
	{
		if (s2_t[k] == '.')
		{
			break;
		}
	}
	if ( k < s2_t.size() )
	{
		index += (s2_t.size()-k-1);
		s2_t.erase(s2_t.begin()+k);
	}



	string ret;
	for(int k = s2_t.size()-1; k >=0 ; --k)
	{
		string temp = ComputeStrChar(s1_t,s2_t[k]);
		temp += string(s2_t.size()-1-k,'0');
		ret = addString(ret,temp);
	}
		
	if(index)
	{
		if(index < ret.size())
		{
			ret.insert(ret.begin() + (ret.size()-index),'.');
		}
		else
		{
			int size = index - ret.size() + 1;
			string insert_s = "0.";
			insert_s += string(size,'0') ;
			ret = insert_s + ret;
		}
	}
	if(label) ret = '-' + ret;
	return ret;
	
}
int main()
{
	string s1("-12.3");
	string s2("2.22");
	cout << s1 << " * " << s2 << " = " << ComputeString(s1, s2) << endl;

	return 0;
}

