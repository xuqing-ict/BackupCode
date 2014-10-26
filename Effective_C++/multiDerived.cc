#include <iostream>
using namespace std;

class Top
{
private:
	int x;
public:
	Top(int _x):x(_x){}
	~Top(){}
	int getx() const {return x;}

};

class Left : public Top
{
private:
	int l;
public:
	Left(int _x,int _l):Top(_x),l(_l){}
	~Left(){}
	int getl() const {return l;}
	
};

class Right : public Top
{
private:
	int r;
public:
	Right(int _x, int _r):Top(_x),r(_r){}
	~Right(){}
	int getr() const {return r;}
};

class Bottom :  public Left, public Right
{
private:
	int b;
public:
	Bottom(int _x, int _l, int _r, int _b):Left(_x, _l),Right(_x, _r),b(_b){}
	~Bottom(){}
	int getb() const {return b;}
};

int main()
{
	Bottom b(0,-1,1,2);
	Left *left = &b;
	Right *right = &b;
	Top *topL = (Left *)&b;
	Top *topR = (Right *)&b;
	cout << left << " " << right << " " << topL << " " << topR  << " " << &b << endl;
	cout << (int)*((char *)left + (4)) << endl;
	cout << (int)*((char *)right + (4)) << endl;
	cout << (int)*((char *)left) << endl;
	cout << (int)*((char *)right) << endl;
/*
	cout << b.getb() << endl;
	cout << b.getl() << endl;
	cout << b.getr() << endl;
	cout << (Left *)b.getx() << endl;
	
*/
	return 0;
}
