//#include <bits/stdc++.h>

#include <iostream>
#include <stdlib.h>

using namespace std;

class ADD
{
private:
    static int sum;
    static int N;
public:
    ADD() // ctor
    {
        cout << "ADD ctor..." << endl;
        ++N; sum += N;
    }
    static void init(){sum = 0 ; N = 0;}
    static int getSum(){return sum;}
};
int ADD::sum = 0;
int ADD::N = 0;

//call ctor
int add1ToN(const int n)
{
    ADD::init();
    ADD *tmp = new ADD[n];
    cout << ADD::getSum() << endl;
    delete [] tmp;
    tmp = NULL;
}

//&& 短路求值
int add1ToN2(const int N)
{
    static int sum = 0;
    (N) && (sum += N) && (add1ToN2(N-1));
    return sum;
}

//利用两个函数来分别实现递归处理以及递归终止
class A;
A *obj[2];
class A
{
public:
    virtual int ADD(int n) // 用于递归终止
    {
        return 0;
    }
};

class B : public A
{
public:
    virtual int ADD(int n)
    {
        return n + obj[!!n]->ADD(n-1); //if n==0, call A::ADD() , else call B::ADD()
    }
};
//add 1 to N
int add1ToN3(const int N)
{
    A a;
    B b;
    obj[0] = &a;
    obj[1] = &b;
    return obj[1]->ADD(N);
}

// function pointer
typedef int (*add_ptr)(int);

int terminator(const int n)
{
    return 0;
}

int add1ToN4(const int n)
{
    static add_ptr f[2] = {terminator,add1ToN4};
    return n + (f[!!n])(n-1);
}


//不用加减乘除实现a+b
int add(int a, int b)
{
    int sum,carry;
    do
    {
        sum = a ^ b;
        carry = (a & b)<<1;

        a = sum; //在计算进位与原先不考虑进位的结果sum的时候是需要迭代进行的，
        //因为此时同样是要将两个数相加，但是不能使用加减乘除。
        b = carry;
    }while(b != 0);
    return sum;
}

int main(void)
{
    srand(time(NULL));
    int n;
    cin >> n;
    add1ToN(n);
    cout << add1ToN2(n) << endl;
    cout << add1ToN3(n) << endl;
    cout << add1ToN4(n) << endl;
    int a = rand()%10000, b =  rand() % 10000;
    cout << add(a,b) << endl;
    assert(add(a,b) == a+b);
    return 0;
}
