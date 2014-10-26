/**
 * @file defaultCtor.cc
 * @brief class without default ctor would meet some constraints
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-30
 */

//没有定义构造函数的类不能定义该类的对象数组,内置类型除外

//operator new + ctor
//dtor + operator delete 

//operator new[] + ctor
//dtor + operator delete []

#include <bits/stdc++.h>
using namespace std;

class A
{
private:
    int x;
public:
    A(int _x):x(_x){}
    ~A() {}
};
//没有定义构造函数的类在定义数组的时候，会出现问题！！

int main()
{
    //A vecs[10];   //compile failed
    //Method 1: placement new
    void *raw = operator  new[] (3*sizeof(A));
    A *pa = static_cast<A *>(raw);
    for(int i = 0 ; i< 3;++i)
        new (&pa[i])A(i);     //placement new

    //destructor + deallocate
    for(int i = 3-1;  i>=0; --i)
        pa[i].~A(); //只是在每个位置处调用了析构函数，但是没有释放内存
    operator delete[](pa); //释放内存
    //delete [] pa;   //如果类A没有定义构造函数，那么此句正确，但是一旦定义了构造函数就内存错误了，只能通过operator delete来删除operator new分配的空间,见上一句

    
    //但是下面的方法与是否定义构造函数没有关系!!
    void *raw2 = operator new(sizeof(int));
    int *p = static_cast<int *>(raw2);
    new (p)int(3);
    cout << *p << endl;
    delete p;     //内置类型没有析构函数，直接delete即可

    
    void *raw3 = operator new [] (sizeof(int)*3);
    int *pInts = static_cast<int *>(raw3);
    for(int i = 0 ; i < 3;++i)
      new (&(pInts[i]))int(i);  //placement new

    for(int i = 0 ; i < 3;++i)
      cout << pInts[i] << endl;

    operator delete []( pInts);

    return 0;
}
