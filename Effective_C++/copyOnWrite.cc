/**
 * @file copyOnWrite.cc
 * @brief string class and copy on write
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-06
 */

#include <bits/stdc++.h>

using namespace std;

class String
{
    friend ostream &operator<<(ostream &os, const String &rhs);
private:
    struct StringValue
    {
        int refCount;
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
    if(value->refCount > 1)
    {
      --value->refCount;
      value = new StringValue(value->data);
    }
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
String::StringValue::StringValue(const char *initValue):refCount(1)
{
  data =  new char[strlen(initValue)+1];
  strcpy(data,initValue);
}
String::StringValue::~StringValue()
{
    delete [] data;
}
String::String(const char *initValue):value(new StringValue(initValue))
{
}
//copy ctor is called at a time of object construction
String::String(const String &rhs):value(rhs.value)
{
    ++(value->refCount);
}

String &String::operator=(const String &rhs)
{
    if(this == &rhs) return *this; //self-copy
    if(--(value->refCount) == 0)
        delete value;
    value = rhs.value;
    ++(value->refCount);
    return *this;
}
String::~String()
{
  if(--value->refCount == 0)
      delete value;
}
int main()
{
    String s1 = "Hello";
    String s2 = s1;
    String s3(s1);
    cout << s1 << "\t" << s2 << "\t" << s3 << endl;
    cout << s1[2] << endl;
    s1[2] = '!';
    cout << s1 << "\t" << s2 << "\t" << s3 << endl;

    return 0;
}
