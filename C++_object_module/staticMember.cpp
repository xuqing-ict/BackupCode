//��ľ�̬��Ա�����Ĵ�ȡ����ʹ������ ��������Ķ���Ҳ����ʹ�ñ�̬��thisָ�룡�����£�����
//�����ǣ�Ϊʲô���˽�о�̬���������������ʼ������
//����Ǿ�̬��Ա�����ɵ��¶��ˣ���̬��Ա������set������get��̬��Ա������ֵ

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
