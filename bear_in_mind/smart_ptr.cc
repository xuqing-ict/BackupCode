/**
 * @file smart_ptr.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-26
 */
//智能指针的实现
#include <bits/stdc++.h>
using namespace std;

template <class T>
class Smart_Ptr
{
public:
    Smart_Ptr(T value):ptr(new T(value)), ref_count(new size_t(1)){cout << "ctor called..." << endl;}
    ~Smart_Ptr(){cout << "dtor called..." << endl;remove();}
    //copy control
    Smart_Ptr(const Smart_Ptr &rhs);
    Smart_Ptr & operator=(const Smart_Ptr &rhs);

    //member function
    T *get_ptr(){return ptr;}
    T get_ptr_val(){return *ptr;}
    
    T& operator*(){return *ptr;}
    const T &operator*() const{return *ptr;}
    T *operator->(){return ptr;}
private:
    T *ptr;
    size_t *ref_count;
protected:
    void remove()
    {
        if(--*ref_count == 0)
        {
            delete ptr;
            delete ref_count;
            ptr=nullptr;
            ref_count=nullptr;
        }
    }
};

template<class T>
Smart_Ptr<T>::Smart_Ptr(const Smart_Ptr &rhs)
:ref_count(rhs.ref_count),ptr(rhs.ptr)
{
    cout << "copy ctor called..." << endl;
    ++*ref_count;
}

template<class T>
Smart_Ptr<T> & Smart_Ptr<T>::operator=(const Smart_Ptr &rhs)
{
    cout << "operator= called..." << endl;
    ++*(rhs.ref_count);
    remove();
    ptr=rhs.ptr;
    ref_count = rhs.ref_count;
    return *this;
}
int main(void)
{
    Smart_Ptr<int> *sp =  new Smart_Ptr<int>(3);
    Smart_Ptr<int> sp2 = *sp;
    delete sp;
    return 0;
}
