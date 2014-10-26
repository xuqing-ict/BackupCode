#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

int main()
{
	string line,word;
	ifstream infile("data");
	while(getline(infile,line))
	{
		cout << "line = " << line << endl;
		istringstream stream(line);
		while(stream >> word)
		{
			cout << "word = " << word << endl;
		}
	}
	return 0;
}
