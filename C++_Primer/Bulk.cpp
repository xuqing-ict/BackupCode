#include <iostream>

using namespace std;

class Item_base
{
private:
	string isbn;
protected:
	double net_price;
public:
	Item_base(string _isbn="", double _net_price=0):isbn(_isbn),net_price(_net_price){}

	string book() const {return isbn;}
	virtual double net_price(size_t n) const
	{
		return n*net_price;
	}
	virtual ~Item_base(){}
}

class Bulk_Item
{
public:
	Bulk_Item()
}


int main(void)
{

	return 0;
}
