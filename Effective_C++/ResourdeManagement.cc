/*#include <iostream>
#include <boost/shared_ptr.hpp>
#include <thread>
#include <assert.h>
#include <mutex>
#include <memory>
*/
#include <bits/stdc++.h>

using namespace std;
//using namespace boost;

class Management
{
private:
	int money;
public:
	Management(int _money = 0 ):money(_money){}
	~Management(){}
	void get_money(){cout <<  money << endl;}
};

Management *getManagement(int _val = 0)
{
	return new Management(_val);
}

// define own resource Management class
void unlock(mutex *MutexPtr)
{
	cout << "unlock ..." << endl;
	MutexPtr->unlock();
	cout << "unlock end ..." << endl;
}

class Lock
{
public:
	explicit Lock(mutex *pm):MutexPtr(pm,unlock) //shared_ptr的构造函数允许传入第二参数，表示在reference counting等于0的时候调用的函数
	{
		cout << "Lock construction..." << endl;
		(MutexPtr.get())->lock(); //the parameter of lock is a pointer of Mutex
		cout << "Lock contruction end..." << endl;
	}

private:
	shared_ptr<mutex> MutexPtr; //对底层资源进行引用计数
};



int main()
{
	Management *ptr = getManagement(10);
	ptr->get_money();
	delete ptr;
	

	cout << "auto ptr..." << endl;
	auto_ptr<Management> pMa(getManagement(20));
	pMa->get_money();
	auto_ptr<Management> pMa2 = pMa;
    //both are ok
	//assert(pMa.get() == nullptr);
	assert(!pMa.get());
	pMa2->get_money();
	
	cout << "shared ptr..." << endl;

	shared_ptr<Management> spMa(getManagement(20));
	spMa->get_money();
	(*spMa).get_money();

	shared_ptr<Management> spMa2 = spMa;
	spMa->get_money();
	spMa2->get_money();
    
    assert(spMa.get() == spMa2.get());
//shared_ptr point to the array is not a good choice. will leak memory
//For the default delete operation is delete ptr , not delete [] ptr!!!

//	boost::shared_ptr<int> p2Arr(new int[10]);
	mutex pt1;
	{
		Lock lock1(&pt1);
	}



    unique_ptr<Management> upMa(getManagement(100));
    //upMa implicity convert to the raw resources
    (upMa)->get_money();
    (upMa.get())->get_money();
    unique_ptr<Management> upMa2(std::move(upMa));
    assert(upMa == NULL);
	return 0;
}



