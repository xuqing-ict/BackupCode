/**
 * @file singleton.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-17
 */

#include <bits/stdc++.h>
#include "mutex_lock.h"

using namespace std;


class MutexLock {
public:
    explicit MutexLock(mutex *mu) 
        : mu_(mu)  {
            this->mu_->lock();
        }
    ~MutexLock() { 
        this->mu_->unlock(); 
    }

private:
    mutex *mu_;
    // No copying allowed
    MutexLock(const MutexLock&);
    void operator=(const MutexLock&);
};

class Singleton2
{
public:
    static Singleton2 *instance;
    static Singleton2 * getInstance()
    {
        if(instance == nullptr)
        {
            MutexLock lock(&m);
            if(instance == nullptr)
            {
                cout << "New instance..." << endl;
                instance =  new Singleton2();
            }
        }
    }

private:
    static mutex m;
    Singleton2(){}
    Singleton2(const Singleton2 &);
    struct Utility
    {
        ~Utility()
        {
            cout << "delete instance..." << endl;
            delete instance;
            instance = nullptr;
        }
    };
    static Utility u;
};

mutex Singleton2::m;
Singleton2* Singleton2::instance;
Singleton2::Utility Singleton2::u;

/*
   class Singleton {
   public:
   static Singleton* getInstance() {
   cout << "get instance " << endl;
   static Singleton instance;
   return &instance;
   }
   private:
   struct Utility {
   Utility() {
   cout << "entering utility's constructor" << endl;
   getInstance();
   }
   };
   static Utility u_data;

//no constuct directly
Singleton() {
}
Singleton(const Singleton &);
};

Singleton::Utility Singleton::u_data;
*/

int main(void)
{
    cout << "entering main" << endl;

    Singleton2 *p = Singleton2::getInstance();

    return 0;
}
