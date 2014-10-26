#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

template<class T, class Sequence = vector<T>, 
	class Compare = less<typename Sequence::value_type> > 
	//采用类模板的形式，定义数组的元素类型以及底层实现的容器类型（此处为vector）
	//以及用于比较的函数对象 less
	
class my_priority_queue
{
private:
	Sequence c;    //用于存放元素的vector
	Compare comp;  //用于比较的函数对象
	
public: 
	//类模板内部定义的类型
	typedef typename Sequence::value_type value_type;
	typedef typename Sequence::size_type size_type;
	typedef typename Sequence::reference  reference;
	typedef typename Sequence::const_reference  const_reference;


	my_priority_queue():c(){}

	//如果没有指定比较函数，那么使用less
	template<class InputIterator>
	my_priority_queue(InputIterator beg, InputIterator end, const Compare &x = Compare()):
		c(beg, end),comp(x)
	{
		make_heap(c.begin(),c.end(), comp);
	}

	bool empty() const
	{
		return c.empty();
	}

	size_type size() const
	{
		return c.size();
	}

	const_reference top() const
	{
		return c.front();
	}

	void pop()
	{
		if(empty())
		{
			cout << "pop empty" << endl;
			exit(1);
		}
		pop_heap(c.begin(), c.end(), comp);
		c.pop_back();
	}

	void push(const value_type &x)
	{
		c.push_back(x);
		push_heap(c.begin(), c.end(), comp);
	}
};


int main()
{
	my_priority_queue<int> mpq;
	int A[] = {4,2,3,1};
	my_priority_queue<int , vector<int> > mpq2(A, A+4);
	mpq2.push(5);

	cout << "mpq2.size() = " << mpq2.size() << endl;

	while(!mpq2.empty())
	{
		cout << mpq2.top() << " ";
		mpq2.pop();
	}
	if (mpq2.empty())
	{ 
		cout << "mpq2 is empty..." << endl;
	}
	//使用greater比较函数
	my_priority_queue<int,vector<int>, greater<int> > mpq3(A, A+4, greater<int>());
	mpq3.push(5);

	cout << "mpq3.size() = " << mpq3.size() << endl;

	while(!mpq3.empty())
	{
		cout << mpq3.top() << " ";
		mpq3.pop();
	}
	if(mpq3.empty())
	{
		cout << "Empty.." << endl;
	}
	return 0;
}
