#include <iostream>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <limits>
#include <map>

using namespace std;

 struct Point {
int x;
int y;
Point() : x(0), y(0) {}
Point(int a, int b) : x(a), y(b) {}
 };

int maxPoints(vector<Point> &points) {
        const int n = points.size();

        if( n == 0 ) return 0;
        if( n == 1 ) return 1;

        unordered_map<float, int> count;
        unordered_map<float, int>::iterator iter;

        map<pair<int,int>, int> same;

        for(int i = 0 ; i < n ; ++i)
        {
            pair<int,int> p1 = make_pair(points[i].x , points[i].y);
            if(same.find(p1) != same.end())
                ++same[p1];
            else
                same.insert(map<pair<int,int>, int>::value_type(p1, 1));
                //same[p1] = 1;
        }

        //only one point
        if( same.size() == 1 )return (same.begin())->second;
        int maxCount = 0;

        for(map<pair<int,int>, int>::iterator sameIter = same.begin(); sameIter != same.end(); sameIter++)
        {
            count.clear(); //record the points share a line with p1
            assert(count.empty());

            pair<int,int> p1 = sameIter->first;

            for(map<pair<int,int>, int>::iterator sameIter2 = same.begin(); sameIter2 != same.end() ; sameIter2++)
            {
                pair<int,int> p2 = sameIter2->first;
                if(p1 == p2) continue; //ignore itself
                float k = 0;
                if(p1.first == p2.first)
                {
                    k = numeric_limits<float>::max(); //the points with the same x axis,the slope is infinite
                }
                else
                {
                    k = 1.0*(float)(p1.second - p2.second)/(float)(p1.first - p2.first);
                }
                if(count.find(k) != count.end())
                    count[k] += (sameIter2->second);
                else
                    count.insert(unordered_map<float,int>::value_type(k,sameIter2->second));
            }

            int temp = 0;
            for( unordered_map<float, int>::iterator iter = count.begin(); iter != count.end(); ++iter)
            {
                if(iter->second > temp)
                    temp = iter->second;
            }
            if(maxCount < (temp + sameIter->second))maxCount = temp + sameIter->second;
        }

    return maxCount;
    }
    int main()
    {
        return 0;
    }
