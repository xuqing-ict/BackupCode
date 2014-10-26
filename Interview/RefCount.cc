/**
 * @file RefCount.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-12
 */

//shared_ptr class
#include <bits/stdc++.h>
using namespace std;

template<class T>
class smart_ptr 
{
private:
    T *data;
    int *ref_count;
    void destroy()
    { 
        if(--(*ref_count) == 0)
        {
            delete data;
            data = nullptr;
            delete ref_count;
            ref_count = nullptr;
        }
 
    }
public:
    //ctor
    smart_ptr(T *_data):data(_data),ref_count(new int(1)){}
    //dtor
    ~smart_ptr()
    {
        destroy();
    }
    smart_ptr(const smart_ptr &rhs):data(rhs.data),ref_count(rhs.ref_count)
    {
        (*ref_count) ++;
    }
    
    smart_ptr &operator=(const smart_ptr& rhs)
    {
        if(&rhs == this) return *this;
        destroy();
        data = rhs.data;
        ref_count = rhs.ref_count;
        ++(*ref_count);
        return *this;
    }

    T *getVal(){return data;}
    int getRef(){return *ref_count;}
};

int main(void)
{
    smart_ptr<int> sp(new int(10));
    smart_ptr<int> sp2 = sp;
    smart_ptr<int> sp3(new int(11));
    sp3 = sp2;
    cout << sp3.getRef() << endl;
    return 0;
}
