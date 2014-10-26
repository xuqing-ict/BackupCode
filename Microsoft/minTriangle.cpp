#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> point;

const double max_label = INT_MAX;
double centimeter(point ps[], int i, int j, int k )
{
	double ret = 0;
	double dx = ps[i].first - ps[j].first;
	double dy = ps[i].second - ps[j].second;
	ret += sqrt(dx*dx+dy*dy);
	dx = ps[i].first - ps[k].first;
	dy = ps[i].second - ps[k].second;
	ret += sqrt(dx*dx+dy*dy);
	dx = ps[j].first - ps[k].first;
	dy = ps[j].second - ps[k].second;
	ret += sqrt(dx*dx+dy*dy);
	return ret;
}

bool oneLine(point ps[], int i, int j , int k)
{
	return (ps[j].second - ps[i].second) * (ps[k].first - ps[i].first) == (ps[j].first - ps[i].first) * (ps[k].second - ps[i].second);
}

double enumerate(point ps[], int n)
{
	if(n < 3) return max_label;
	double res(max_label);
	for(int i=0; i<n; ++i)
	 for(int j=i+1; j<n; ++j)
	  for(int k=j+1; k<n; ++k)
	{
		if(oneLine(ps,i,j,k))
		  continue;
		res = min(res, centimeter(ps, i, j, k));
	}
	return res;
}

double minTriangle(point ps[], int n)
{
	if(n < 3)return max_label;
	double ret = max_label;
	sort(ps,ps+n);
	for(int i = 0 ; i < n-2 ; ++i)
	{
		for(int j = i+1; j < n-1 ; ++j)
		{
			if(ret <= 2*(ps[i].first - ps[j].first))
				break;
			double dx = ps[i].first - ps[j].first;
			double dy = ps[i].second - ps[j].second;
			double dis = sqrt(dx*dx+dy*dy);
			if(ret < dis*2)
			{
				continue;
			}
			for(int k = j + 1; k < n ; ++k)
			{
				if(ret <( ps[k].first - ps[j].first) * 2)
					break;
				if(oneLine(ps,i,j,k))
					continue;
				ret = min (ret , centimeter(ps,i,j,k));
			}
		}
	}
	return ret;
}

int main()
{
	const int n = 10;
	point ps[n];
	srand(time(NULL));
	ps[0] = (make_pair(rand()%100,rand()%100));
	ps[1] = (make_pair(rand()%100,rand()%100));
	ps[2] = (make_pair(rand()%100,rand()%100));
	ps[3] = (make_pair(rand()%100,rand()%100));
	ps[4] = (make_pair(rand()%100,rand()%100));
	ps[5] = (make_pair(rand()%100,rand()%100));
	ps[6] = (make_pair(rand()%100,rand()%100));
	ps[7] = (make_pair(rand()%100,rand()%100));
	ps[8] = (make_pair(rand()%100,rand()%100));
	ps[9] = (make_pair(rand()%100,rand()%100));

	cout << minTriangle(ps,n) << endl;
	cout << enumerate(ps,n) << endl;
	return 0;
}
