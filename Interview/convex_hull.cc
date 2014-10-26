/**
 * @file convex_hull.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-11
 */

#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x;
    int y;
    point(int _x=0,int _y=0):x(_x),y(_y){}
};
const point operator-(const point &lhs , const point &rhs)
{
    return point(lhs.x-rhs.x, rhs.y-lhs.y);
}

double Det(point p1, point p2)
{
    return  (p1.x*p2.y-p2.x*p1.y);
}
double Dot(point p1, point p2)
{
    return p1.x*p2.x + p1.y*p2.y;
}

//record the lowest point 
point p0;
bool cmp_y(const point &lhs, const point &rhs)
{
    return lhs.y < rhs.y;
}

bool cmp_angle(const point &lhs , const point &rhs)
{
    point v1(lhs.x-p0.x, lhs.y-p0.y), v2(rhs.x-p0.x,rhs.y-p0.y);
    if(Det(v1,v2) > 0 ) 
    {
        return true;
    }
    else if(Det(v1,v2) == 0 && v1.x < v2.x)
    {
        return true;
    }
    return false;
}

vector<point> convex_hull(vector<point> &vec)
{
    //find the lowest point
    sort(vec.begin(),vec.end(),cmp_y);
    cout << "sort y : "  << endl;
    for(auto a : vec)
        cout << a.x << "\t" << a.y << endl;

    const int n = vec.size();

    vector<point> ret;
    ret.resize(n);
    ret[0] = vec[0];

    //sort other point by the angle
    sort(vec.begin()+1,vec.end(), cmp_angle);
    //find the convex
    int top = 1; // the number of points in ret
    for(int i=1;i<n;++i)
    {
        while(top > 2 && Det(vec[i] - ret[top-1], ret[top-1]-ret[top-2]) < 0)
            --top;
        ret[top++] = vec[i];
    }
    ret.resize(top);
    return ret;
}

double dis(const point &lhs, const point &rhs)
{
    return sqrt((lhs.x-rhs.x)*(lhs.x-rhs.x) + (lhs.y-rhs.y)*(lhs.y-rhs.y) );
}
int main(void)
{
    int x,y;
    int n;
    cin >> n;
    vector<point> vec;
    for(int i=0;i<n;++i)
    {
        cin >> x >> y;
        vec.push_back(point(x,y));
    }
    vector<point > ret = convex_hull(vec);
    cout << "ret : " << endl;
    double res= 0;
    for(int i=0;i+1<ret.size();++i)
    {
        res += Dot(ret[i],ret[i+1]);
    }
    res += dis(ret[ret.size()-1], ret[0]);
    printf("%.0f\n", res);
    return 0;
}
