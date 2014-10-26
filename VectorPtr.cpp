#include<iostream>
#include<vector>
using namespace std;

struct st1
{
	int x;
	int y;
	st1(int xx, int yy):x(xx),y(yy){}
};

typedef st1 * pSt;
int main()
{
	vector<vector<st1 &> > V;
	pSt p1 = new st1(3,4);
	st1 p = *p1;
	vector<st1 &> V0;
	V0.push_back(p);
	V.push_back(V0);

	//delete V[0][0];
	/*
	for(vector<vector<pSt> >::size_type i = 0; i != V.size() ; ++i)
	{
		for(vector<pSt>::size_type j = 0; j != V[i].size() ; ++j)
		{
			delete &V[i][j];
			V[i][j] = NULL;
		}
		//delete it;
		//it = NULL;
	}*/
	return 0;
}
