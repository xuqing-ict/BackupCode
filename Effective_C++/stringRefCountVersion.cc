/**
 * @file stringRefCountVersion.cc
 * @brief string reference counting version
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-31
 */

#include <bits/stdc++.h>
using namespace std;

class String
{
    friend ostream &operator<<(ostream &os, const String &rhs);
public:
    String(const char *rhs=0);
    String(const String &rhs);
    ~String();
    String &operator=(const String &rhs);
    char &operator[](int idx);
    const char &operator[](int idx) const;
private:
    struct StringValue
    {
        int refCount;
        char *data;
        StringValue(const char *rhs);
        ~StringValue();

    };
    StringValue *value;
};
ostream &operator<<(ostream &os, const String &rhs)
{
  cout << (rhs.value)->data;
}
String::StringValue::StringValue(const char *rhs)
{
  if(rhs == nullptr)  //必须考虑空指针的情况！！
  {
      data=new char[1];
      data[0]='\0';
      refCount=1;
      return;
  }
  data = new char[strlen(rhs)+1];
  strcpy(data,rhs);
  refCount = 1;
}
String::StringValue::~StringValue()
{
    delete [] data;
}
String::String(const char *rhs):value(new StringValue(rhs))
{}
String::~String()
{
  if(--(value->refCount) == 0)
      delete value;

}
String::String(const String &rhs):value(rhs.value)
{
    ++(value->refCount);
}
String &String::operator=(const String &rhs)
{
  if(this == &rhs) return *this;
  if(--(value->refCount)==0)delete value;
  value=rhs.value;
  ++(value->refCount);
  return *this;
}

const char &String::operator[] (int idx) const
{
  return value->data[idx];
}
char &String::operator[](int idx)  
{
    if(value->refCount > 1 ) //share with other objects
    {
        --value->refCount;
        value =  new StringValue(value->data);
    }
    return value->data[idx];
}

int main(void)
{
  String s1("1234");
  char *p = &s1[1];
  String s2 = s1;
  cout << s1 << "\t" << s2 << endl;
  *p = 'O';
  cout << s1 << "\t" << s2 << endl;
  return 0;
}
