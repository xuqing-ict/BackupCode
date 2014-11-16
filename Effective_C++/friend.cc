#include <bits/stdc++.h>
using namespace std;

template <class T>
class Rational
{
private:
    T numerator;  //分子
    T denominator; //分母
public:
    Rational(T _numerator=0, T _denominator=1):numerator(_numerator),denominator(_denominator){}
    T get_numerator()const {return numerator;}
    T get_denominator()const {return denominator;}
    //此友元函数的声明与实现均在类的内部
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
