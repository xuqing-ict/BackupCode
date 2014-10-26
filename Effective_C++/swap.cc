
//针对特定的用户自定义类型定义自己的swap函数
#include <bits/stdc++.h>

using namespace std;

//namespace StudentSpace
//{

template<class T>
class StudentImpl
{
private:
    T name;
    int age;
public:
    StudentImpl(T _name = "", int _age = 0):name(_name),age(_age){}
    void print()
    {
        cout << "name : " << name << " age : " << age << endl;
    }
};

template<class T>
class Student
{
private:
    shared_ptr< StudentImpl<string> >  pStu;
    T label;
public:
    Student(string _name = "", int _age = 0,T _label = T()):label(_label)
    {
        pStu = make_shared< StudentImpl<string> >(_name, _age);
          //pStu =  new StudentImpl<string>(_name, _age);
    }
    Student(StudentImpl<string> *_pStu, T _label):pStu(_pStu),label(_label){}

    Student(const Student &rhs);
    Student & operator=(const Student &rhs);

    ~Student()
    {
        //delete pStu;
    }

    void swap(Student &b)
    {
        using std::swap; //使的STL库中的swap函数依然可用。
        //也就是说，在编译器看到swap函数的时候，决定是调用为Student特化的版本呢，还是在某个命名空间中定义的版本呢，
        //此处为StudentSpace命名空间，如果都没有，最后是否会调用STL库中的swap函数版本（就是这个using的功劳了），毕竟如果用户定义了自己的swap函数，肯定是要尽可能地
        //使用自己的高效的版本。

        swap(pStu, b.pStu);
        swap(label, b.label);
    }
    void print()
    {
        pStu->print();
        cout << " label : " << label << endl;
    }
};

//Student实现
template<class T>
Student<T> & Student<T>::operator=(const Student<T> &rhs)
{
    pStu = rhs.pStu;
    label = rhs.label;
    return *(this);
}

//Student<T> 是类型。定义该类型的Student函数。
template<class T>
Student<T>::Student(const Student<T> &rhs):pStu(rhs.pStu)
{}

//如果我要交换两个Student对象， 那么其实只需要交换其内部成员pStu指针即可。
//在STL库中定义的swap函数版本并不知道这一点，
/*
template<class T>
void swap(T &a, T &b)
{
    T temp(a);
    a = b;
    b = temp;
}
//显然只要类型T支持拷贝构造函数和复制操作符，那么上述swap就会实现预期的功能。
//但是对于Student类来说，将预示着3次复制构造函数的调用，显然我们可以为该类定义更高效的swap操作。
*/
//
/*
void swap(Student &a, Student &b)
{
    using std::swap;
    swap(a.pStu, b.pStu);
}
//此函数不能通过编译，因为pStu是类的private变量，因此，我们可以定义一个成员函数swap来执行真正的操作，再类外调用该成员函数完成该函数。
*/

//此函数调用成员函数swap完成。

template<class T>
void swap(Student<T> &a, Student<T> &b)
{
    a.swap(b); //通过对象a调用swap完成操作
}
//}

int main(void)
{
    //StudentImpl a("AAA",1);
    //StudentImpl b("BBB",2);

    Student<char> pA("AAA",1,'F');
    Student<char> pB("BBB",2,'M');

    cout << "swap before : " << endl;
    pA.print();
    pB.print();

    pB = pA;

    swap(pA,pB); // 如果此处的swap是STL库中原本的swap函数，那么这将会导致“指针悬垂”的问题，因为Student类中含有指针，那么它将
    //具有指针所有的缺点。。具体请参见：超链接，智能指针类的实现。
    cout << "swap after : " << endl;
    pA.print();
    pB.print();

    return 0;
}

