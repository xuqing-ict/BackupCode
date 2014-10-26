#include <iostream>
#include <string>
#include <vector>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

const int MAX_LINE = 100;

string get_diff_bases_bt_read_ref(const char* ref, const char* read)
{
    char diff_bases_list[MAX_LINE];
    vector<int> mis;
    for (unsigned int i = 0; read[i] != '\0'; i++) {
        if (read[i] != ref[i]) {
            mis.push_back(i+1);
        }
    }
    int j = 0;
    for (vector<int>::iterator it = mis.begin(); it != mis.end(); it++) {
        sprintf(&(diff_bases_list[j]), "%d_%c,", *it, ref[*it]);
        j += ((*it < 10) ? 3 : 4); // assume read length < 100
        if ( *it >= 100) j++;      // assume read length < 1000
    }
    return(string(diff_bases_list));
}



int main()
{
	const char ref[] = "GACGTGTTGCTGTGGCGACCGTCATCACTTCCGGTC";
	const char read[] = "GACGTGTTGCTGTGGCGACCGTCATCACTTCCGGCC";
	cout << get_diff_bases_bt_read_ref(ref,read) << endl;
}




