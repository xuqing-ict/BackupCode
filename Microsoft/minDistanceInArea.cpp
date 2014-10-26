#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> point;

const double max_label = INT_MAX;

bool compY(const point &lhs, const point &rhs)
{
	return lhs.second < rhs.second;
}
double minDistance(point *ps, const int n )
{
	if (n <= 1)
	{
		return max_label; 
	}
	int mid = n/2;
	double x = ps[mid].first;
	double min_d = min(minDistance(ps,mid), minDistance(ps+mid,n-mid));
	
	sort(ps, ps+n,compY);

	vector<point> ex;
	for(int i = 0 ; i < n ; ++i)
	{
		//grt
		if (min_d < (fabs(ps[i].first - x)))
		{
			continue;
		}
		//less, compare point in y-d area
		for(int j = ex.size()-1; j >= 0 ; --j)
		{
			if ((ps[i].second - ex[j].second) > min_d)
			{
				break;
			}
			double dx = ps[i].first - ex[j].first;
			double dy = ps[i].second - ex[j].second;
			double d = sqrt(dx*dx + dy*dy);
			if(d < min_d) min_d = d;
		}
		ex.push_back(ps[i]);
	}
	return min_d;
}
int main()
{

	const int n = 3;
	point ps[n];
	sort(ps, ps+n);
	cout << minDistance(ps, n) << endl;
	return 0;
}

