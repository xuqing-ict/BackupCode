
//���ڲ��ĳ�Ա�����ĳ�ʼ��˳��
#include <bits/stdc++.h>
using namespace std;

class A
{
private:
    int n1;
    int n2;
public:
    A(int x=2):n1(x+1),n2(n1){}
    void print()
    {
        cout << n1 << " \t " << n2 << endl;
    }
};

enum Status {invalid, valid}; // ������ʾ�����Ƿ�Ϸ���ȫ�ֱ���
bool g_state = valid;

int strToInt(const char *s)
{
    g_state = invalid;

    if(s == nullptr) //���ڴ˴�������sΪ�յ������atoi��ͨ������һ��ȫ�ֱ�����ֵ����ʾ˵��ǰ�������ǲ��Ϸ��ġ�
    {
        exit(1);
    }
    long long number = 0 ; // Ϊ���ܹ����������������ʹ��long long��������
    bool label = false; // + / -
    int n = strlen(s);
    if(n == 0)  //���ַ����Ļ�����ô����ȫ�ֱ��������ҷ���0;
    {
        exit(1);
    }

    int i = 0;
    if(s[i] == '+')
    {
        label = false;
        ++i;
    }
    else if(s[i] == '-')
    {
        label = true;
        ++i;
    }
    if(i == n)  //ֻ��һ�����Ż����Ǹ��ţ������ֲ��֣�Ҳ�ǲ������
    {
        return 0;
    }
    for( ; i < n; ++i)
    {
        if(!isdigit(s[i]))
        {
            number = 0;
            break;
        }
        number = number * 10 + (label?(-1):1)*(s[i]-'0');
        //�ж��Ƿ����,�����������g_state, ���Ǹ������ֵ��������ֱ�ӷ���0
        if(number > INT_MAX || number < INT_MIN)
        {
            number = 0;
            break;
        }
    }

    if(i == n) g_state = valid;
    return number;
}

int main(void)
{
    A a(9);
    a.print();
    cout <<INT_MAX << "\t" << INT_MIN << endl;

    char str[100] = "2147483648";
    //cin >> str;
    int number = strToInt(str);
    if(g_state == invalid)
        cout << "illegel input..." << endl;
    else
        cout << number << endl;
    return 0;
}
