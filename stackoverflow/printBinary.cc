#include <iomanip>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main()
{
    int num; //the number a user enters
    int rem; //the remainder, the 1 and 0 of the binary number
    int x;   //a variable to store the number after division

    //char binary[10]; //c-string initialized to 10, perhaps that is too many.
    unsigned char binary[10];
    cout << "Enter a number: ";
    cin >> num;

    for (int i = 0; i < 10; i++)
    {
        x = num / 2;
        cout << "cur = " << x << " "; //this shows that the code is working
        rem = num % 2;
        cout << "num = " << num << " "; //this also shows the code is working

       // char r = (char)rem;   //These two lines of code are
       // strcpy((binary+i), &r); //preventing compilation
        binary[i] = rem + '0';
        cout << "bit = " << binary[i] << endl; // this is diagnostic
        num = x;
    }
}
