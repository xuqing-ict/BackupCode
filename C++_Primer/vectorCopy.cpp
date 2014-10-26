#include <iostream>
#include <vector>
#include <iterator>
using namespace std;


int main()
{
/*	vector<int> *a;
	a = new vector<int>(4,1);
	a->recapacity(5);
	cout << (*a)[3] << endl;
//	a->push_back(1);
//	a->push_back(2);
//	a->push_back(3);
//	vector<int> *b = a;
//	b->at(2) =4;
	copy((*a).begin(), (*a).end(), ostream_iterator<int>(cout,"\t"));
//	copy(b->begin(), b->end(), ostream_iterator<int>(cout,"\t"));
*/
/*

	vector<int> a;
	cout << a.capacity() << endl;
	a.push_back(1);
	cout << a.capacity() << endl;
	a.push_back(1);
	cout << a.capacity() << endl;
	a.push_back(1);
	cout << a.capacity() << endl;
	a.push_back(1);
	cout << a.capacity() << endl;
	a.push_back(1);
	cout << a.capacity() << endl;
	a.push_back(1);
	cout << a.capacity() << endl;
	a.push_back(1);
	cout << a.capacity() << endl;
	a.push_back(1);
	cout << a.capacity() << endl;
	a.push_back(1);
	cout << a.capacity() << endl;
	a.pop_back();
	cout << a.capacity() << endl;
	a.pop_back();
	cout << a.capacity() << endl;
	a.pop_back();
	cout << a.capacity() << endl;
	a.pop_back();
	cout << a.capacity() << endl;
	a.pop_back();
	cout << a.capacity() << endl;
	a.pop_back();
	cout << a.capacity() << endl;
	a.pop_back();
	cout << a.capacity() << endl;
	a.pop_back();
	cout << a.capacity() << endl;
	a.pop_back();
	cout << a.capacity() << endl;
	a.pop_back();
	cout << a.capacity() << endl;
*/
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	cout << vec.size() << " " << vec.capacity() << endl;

	//vec.resize(7);
	//cout << vec.size() << " " << vec.capacity() << endl;

	vec.reserve(9);
	cout << vec.size() << " " << vec.capacity() << endl;

	vec.resize(7);
	cout << vec.size() << " " << vec.capacity() << endl;
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout,"\t"));
	return 0;
}

