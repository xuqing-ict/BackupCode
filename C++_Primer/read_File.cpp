#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ifstream in("XX");
	string seq1,seq2,seq3;
	vector<string> strs;
	while(!in.eof())
	{
		in >> seq1;
		if(in.eof())
		{
			break;
		}
		in >> seq2;
		in >> seq3;
		cout << seq1 << endl;
		cout << seq2 << endl;
		cout << seq3 << endl;
		++seq2;
		cout << "seq2++ = " << seq2 << endl;
	}
	cout << strs.size() << endl;
	return 0;
}
