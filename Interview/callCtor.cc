/**
 * @file callCtor.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-26
 */

#include <bits/stdc++.h>
using namespace std;
/*
   class A
   {
   public:
   A(){cout << "A ctor.." << endl;}
   };

   int main()
   {
   A a[5], *b[6];
   return 0;
   }
   */
/*
   class Base { 
   int x;
   public: 
   Base(int b):x(b) {} 
   virtual void display() 
   { 
   cout<<x<<endl;
   } 
   }; 

   class Derived:public Base 
   { 
   int y; 
   public: 
   Derived(int d):Base(d),y(d) {}
   void display() 
   { cout<<y<<endl;} 
   };

   int main() 
   { Base b(2);
   Derived d(3); 
   b.display(); 
   d.display(); 
   Base *p=&d; 
   p->display(); 
   system("pause"); 
   return 0; 
   } 
   */
/*
struct xx {     
    long long _x1;
    char _x2;    
    int _x3;    
    char _x4[2];    
    static int _x5; 
}; 
int xx::_x5;
int main(void)
{
    cout << sizeof(void *) << endl;
    cout << sizeof(long long) << endl;
    cout << sizeof(xx) << endl;
    return 0;
}
*/
/*
int i=0;
int fun(int n)
{
    static int a = 2;
    a++;
    return a*n;
}
int main(void)
{
    int k = 5;
    {
        int i=2;
        k += fun(i);
    }
    k += fun(i);
    cout << k;
    return 0;
}
*/

class Base
{ 
public: 
    ~Base() 
    { 
        cout<<"BASE"; 
    } 
}; 

class DERIVED : public Base { 
public: 
    ~DERIVED() 
    { 
        cout<<"DERIVED";
    }
}; 
int main() 
{ 
    DERIVED x; 
    return 0; 
} 

