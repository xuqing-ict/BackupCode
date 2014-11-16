#include <iostream>
#include <cstdio>

using namespace std;

class Point3d
{
public:
    Point3d(){
        cout << "constructor called" << endl;
    }
    virtual ~Point3d(){
    cout << "destructor called" << endl;
    cout << "a: " << Point3d::a << endl;}
public:

    float x,y,z;
private:
    static int a;
    static Point3d origin;
};
Point3d Point3d::origin;
int Point3d::a = 10;

int main()
{
    cout << "main func entered..." << endl;
   // cout << sizeof(Point3d) << endl;
   // printf("&Point3d::x : %p\n" ,&Point3d::x);
   // printf("&Point3d::y : %p\n" ,&Point3d::y);
   // printf("&Point3d::z : %p\n" ,&Point3d::z);


    //printf("&origin::x : %p\n" ,&(Point3d::origin.x));
    //printf("&origin::y : %p\n" ,&Point3d::origin.y);
    //printf("&origin::z : %p\n" ,&Point3d::origin.z);
    //cout << Point3d::a << endl;
}
