#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> ComputeNext(string p)
{
	vector<int> next(p.length(),0);
	if(p.length() == 0 ) return next;
	next[0] = -1;//index从0开始
	int k = -1;
	for(int q = 1 ; q < p.length() ; ++q )
	{
		while(k >= 0 && p[k+1] != p[q])
			k = next[k];
		if( p[k+1] == p[q] ) k++;
		next[q] = k;
	}
	return next;
}

void KMP(string s, string p )
{
	cout << "KMP..." << endl;
	vector<int> next = ComputeNext(p);
	int lenS = s.length();
	int lenP = p.length();
	int q = -1; //已经match的字符的个数
	
	for(int i = 0 ; i < lenS ; ++i)
	{
		//-1 means no backward position
		while(q >= 0 && s[i] != p[q+1])
			q = next[q];
		if (p[q+1] == s[i])
			q++;
		if ( q == lenP-1 )
		{
			cout << p << " find in "<< s << " " << (i-lenP+1) << " pos!" << endl;
			q = next[q];
			//return;
		}
	}
	//cout << "do not find!!!" << endl;
	return;
}

int main()
{
	string p = "abababab";
	string s = "abacabababababcabababababca";
	vector<int> next = ComputeNext(p);
	for(vector<int>::size_type i = 0 ; i != next.size() ; ++i)
	{
		cout << i << " " << next[i] << endl;
	}
	KMP(s,p);
	return 0;
}
