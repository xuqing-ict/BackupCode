#include<iostream>
#include<algorithm>

//Implement the permutation and output results
template<class T>
void permutation(T *start, T* end)
{

}


using namespace std;
int main()
{
	char myChars[] = "abcabs";
	do
	{
		cout << myChars[0] << ' ' << myChars[1] << ' ' << myChars[2] << ' '
			<< myChars[3] << ' ' << myChars[4] << ' ' << myChars[5] << endl;
	}while ( next_permutation(myChars,myChars+6) );
	return 0;
}
