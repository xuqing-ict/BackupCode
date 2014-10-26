#include <iostream>

using namespace std;
/*
//traditional class wich has pointer
class myClass
{
private:
	int val;
	int *ptr;
public:

	myClass(int *_ptr, int _val):val(_val),ptr(_ptr){}
	~myClass(){}

	void set_val(int _val){val = _val;}
	void set_ptr(int *_ptr){ptr = _ptr;}

	int get_val() const {return val;}
	int *get_ptr() const {return ptr;}

	int get_ptr_val() const {return *ptr;}
	void set_ptr_val(int x) const {*ptr = x;}
};

int main()
{
	int x = 20;
	myClass hp1(&x, 40);
	myClass hp2(hp1);

	cout << hp1.get_val() << endl;
	cout << hp1.get_ptr_val() << endl;
	cout << hp2.get_val() << endl;
	cout << hp2.get_ptr_val() << endl;

	hp1.set_ptr_val(55);
	cout << hp1.get_ptr_val() << endl;
	cout << hp2.get_ptr_val() << endl;
	return 0;
}
*/

//ref_counting class
/*
class U_ptr
{
	friend class hasPtr;
	int *ip;
	size_t use;
	U_ptr(int *p):ip(p),use(1){}
	~U_ptr() { if(--use == 0 ) delete ip;}
public:
	size_t get_use() const { return use;}
};

class hasPtr
{
private:
	U_ptr *ptr;
	int val;
public:
	hasPtr(int *_ptr, int _val):ptr(new U_ptr(_ptr)), val(_val){}
	hasPtr(const hasPtr &lhs);
	~hasPtr(){if (--ptr->use == 0 ) delete ptr;}

	hasPtr &operator=( const hasPtr & rhs);

	U_ptr *get_ptr() const {return ptr;}
	int get_ptr_val() const{return *(ptr->ip);}
	int get_val() const { return val;}
	
	void set_ptr_val (int x) const {*(ptr->ip) = x;}
	void set_val(int x) {val = x;}
};

hasPtr::hasPtr(const hasPtr &lhs)
{
	ptr = lhs.ptr;
	val = lhs.val;
	++ptr->use;
}

hasPtr & hasPtr::operator=(const hasPtr &rhs)
{
	if (--(ptr->use) == 0)
	{
		delete ptr;
	}
	++rhs.ptr->use;
	ptr = rhs.ptr;
	val = rhs.val;
	return *this;
}
 
int main()
{
	int x = 1;
	hasPtr* hp1 = new hasPtr(&x, 100);
	hasPtr hp2(*hp1);
	cout << hp1->get_val() << endl;
	cout << hp1->get_ptr_val() << endl;
	cout << hp2.get_val() << endl;
	cout << hp2.get_ptr_val() << endl;

	hp1->set_ptr_val(55);
	cout << hp1->get_ptr_val() << endl;
	cout << hp2.get_ptr_val() << endl;
	cout << hp1->get_ptr()->get_use() << " " << (hp2.get_ptr())->get_use() << endl;
	delete hp1;
	cout << hp2.get_ptr_val() << endl;
	cout << " " << (hp2.get_ptr())->get_use() << endl;
	return 0;

}
*/

class hasPtr
{
private:
	int *ptr;
	int val;
public:
	
	hasPtr(const int &p, int _val):ptr(new int(p)), val(_val){}
	hasPtr(const hasPtr &rhs):ptr(new int(*rhs.ptr)),val(rhs.val){}
	~hasPtr(){delete ptr;}

	hasPtr &operator=(const hasPtr rhs)
	{
		ptr = rhs.ptr;
		val = rhs.val;
		return *this;
	}
	
	void set_val(int _val){val = _val;}
	void set_ptr(int *_ptr){ptr = _ptr;}

	int get_val() const {return val;}
	int *get_ptr() const {return ptr;}

	int get_ptr_val() const {return *ptr;}
	void set_ptr_val(int x) const {*ptr = x;}
};

int main()
{
	int x = 1;
	hasPtr hp1(x, 20);
	hasPtr hp2 = hp1;
	cout << hp1.get_val() << endl;
	cout << hp2.get_ptr_val() << endl;
	cout << hp2.get_val() << endl;
	cout << hp2.get_ptr_val() << endl;
	hasPtr hp3(hp1);
	hp3.set_ptr_val(30);
	cout << hp1.get_val() << endl;
	cout << hp1.get_ptr_val() << endl;
	cout << hp3.get_val() << endl;
	cout << hp3.get_ptr_val() << endl;

}


