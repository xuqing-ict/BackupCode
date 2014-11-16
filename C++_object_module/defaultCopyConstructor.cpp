//拷贝构造函数，什么时候算是 “合适的时候”，才会合成呢~~~

#include <iostream>
using namespace std;

class A
{
public:
    A(char *_str):str(_str),x(0){}
    //A(const A&a){cout << "call default copy constructor..." << endl;} //如果定义了的话，那么编译器不会合成。
    //如果没有定义的话，对于类A来说，编译器依然不会合成，因为此时的对象之间的复制很简单，就是一个int与一个char *的复制。
    //此时，你可能已经注意到了，这个类含有指针，应该自己定义复制控制函数。但这并不是我本篇文章想要强调的东西。
    ~A(){}
    int getX() const {return x;}
    char *getStr() const {return str;}

private:
    int x;
    char *str;
};
int main()
{
    A a("123");
    A b = a;
    cout << b.getX() << " " << a.getX() << endl;
    cout << b.getStr() << " " << b.getStr() << endl;

    return 0;
}
