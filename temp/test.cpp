#include<iostream>
//#include<string>
using namespace std;

int add()
{
	int aaa;
	cout << "aaa in function " << aaa << endl;
}

string print(string *AA)
{
	*AA = "111";
	return *AA;
}
int main()
 
{
	int x;
	int *y = new(int);
	cout << "*y = " << *y << endl;
	cout << "x = " << x << endl;
	cout << "Hello,world---cout" << endl;
	clog << "Hello,world---clog" << endl;
	cerr << "Hello,world---cerr" << endl;

	cout << "line 1 "<<x
		<< "+ line 2 " <<x
		<< "is " << x+x
		<<endl;
	cout << "waiting for inputs..."<< endl;
	int value,sum = 0;
	while(cin >> value)
		sum += value;
	cout << "sum = " << sum << endl;
	unsigned short i = -2;
	cout << "i = " << i << endl;
	string A = "r";
	cout << A.size() << endl;
	int aa(23);
	cout << "aa=" << aa << endl;
	
	string A2(10,'s');
	cout <<"A2 =" << A2 << endl;
	int a=3,b=a+1;
	cout << "a = " << a << "\tb =" << b << endl; 
	int aaa;
	cout << "aaa = " << aaa<<endl;
	add();

	int *newPtr = new int[5];
	for(int i = 0;i < 5; ++i)
	{
		cout << *(newPtr+i)<< endl;
	}
	int *newPtr2 = new int[5]();
	for(int i = 0;i < 5; ++i)
	{
		cout << *(newPtr+i)<< endl;
	}

	delete [] newPtr;
	delete [] newPtr2;
	newPtr = 0;
	newPtr2 = 0;
	
	string AA = "abc";
	cout << print(&AA) << endl;
	cout << AA << endl;

	int *B;
	B = new int[10];
	cout << "TEST.. " << sizeof(B)/sizeof(int) << endl;

	int inta = 1234567;
	cout << float(inta) << endl;

	char ca = 255, cb = 255;
	char cc = ca+cb;
	int cd = ca + cb;
	cout << ca + cb << " " << cd << endl;
	cout << cc << endl;
	return 0;





}

