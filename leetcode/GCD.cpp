#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

int GCD(int m , int n)
{
	int max_ = m, min_ = n;
	if(max_ < min_) swap(max_,min_);
	int ret = min_;
	if(ret == 0 ) return ret;

	while(max_ = max_%min_)
	{
		ret = max_;
		if(max_ < min_)swap(max_,min_);
	}
	return ret;
}
//0 < a <= m,  m < b <= n
void Print_result(const int m , const int n, vector<string > & reducible, vector<string> &irreducible)
{
	//ostringstream ss;
	char buffer[8*sizeof(int)+1];
	string temp;
	if (m >= n) return ;
	for(int i = 1; i <= m ; ++i)
	{
		for(int j = m +1 ; j <= n ; ++j)
		{
			assert(i < j);
			if(GCD(i,j) != 1)
			{
				/*
				ss << i << "/" << j ;
				reducible.push_back(ss.str());
				ss.str("");
				ss.clear();
				*/
				//itoa(i,buffer, 10);
				sprintf(buffer, "%d",i);
				temp = string(buffer);
				temp += '/';
				//itoa(i,buffer,10);
				sprintf(buffer, "%d",j);
				temp += string(buffer);
				reducible.push_back(temp);

			}
			else
			{
				/*
				ss << i << "/" << j ;
				irreducible.push_back(ss.str());
				ss.str("");
				ss.clear();
				*/
				//itoa(i,buffer, 10);
	
				sprintf(buffer,"%d",i);
				temp = string(buffer);
				temp += '/';
				//itoa(i,buffer,10);
				sprintf(buffer,"%d",j);
				temp += string(buffer);
				irreducible.push_back(temp);
			}
		}

	}
}
int main()
{
	vector<string> reducible,irreducible;
	int m = 5, n = 10;
	Print_result(m,n,reducible, irreducible);
	cout << reducible.size() << endl;
	cout << irreducible.size() << endl;
	for(int i = 0 ; i < reducible.size(); ++i)
		cout << reducible[i] << endl;
	cout << endl;
	for(int i = 0 ; i < irreducible.size(); ++i)
		cout << irreducible[i] << endl;
	cout << endl;

	ostringstream ss;
	ss << m << n << "*" << 34;
	cout << ss.str() << endl;
	ss.str("");
	ss.clear();
	cout << ss.str() << endl;
	return 0;
}
