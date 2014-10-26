#include <bits/stdc++.h>
using namespace std;

int main()
{
	int number[] = {1,2,3,4};
	//定义时初始化
	vector<int> myVector(number, number+ sizeof(number)/sizeof(int));
		
	// assign去初始化另外一个vector,注意：assign(p1,p2) 返回的是p1与p2之间的元素（包括p1不包括p2）
	vector<int> myVector2;
	myVector2.assign(myVector.begin(),myVector.end()-2); 	
	
	//使用一个vector去初始化另一个vector
	vector<int > myVector3(myVector2);
	assert(myVector3.size() == myVector2.size());
	assert(myVector3.capacity() == myVector2.capacity()); //capacity要成立，是说容量一样大
	

	int A[] = {1,2,3,4,5,6,7};
	vector<int > ivec(A, A+ sizeof(A)/sizeof(int));
	for(vector<int>::iterator it = ivec.begin(); it != ivec.end();++it)
		cout << *it << " ";
	cout << endl;
	
	//find
	vector<int>::iterator elem1 = find(ivec.begin(), ivec.end(), 2);
	vector<int>::iterator elem2 = find(ivec.begin(), ivec.end(), 6);
	
	//delete the elements in [elem1. elem2)
	ivec.erase(elem1,elem2);

	for(vector<int>::iterator it = ivec.begin(); it != ivec.end();++it)
		cout << *it << " ";
	cout << endl;

	//向量直接赋值
	vector<int> ivec2;
	ivec2 = ivec;
	for(vector<int>::iterator it = ivec2.begin(); it != ivec2.end();++it)
		cout << *it << " ";
	cout << endl;


	ivec.erase(ivec.begin(),ivec.begin()+3);
	for(vector<int>::iterator it = ivec.begin(); it != ivec.end();++it)
		cout << *it << " ";
	cout << endl;
	cout << ivec.size() << endl;
	swap(ivec,ivec2);
	cout << "after swap..." << endl;

	for(vector<int>::iterator it = ivec2.begin(); it != ivec2.end();++it)
		cout << *it << " ";
	cout << endl;
	cout << ivec2.size() << endl;
	cout << "end..." << endl;
	for(vector<int>::iterator it = ivec.begin(); it != ivec.end();++it)
		cout << *it << " ";
	cout << endl;
	cout << ivec.size() << endl;
	cout << "end..." << endl;
	list<char *> clist;
	clist.push_back("abc");
	clist.push_back("def");
	vector<string > svec;
	svec.clear();
	svec.assign(clist.begin(),clist.end());
	for(vector<string>::iterator it = svec.begin(); it != svec.end();++it)
		cout << *it << " " << (*it).size() << " ";
	cout << endl;


	vector<int> ivec3;
	cout << ivec3.size() << " " << ivec3.capacity() << " " << ivec3.max_size() << endl;
	ivec3.push_back(1);
	cout << ivec3.size() << " " << ivec3.capacity() << " " << ivec3.max_size() << endl;
	ivec3.push_back(1);
	cout << ivec3.size() << " " << ivec3.capacity() << " " << ivec3.max_size() << endl;
	ivec3.push_back(1);
	cout << ivec3.size() << " " << ivec3.capacity() << " " << ivec3.max_size() << endl;
	ivec3.push_back(1);
	ivec3.push_back(1);
	ivec3.push_back(1);
	ivec3.push_back(1);
	ivec3.push_back(1);
	ivec3.push_back(1);
	cout << ivec3.size() << " " << ivec3.capacity() << endl;
	
	char no_null[] = {'A','T'};
	string ss(no_null,10);
	cout << "ss = " << ss << endl;

	string vecs = "-123";
	cout << atoi(vecs.c_str()) << endl;
	

	vector<int> a;
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	cout << a.size() << endl;
	a.clear();

	
	cout << a.size() << endl;


 	return 0;

}
