#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream in("./TT");
	string word1, word2,word3;
	int index = 0 ;
	while(!in.eof())
	{
		in >> word1 ; 
		in >> word2;
		in >> word3;
		if(in.eof())
		{
			break;
		}
		cout << index << " " << word1 << endl;
		cout << index << " " << word2 << endl;
		cout << index << " " << word3 << endl;
	}
}
