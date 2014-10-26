/**
 * @file FinalClass.cc
 * @brief final class which is not be inherented
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-25
 */
#include <bits/stdc++.h>
using namespace std;
/*
class FinalClass
{
private:
    FinalClass(){}
    ~FinalClass(){}
public:
    static FinalClass *getInstance()
    {
        return new FinalClass();
    }
    static FinalClass *delInstance(FinalClass *rhs)
    {
        delete rhs;
        rhs=0;
    }

};
class Derived:public FinalClass
{
    
};
*/
template<class T>
class MakeFinal
{
    friend T;
private:
    MakeFinal(){}
    ~MakeFinal(){}
};
class FinalClass:virtual public MakeFinal<FinalClass>
{
public:
    FinalClass(){}
    ~FinalClass(){}
};

class Derived:public FinalClass
{
};

int main(void)
{
    FinalClass o1;
    Derived d;
    return 0;
}
