/**
 * @file refCountBase.cc
 * @brief reference counting base class definition 更通用的reference_counting
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-06
 */
#include <bits/stdc++.h>
using namespace std;

//smart pointer
template<class T>
class RCPtr
{
public:
    RCPtr(T *realPtr=0);
    RCPtr(const RCPtr &rhs);
    ~RCPtr();

    RCPtr & operator=(const RCPtr &rhs);
    T *operator->() const;
    T &operator*() const;
private:
    T *pointee;
    void init();
};

//reference_counting base class
class RCObject
{
private:
    int refCount;
    bool shareable;
public:
    //each object is defult shareable true
    RCObject():refCount(0),shareable(true){}
    RCObject(const RCObject &rhs):refCount(0),shareable(true){}
    RCObject &operator=(const RCObject &)
    {
        return *this;
    }
    virtual ~RCObject() = 0; //pure virtual destructor
    void addReference()
    {
      ++refCount;
    }
    void removeReference()
    {
      if(--refCount == 0) delete this;
    }
    bool isShareable() const
    {
        return shareable;
    }
    bool isShared() const
    {
        return refCount > 1;
    }
};

RCObject::~RCObject(){}

class String
{
    friend ostream &operator<<(ostream &os, const String &rhs);
private:
    struct StringValue:public RCObject
    {
        char *data;
        StringValue(const char *initValue);
        ~StringValue();
    };
    StringValue * value;
public:    
    String(const char *initValue="");
    String(const String &rhs);
    String &operator=(const String &rhs);
    const char &operator[](int index) const;
    char &operator[] (int index) ;
    ~String();
};
char &String::operator[](int index)
{
    //if ref count ==1 no need to new!!
    //there exist other objects share the data, so we should new a object
    if(value->isShared())
    {
      value->removeReference();
      value = new StringValue(value->data);
    }
    value->addReference();
    return value->data[index];
}
const char &String::operator[](int index) const
{
    return value->data[index];
}
ostream &operator<<(ostream &os, const String &rhs)
{
    os << (rhs.value)->data;
}
String::StringValue::StringValue(const char *initValue)
{
  data = new char[strlen(initValue)+1];
  strcpy(data,initValue);
}
String::StringValue::~StringValue()
{
    if(StringValue)
    delete [] data;
}
String::String(const char *initValue):value(new StringValue(initValue))
{
    value->addReference();
    cout << "String ctor called..." << endl;
}
//copy ctor is called at a time of object construction
String::String(const String &rhs):value(rhs.value)
{
  if(rhs.value->isShareable())
  {
      value = rhs.value;
      value->addReference();
  }
  else
  {
    value = new StringValue((rhs.value)->data);
    value->addReference();
  }
}

String &String::operator=(const String &rhs)
{
    if(this == &rhs) return *this; //self-copy
    if(!(value->isShared()))
        delete value;
    if((rhs.value)->isShareable())
    {
      value = rhs.value;
      value->addReference();
    }
    else
    {
      value = new StringValue(rhs.value->data);
    }
    return *this;
}
String::~String()
{
  cout << "String dtor called..." << endl;
  if(!(value->isShared()))
      delete value;
}
int main()
{
    String s1("Hello");
    String s2 = s1;
    String s3(s1);
    cout << s1 << "\t" << s2 << "\t" << s3 << endl;
    cout << s1[2] << endl;
    s1[2] = '!';
    cout << s1 << "\t" << s2 << "\t" << s3 << endl;

    return 0;
}
