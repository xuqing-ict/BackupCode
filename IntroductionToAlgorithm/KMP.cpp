#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> ComputeNext(const string &p)
{
  const int n = p.size();
  vector<int> next(n);
  next[0]=-1;
  int k=-1,j=0;
  while(j<n-1)
  {
      if(k == -1 || p[k]==p[j])
      {
          ++k;++j;
          next[j]=k;
      }
      else
          k=next[k];
  }
  return next;
}

vector<int> ComputeNext2(string p)
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
    for(int i=0;i<p.length();++i)
        cout << next[i] << "\t";
    cout << endl;
	return next;
}
/*
void KMP(string s, string p )
{
	cout << "KMP..." << endl;
	vector<int> next = ComputeNext(p);
	next = ComputeNext(p);
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
		}
	}
    return;
}

*/
void KMP(const string &s,const string &p)
{
    const int n=s.size(), m=p.size();
    int i=0,j=0;
    vector<int>next=ComputeNext(p);
    while(i<m && j<n)
    {
      if(j==-1 || s[i]==p[j])
      {
        ++i;++j;
      }
      else
      {
        j=next[j];
      }
    }
    if(j==m) cout << p << " occur in " << s << " " << i-j << "pos " << endl;
}

int main()
{
	string p = "abababab";
	string s = "abacabababababcabababababca";
	vector<int> next = ComputeNext(p);
    cout << next.size() << endl;
	for(vector<int>::size_type i = 0 ; i != next.size() ; ++i)
	{
		cout << i << " " << next[i] << endl;
	}
	KMP(s,p);
	return 0;
}
