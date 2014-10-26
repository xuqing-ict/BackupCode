#include <iostream>

using namespace std;

class Item_Base
{
private:
	string isbn;
protected:
	double price;
public:
	Item_Base(string _isbn = "", double _price = 0.0)
	{
		cout << "Item Base construction..." << endl;
		isbn = _isbn;
		price = _price;
	}
	virtual ~Item_Base(){};
	virtual double net_price(size_t n) const
	{
		cout << "Item_Base net_price() " << endl;
		return n*price;

	}
	string book() const
	{
		cout << "Item_Base book() call..." << endl;
		return isbn;
	}
	virtual Item_Base *ret_pointer() const
	{
		cout << "return Item_Base..." << endl;
		return NULL;
	}
};

class Bulk_Item:public Item_Base
{
private:
	size_t min_qty;
	double discount;

public:
	Bulk_Item():min_qty(0),discount(0)
	{
		cout << "Bulk_Item construction..."<< endl;
	}
	~Bulk_Item(){}

	string book() const
	{
		cout << "Bulk_Item book() call..." << endl;
		return isbn;
	}
	double net_price(size_t n) const
	{
		cout << "Bulk_Item net_price..." << endl;
		if ( n >= min_qty)
		{
			return n*price* (1 - discount);
		}
		else
		{
			return n*price;
		}
	}
	Bulk_Item *ret_pointer() const
	{
		cout << "return Bulk_Item ..." << endl;
		return NULL;
	}

};

double print_total(const Item_Base &ib, size_t n)
{
	cout << "Item base &print_total call..." << endl;
	ib.book();
	ib.net_price(0);
	return 0.0;
}

double print_total(const Bulk_Item &bi, size_t n)
{
	cout << "bulk_item & print total call " << endl;
	bi.net_price(0);
	return 0.0;
}

double print_total(const Item_Base *ib, size_t n)
{
	cout << "Item base * print_total call..." << endl;
	ib->book();
	ib->net_price(0);
	return 0.0;
}


double print_total(const Bulk_Item *bi, size_t n)
{
	cout << "bulk_item * print total call " << endl;
	bi->net_price(0);
	return 0.0;
}


int main()
{
	Item_Base item;
	print_total(item,0);
	Bulk_Item bulk;
	print_total(bulk,0);

	Item_Base * p = new Bulk_Item();
	print_total(p,0); //call the Item_Base * print_total()
	p->net_price(0);
	
	Item_Base * p2 = new Item_Base();
	print_total(p2,0); // call the Item_Base *print_total()
	p2->net_price(0);

	return 0;
}
