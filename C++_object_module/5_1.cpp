#include <iostream>
#include <memory>

using namespace std;

class Point
{
private:
    int x,y,z;
public:
    Point(int _x=0,int _y=0,int _z=0):x(_x),y(_y),z(_z){}
};
int main()
{
   Point p = {1,1,1};

    return 0;
}
