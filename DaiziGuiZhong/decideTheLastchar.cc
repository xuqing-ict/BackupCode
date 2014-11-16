//decide if the last char is one-byte character or two-byte character.
//constraint: you can scan the array only from end to beginning.
#include <iostream>
#include <vector>
using namespace std;

typedef unsigned char uchar;

void decide(vector<uchar> &A)
{
    const int n = A.size();
    if( n < 2)
    {
        cout << "One-byte character..." << endl;
        return;
    }
    int cnt = 0; //count the continuous bytes started with 1 from the 2-nd byte from the end.
    for(int j=n-2;j>=0;--j)
    {
        if(A[j] & 0x80) cnt += 1;
        else break;
    }
    //cout << "cnt : " << cnt << endl;
    if(cnt && cnt % 2)
        cout << "two-byte character..." << endl;
    else
        cout << "one-byte character..." << endl;
}


int main(void)
{
   // vector<uchar> A = {129,64,129,128,129,137,129,128,23};
     vector<uchar> A = {137,129,128};
    decide(A);

    return 0;
}
