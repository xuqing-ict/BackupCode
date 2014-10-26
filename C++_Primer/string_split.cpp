#include <iostream>       // std::cout
#include <string>         // std::string
#include <cstddef>        // std::size_t

using namespace std;

string delim = "IDMS^\t\n ";

int main ()
{
	char map_type;
	std::string str ("1M 5I30M");
	std::size_t found = str.find_first_of(delim);
	std::size_t start = 0;
	vector<int> inserts(36,0);
	int map_pos = 0, read_pos = 0;
	int cur_type_base_count = 0;
	bool f_or_r = false;

	while (found!=std::string::npos)
	{
		//str[found]='*';
		cout << "found = " << found << endl;

		std::cout << atoi(str.substr(start, found - start)) << std::endl;
		cur_type_base_count = atoi(str.substr(start, found - start));
		map_type = str[found];
		cout << "map_type = "  << math_type<< endl;

		if (map_type == 'M')
		{
			map_pos += cur_type_base_count;
			read_pos += cur_type_base_count;
		}
		else if (map_type == 'I' || map_type == 'S')
		{
			
			if (f_or_r)
			{
				inserts[map_pos ] = cur_type_base_count;
			}
			else
			{
				inserts[36 - map_pos - 1] = cur_type_base_len;
			}



		}







		start = found + 1;
		found=str.find_first_of(delim,found+1);
	}
	return 0;
}
