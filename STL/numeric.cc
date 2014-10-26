/**
 * @file algorithm.cc
 * @brief accumulate
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-03
 */

//binary operation 
/*#include <iostream>
#include <numeric>
#include <vector>
#include <iterator>
*/
#include <bits/stdc++.h>
using namespace std;

int square(int x, int y){return x*y;}
int myaccumulate(int x, int y){return x+y;}
int myminus(int x, int y){return x-y;}
class myclass
{
public:
   int  operator()(const int x, const int y){return x + y;}
};

int main()
{
    //accumulate
    vector<int> number = {1,2,3,4};
    //default add operation
    cout << accumulate(number.begin(), number.end(), 0) << endl;
    //minus operation
    cout << accumulate(number.begin(), number.end(), 100, minus<int>()) << endl;
    //multiple operation  100 * 1 *2 *3 *4
    cout << accumulate(number.begin(), number.end(), 100, multiplies<int>()) << endl;
    //functor
    cout << accumulate(number.begin(), number.end(), 100, myclass()) << endl;
    //function pointer
    cout << accumulate(number.begin(), number.end(), 100, square) << endl;

  
    //inner_product
    //if the size of a and b is not equal, the result is not defined
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {1,1,1,1,1};
    cout << inner_product(begin(a),end(a),begin(b),0) << endl;
    //0 - 1+1 - 2+1 - 3+1 - 4+1 - 5+1 = -20
    //myminus : define the operation between the corresponding element of a and b
    //myaccumulate: define the operation between init and the result of the followed operation
    cout << inner_product(a.begin(), a.end(), b.begin(), 0,myminus,myaccumulate) << endl;

    //patiral sum
    //部分和
    ostream_iterator<int> out(cout, "\t");
    vector<int> c(a.size());
    partial_sum(a.begin(), a.end(),c.begin());
    copy(c.begin(), c.end(), out); cout << endl;
    copy(a.begin(), a.end(), out); cout << endl;

    //adjacent_difference
    adjacent_difference(a.begin(),a.end(),out); cout << endl;
    adjacent_difference(a.begin(),a.end(),out, plus<int>()); cout << endl;

    //power 
    cout << pow(10,2) << endl;
    //cout << pow(10,2,plus<int>()) << endl;
    return 0;
}
