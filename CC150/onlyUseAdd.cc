/**
 * @file onlyUseAdd.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-11-15
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <exception>

using namespace std;

//implement the subtraction, multiplication, division with only add.

/*
 * implement subtraction
 */

//negative a
int negative(int a)
{
    int neg=0;
    int d=(a>0)?-1:1;
    while(a)
    {
        neg += d;
        a += d;
    }
    return neg;
}

int sub(int a, int b)
{
    int negb = negative(b);
    return a + negb;
}


//implement multiplication

int multiply(int a, int b)
{
    if( a < b ) return multiply(b,a); //multiplicand > multiplyer is much faster as the times of add operation called is less.
    int sum = 0;
    for(int i=abs(b);i>0;--i)
    {
        sum += a;
    }
    if(b < 0) sum = negative(sum);
    return sum;
}

//implement division
int divide(int a, int b)
{
    if(b == 0 ) throw runtime_error("divisor is zero...\n");
    int absa=abs(a),absb=abs(b);
    int sum=0;
    int ret=0;
    while(sum + absb <= absa)
    {
        ret += 1;
        sum += absb;
    }
    if((a < 0 && b < 0) || (a>0 && b>0))
        return ret;
    return negative(ret);
}

int main(void)
{
    srand(time(nullptr));
    int k = 1000;
    while(k--)
    {
        int a = rand()%1000000, b = rand()%1000000+1;
    assert( sub(a,b) == a-b );
    assert( multiply(a,b) == a*b) ;
    assert( divide(a,b) == a/b);
    }
   return 0 ;
}
