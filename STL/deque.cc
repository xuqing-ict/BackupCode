//deque in STL
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	deque<int,std::allocator<int> >  q(20,9);
	cout << "size : " << q.size() << endl;

	for(int i=0; i<q.size(); ++i)
		q[i]=i;
	auto it = find(q.begin(),q.end(),4);
	cout << *it << endl;
	cout << *(it._M_cur) << endl;
	cout << *(it._M_first) << endl;
	cout << *(it._M_last) << endl;

    cout << "Test stack ... " << endl;
  
 //   stack<int,list<int> > s;
    stack<int,deque<int> > s;
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
	return 0;
}
