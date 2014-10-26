#include<iostream>
using namespace std;

struct ptrStruct
{
	int *ptr;
};
int a = 100;
int b =200;

void changePtr(ptrStruct *struct1)
{
	struct1->ptr = &b;
}

int main()
{
	ptrStruct *struct1 = new ptrStruct;
	struct1->ptr =  &a;
	cout << "before change..." << *(struct1->ptr) << endl;
	changePtr(struct1);
	cout << "struct1->ptr = " << *(struct1->ptr) <<endl;
	return 0;
}
