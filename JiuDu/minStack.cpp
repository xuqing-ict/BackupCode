#include <bits/stdc++.h>
using namespace std;

template<class T>
class minStack
{
public:
    minStack(){}
    void push(const T &);
    void pop();
    T min_e() const;
    T top() const;
private:
    stack<T> s;
    stack<T> min_s;
};
template<class T>6
void minStack<T>::push(const T & val)
{
    s.push(val);
    if(min_s.empty() || val < min_s.top())
    {
        min_s.push(val);
    }

}
template<class T>
void minStack<T>::pop()
{
    assert(!s.empty() && !min_s.empty());
    if(min_s.top() == s.top())
    {
        min_s.pop();
    }
    s.pop();
}
template<class T>
T minStack<T>::min_e() const
{
    assert(!s.empty() && !min_s.empty());
    return min_s.top();
}
template<class T>
T minStack<T>::top() const
{
    assert(!s.empty());
    return s.top();
}

int main()
{
    minStack<int> ms;
    ms.push(1);
    ms.push(2);
    cout << ms.top() << endl;
    cout << ms.min_e() << endl;
    ms.pop();
    cout << ms.min_e() << endl;
    return 0;
}
