// Last Update:2014-06-08 15:17:45
/**
 * @file main.cpp
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-06-08
 */
#include <bits/stdc++.h>
using namespace std;
class A
{
private:
  int value;
public:
  A(int a){value = a;}
  A(const A &other){value = other.value;}//不允许拷贝构造函数的参数不是const引用
  void print(){cout << "value : " << value << endl;}
};
class cMyString
{

friend ostream &operator<<(ostream &os, const cMyString &rhs);
private:
  char *m_pdata;
public:
  cMyString(char *pdata = NULL);
  cMyString(const cMyString &rhs);
  cMyString &operator=(const cMyString &rhs);
  ~cMyString(void){
    cout << "dtor..." << endl;
      delete [] m_pdata;
      m_pdata = NULL;
    cout << "dtor..." << endl;
  }
  bool empty() const {return strlen(m_pdata) == 0;}
};

cMyString::cMyString(const cMyString &rhs)
{
  m_pdata = new char[strlen(rhs.m_pdata)+1];
  strcpy(m_pdata,rhs.m_pdata);
}
cMyString::cMyString(char *pdata)
{
  cout << "construct..." << endl;
  if(pdata == NULL) 
  {
    m_pdata = new char[1];
    m_pdata[0] = '\0';
    return;
  }
  int len = strlen(pdata)+1;
  m_pdata = new char[len];
  strcpy(m_pdata,pdata);
}
/*
cMyString & cMyString::operator=(const cMyString &rhs)
{
  //self copy
  if(this == &rhs)
  {
    return *this;
  }
  delete [] m_pdata; //此处违背了异常安全性原则，如果下面的new失败，那么this的内存已经被释放掉了
  m_pdata = NULL;
  m_pdata = nendlew char[strlen(rhs.m_pdata) + 1];
  strcpy(m_pdata,rhs.m_pdata);
  return *this;
}

*/

//带有异常安全性机制的赋值操作符
cMyString & cMyString::operator=(const cMyString &rhs)
{
  //处理自我赋值，
  if(this == &rhs) return *this;
  cMyString temp_obj(rhs);//局部变量，在该函数执行完毕之后自动释放,
  char *temp = temp_obj.m_pdata;
  temp_obj.m_pdata = m_pdata;
  m_pdata = temp;
  return *this;
}

ostream &operator<<(ostream &os, const cMyString &rhs)
{
  cout << rhs.m_pdata ;
}


class Singleton
{
private:
  Singleton(){};
  static obj = new Singleton();
public:
  
};
int main()
{
  A a = 10;
  A b = a;
  b.print();
  char s[] = {'1','2','3','\0'};
  cout << s << endl;
  cMyString s1(s);
  cMyString s2 = s1;
  cout << "s1 : " << s1 << endl;
  cout << "s2 : " << s2 << endl;
  cMyString s3;
  cMyString s4 = s3;
  cout << "s3 : " << s3 << endl;
  cout << "s4 : " << s4 << endl;
  s4 =s4;
  s4 = s3 = s2;
  return 0;
}

