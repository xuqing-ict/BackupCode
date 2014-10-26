/**
 * @file singleton2.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-17
 */

#include <bits/stdc++.h>
using namespace std;

//用来管理mutex的lock与unlock，防止程序员忘记释放锁
class mutexLock
{
public:
    explicit mutexLock(mutex *_mu):mu(_mu)
    {
        this->mu->lock();
    }
    ~mutexLock()
    {
        this->mu->unlock();
    }
private:
    mutex *mu;
    mutexLock(const mutexLock &);
    mutexLock &operator=(const mutexLock &);
};

//Singleton的主体
class Singleton
{
public:
    static Singleton *instance;
    static Singleton * getInstance()
    {
        if(instance == nullptr)
        {
            mutexLock lock(&mu);
            if(instance == nullptr)
            {
                instance =  new Singleton();
            }
        }
    }
private:
    static mutex mu; //锁用于线程同步
    //ctor and copy ctor are private
    Singleton(){}
    Singleton(const Singleton &rhs);
    //此结构用于释放该Singleton的唯一的对象的指针
    struct Utility
    {
        ~Utility()
        {
            delete instance;
            instance = nullptr;
        }
    };
    static Utility u;
};

mutex Singleton::mu;
Singleton * Singleton::instance;
Singleton::Utility Singleton::u;

int main(void)
{
    Singleton *p =Singleton::getInstance() ;
    return 0;
}

