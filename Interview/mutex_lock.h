// Last Update:2014-09-17 22:06:11
/**
 * @file mutex_lock.h
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-17
 */

#ifndef MUTEX_LOCK_H
#define MUTEX_LOCK_H_

#include <pthread.h>
#include <mutex>
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

#endif  /*MUTEX_LOCK_H*/
