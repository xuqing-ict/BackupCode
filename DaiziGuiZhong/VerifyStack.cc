//ȷ��ջ�������ķ���
#include <iostream>
using namespace std;

void func(void)
{
    int y;
    cout << "y addr : " << &y << endl;
}

int main(void)
{
    int x;
    func();
    cout << "x addr : " << &x << endl;
    return 0;
}
