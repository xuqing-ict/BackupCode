#include <bits/stdc++.h>
using namespace std;

struct point
{
    double x;
    double y;
    point(double _x, double _y):x(_x),y(_y){}
};

double dis(const point & p1, const point &p2)
{
    double ret = sqrt(((p1.x-p2.x)*(p1.x-p2.x))+((p1.y-p2.y)*(p1.y-p2.y)));
    cout << ret << endl;
    return ret;
}

double minDis(const vector<point> & ps)
{
    if(ps.empty()) return 0.0;
    const int n = ps.size();
    double f[n][n];
    fill_n(&f[0][0],n*n,0);
    //init
    const int N = n-1; //N points
    for(int i = 2; i <= N; ++i)
        f[i][1] = dis(ps[1],ps[i]);

    //upper line
    for(int i = 3; i <= N; ++i)
    {
        for(int j = 1; j<= i-2; ++j)
        {
            f[i][j] = f[i-1][j] + dis(ps[i-1],ps[i]);
        }
        f[i][i-1] = INT_MAX;
        for(int k=1;k<=i-2;++k)
            f[i][i-1] = min(f[i][i-1],f[k][i-1] + dis(ps[k],ps[i]));
    }
    f[N][N] = f[N-1][N]+dis(ps[N-1],ps[N]);
    return f[N][N];
}

int main()
{
    int N;
    vector<point> ps;
    double x, y;
    while(cin >> N)
    {
        ps.clear();
        ps.push_back(point(-1,-1));
        for(int i=0;i< N;++i)
        {
            cin >> x ;
            cin >> y;
            ps.push_back(point(x,y));
        }
        cout << "ret : " << minDis(ps) << endl;
    }
    return 0;
}
