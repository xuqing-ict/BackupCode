//类的静态成员变量的存取可以使用类名 或者是类的对象。也可以使用变态的this指针！！见下！！！
//问题是：为什么类的私有静态变量不能在外面初始化！！
//这就是静态成员函数干的事儿了，静态成员函数来set或者是get静态成员变量的值

#include <iostream>
#include <stdio.h>

using namespace std;

class Point
{
    private:
        int x;
        int y;
    public:
        static const int Member;// = -23;
        static int getMember() {return Member;}
        Point(int _x,int _y):x(_x),y(_y){}
};
const int Point::Member = -23;

int main()
{
    Point p(1,2);
    Point *pt = &p;
    cout << p.Member << "\t" << pt->Member << endl;
    cout << Point::Member << endl;
    cout << &Point::Member << endl;
    cout << ((Point *)0)->Member << endl;
    cout << ((Point *)0)->getMember() << endl;
    printf("add: %p\n",&(Point::getMember));
    return 0;
}
