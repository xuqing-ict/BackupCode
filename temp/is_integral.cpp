#include <iostream>
#include <type_traits>

using namespace std;

int main() {
	if ( is_integral<int>() )
		cout << "int is an integral type" << endl;

	// same result as:
	if ( is_integral<int>::value )
		cout << "int is an integral type" << endl;

	return 0;
}
