/* 此问题一解决 */
//字符串翻转  I am a student. -- >   students. a am I
#include<iostream>
#include<string>
#include<cassert>

using namespace std;
/*
void reverseWord(char *start, char *end)
{
	assert(start && end);
	cout << "reverse..." <<  endl;
	char t;
	while( ( start + 1 ) !=  end && start != end)
	{
		cout << "swap " << *start << " " << *end << endl;
		//swap( start , end);
		t = *start;
		*start = *end;
		*end = t;

		cout << "swap after 1 " << *start << " " << *end << endl;

		start++;
		end--;
		cout << "swap after 2 " << *start << " " << *end << endl;
	}
	t = *start;
	*start = *end;
	*end = t;
	cout << "reverse end" << endl;
	cout << endl;
}

void reverseSentence(char * ptr)
{
	char *head = ptr;
	while( *head != 0 )
	{
		char *start = head;
		cout << "start = " << *start << endl;
		while(*head != 0 && *head != ' ')
		{
			head++;
		}
		char *end = head-1;
		cout << "end = " << *end << endl;
		reverseWord(start,end);
		if (*head == ' ')head++;
	}
	reverseWord(ptr, --head);
	return;
}
*/

void reverse(string &s, int beg, int end)
{
	cout << "reverse " << s.substr(beg, end-beg) << endl;
	if(end-beg <= 1) return;
	--end;
	while(beg <= end)
	{
		swap( s[beg], s[end]);
		++beg;--end;
	}
	cout << "reverse end : " << s  << endl;
}

void reverseSentence(string & s)
{
	int i = 0 ;
	int n = s.size();

	while(i < n)
	{
		while (i < n && s[i] == ' ')++i;
		if(i == n) break;
		int start = i;
		while(i < n && s[i] != ' ') ++i;
		reverse(s,start,i);
		++i;
	}
	reverse(s,0,n);
	i = 0;
	cout << "debug : " << s << endl;
	int j = 0;
	while(i < n)
	{
		while( i < n && s[i] == ' ' ) ++i;
		if(i <  n && j != 0 ) s[j++] = ' ';
		while (i < n && s[i] != ' '){s[j] = s[i];++i;++j;}
	}
	s.resize(j);
}

int main()
{
	char ptr[] = "   ";
	string s(ptr);
	cout << "s = " << s << endl;
	reverseSentence(s);
	cout << " s = " << s.size() << endl;
	cout << s << endl;
	return 0;
}
