#pragma once

#include <iostream>
using namespace std;

class Singleton2 {
public:
	static Singleton2& getInstance() {
		return data_;
	}
	void print() {
		cout << "printing singleton2" << endl;
	}
private:
	Singleton2() {
		cout << "constructor2 called" << endl;
	}
	//declaration
	static Singleton2 data_;
};
//definition
Singleton2 Singleton2::data_;


