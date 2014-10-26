#pragma once

#include "singleton2.h"
#include <iostream>
using namespace std;
class Singleton {
public:
	static Singleton& getInstance() {
		return data_;
	}
	void print() {
		cout << "printing singleton1" << endl;
	}
private:
	Singleton() {
		cout << "constructor called" << endl;
		Singleton2::getInstance().print();
	}
	//declaration
	static Singleton data_;
};
//definition
Singleton Singleton::data_;


