#include <bits/stdc++.h>
using namespace std;

template <class T>
class Rational
{
private:
    T numerator;  //����
    T denominator; //��ĸ
public:
    Rational(T _numerator=0, T _denominator=1):numerator(_numerator),denominator(_denominator){}
    T get_numerator()const {return numerator;}
    T get_denominator()const {return denominator;}
    //����Ԫ������������ʵ�־�������ڲ�
    friend const Rational operator*(const Rational &lhs, const Rational &rhs)
    {
        return Rational(lhs.get_numerator() * rhs.get_numerator(), lhs.get_denominator() * rhs.get_denominator());
    }
};

int main()
{
    Rational<int> oneHalf(1,2);
    Rational<int> ret = oneHalf * 2;
    cout << ret.get_numerator() << "\t" << ret.get_denominator() << endl;
    return 0;
}
