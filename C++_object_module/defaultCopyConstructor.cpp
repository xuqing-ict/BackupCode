//�������캯����ʲôʱ������ �����ʵ�ʱ�򡱣��Ż�ϳ���~~~

#include <iostream>
using namespace std;

class A
{
public:
    A(char *_str):str(_str),x(0){}
    //A(const A&a){cout << "call default copy constructor..." << endl;} //��������˵Ļ�����ô����������ϳɡ�
    //���û�ж���Ļ���������A��˵����������Ȼ����ϳɣ���Ϊ��ʱ�Ķ���֮��ĸ��ƺܼ򵥣�����һ��int��һ��char *�ĸ��ơ�
    //��ʱ��������Ѿ�ע�⵽�ˣ�����ຬ��ָ�룬Ӧ���Լ����帴�ƿ��ƺ��������Ⲣ�����ұ�ƪ������Ҫǿ���Ķ�����
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
