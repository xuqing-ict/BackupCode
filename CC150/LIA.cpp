#include <bits/stdc++.h>
using namespace std;

int LIS2(const vector<int> &s);

//最长递增子数组
vector<int> LIA(const vector<int> &s)
{
	if(s.empty()) return s;
	vector<int> f(s.size(),0);
	f[0]=1;
	for(int i= 1 ; i < s.size(); ++i)
	{
		if(s[i] > s[i-1]) f[i]  = f[i-1] + 1;
		else f[i] = 1;
	}
	int max_len = *max_element(f.begin(),f.end());

	for(int i = 0 ; i < s.size(); ++i)
	{
		if(f[i] == max_len)
		{
			//vector<int> ret = s.substr((i-max_len+1),max_len);
            vector<int> ret;
            ret.assign(s.begin()+(i-max_len+1),s.begin()+(i+2));
			return ret;
		}
	}

}


//Longest increasing subsequence
/*
string LIS(const string &s)
{
	if(s.empty()) return s;
	vector<int> f(s.size(),0);
	f[0]=1;
	for(int i= 1 ; i < s.size(); ++i)
	{
		for(int j = 0 ; j < i; ++j)
		{
			if(s[i] > s[j])
				f[i] = max(f[i], f[j] + 1);
		}
	}
	int max_len = 0;
	int max_index=-1;
	for(int i = 0 ; i < s.size(); ++i)
	{
		if(f[i] > max_len)
		{
			max_len = f[i];
			max_index = i;
		}
	}
	int j = max_index-1;
	string ret;
	ret += s[max_index];
	while(j >= 0)
	{
		if( f[max_index] == 1 || f[j]+1 == f[max_index] )
		{
			ret = s[j] + ret;
			if(max_index == 1) break;
			max_index=j;
		}
		--j;
	}
	return ret;
}
*/
vector<int> LIS(const vector<int> &s)
{
    const int n = s.size();
    vector<int> f(n,0);//初始值应该是1！！！！
    f[0]=1;
    for(int i=1;i<n;++i)
    {
        f[i]=1;
        for(int k=0;k<i;++k)
            if(s[k] < s[i])
                f[i]=max(f[i],f[k]+1);
        assert(f[i]);
    }

    for(auto a: f)cout << a << "\t";cout << endl;
    int ret=*max_element(f.begin(),f.end());
    cout << ret << "\t" << LIS2(s) << endl;

    //assert(ret==LIS2(s));
    //backtrack
    int k=ret;
    vector<int> res;
    for(int i=n-1;i>=0;--i)
    {
        if(f[i]==ret)
        {
            res.push_back(s[i]);
            --ret;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

const int MAX = 1000;
int LIS2(const vector<int> &s)
{
    const int n = s.size();
    vector<int> f(n,MAX);
    for(int i=0; i<n;++i)
    {
        //*upper_bound(f.begin(),f.end(),s[i]) = s[i]; //不是严格递增子序列
        *lower_bound(f.begin(),f.end(),s[i]) = s[i]; //是严格递增子序列

    }
    return lower_bound(f.begin(),f.end(),MAX)-f.begin();
}
int main()
{
    /*
    for(int k=0;k<100;++k)
    {
    srand(time(NULL));
    vector<int> A;
    const int n = rand()%100;
    A.resize(n);
    for(int i=0;i<n;++i)A[i]=rand()%100;
	vector<int> ret = LIS(A);
    for(auto a: ret) cout << a << "\t"; cout << endl;
    cout << LIS2(A) << endl;
    assert(ret.size() == LIS2(A));
    sleep(2);
    }
    */
    vector<int> A = {1,3,4,7,6};
	vector<int> ret = LIS(A);
    for(auto a: ret) cout << a << "\t"; cout << endl;
    cout << LIS2(A) << endl;
	return 0;
}
