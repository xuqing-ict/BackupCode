#include<iostream>

using namespace std;

class INT
{
friend ostream &operator<<(ostream &, const INT&);

public:
	INT(int i ):m_i(i){}

	//++i
	INT &operator++()
	{
		++(this->m_i);
		return *this;
	}

	//i++
	const INT operator++(int)
	{
		INT temp = *this;
		++(this->m_i);
		return temp;
	}

	//--i
	INT &operator--()
	{
		--(this->m_i);
		return *(this);
	}

	//i--
	const INT operator--(int)
	{
		INT temp = this->m_i;
		--(this->m_i);
		return temp;
	}

	int &operator*() const
	{
		//convert const int to int &(int reference)
		return (int&)m_i;
	}

private:
	int m_i;

};
ostream &operator<<(ostream &os, const INT & i)
{
	os << i.m_i  << endl;
	return os;
}




int main()
{
	INT I(5);
	cout << I++;
	cout << ++I;
	cout << I--;
	cout << --I;
	cout << *I ;
	return 0;
}
