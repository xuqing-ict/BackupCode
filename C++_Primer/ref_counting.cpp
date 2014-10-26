#include<iostream>
using namespace std;

class U_ptr{

private:
    friend class hasPtr;
    int *ip;
    int count;  //count the number of object sharing this ptr
    U_ptr(int *p):ip(p),count(1){}
    ~U_ptr(){if(count == 0) delete ip;}
};

class hasPtr{

private:
    int val;
    U_ptr *ptr;

public:
    hasPtr(int *p, int i);
    ~hasPtr();
    hasPtr &operator=(const hasPtr &rhs);
    hasPtr(const hasPtr &rhs);
    int *get_ptr() const;
    int  get_val()const;
};

hasPtr::hasPtr(int *p, int i):ptr(new U_ptr(p)),val(i)
{}

hasPtr::~hasPtr()
{
    if(ptr->count == 0)
    {
        delete ptr;//the destruction of U_ptr invoked
    }
}

hasPtr &hasPtr::operator=(const hasPtr &rhs)
{
    (rhs.ptr->count)++;
    if(--ptr->count==0)
    {
        delete ptr;
    }
    ptr = rhs.ptr;
    val = rhs.val;
    return *(this);
}

hasPtr::hasPtr(const hasPtr &rhs):ptr(rhs.ptr),val(rhs.val)
{
    ptr->count++;
}
int *hasPtr::get_ptr()const
{
    return ptr->ip;
}

int hasPtr::get_val() const
{
    return val;
}

int main()
{
    int iVal= 7;
    hasPtr obj1(&iVal, 12);
    hasPtr obj2(obj1);
    cout << obj1.get_ptr()<< "\t"<< obj1.get_val()<< endl;  
    cout << obj2.get_ptr()<< "\t"<< obj2.get_val()<< endl;  
    hasPtr *obj3 = new hasPtr(&iVal,13);
    cout << obj3->get_ptr()<< "\t"<< obj3->get_val()<< endl;  
    delete obj3;
    cout << obj1.get_ptr()<< "\t"<< obj1.get_val()<< endl;  
    cout << obj2.get_ptr()<< "\t"<< obj2.get_val()<< endl;  
}




