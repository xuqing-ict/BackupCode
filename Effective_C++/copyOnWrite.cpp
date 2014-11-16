#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "Hello";
    char *p = &s1[1];
    string s2 = s1;
    *p = 'a';
    cout << s1 <<"\t" << s2 << endl;
    return 0;
}
