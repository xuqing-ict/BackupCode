//未完成
#include<iostream>
using namespace std;

void inverse_sentence(string *sentence)
{
	string s = *sentence;
	cout << s << endl;
	
	string::size_type it = 0;
	string::size_type jt = s.size();
	cout << "it = " << it << endl;
	cout << "jt = " << jt << endl;

	while(it < jt)
	{
		swap();
		++it;
		--jt;
	}
}



int main()
{
	string sentence = "I am a girl!";
	inverse_sentence(&sentence);
	cout << sentence << endl;
	//inverse_word(&sentence)
	return 0;

}
