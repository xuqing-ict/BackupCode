/**
 * @file statisticalArray.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-09-23
 */

/*给定数组A，大小为n，数组元素为1到n的数字，不过有的数字出现了多次
 * ，有的数字没有出现。请给出算法和程序，统计哪些数字没有出现，哪
 * 些数字出现了多少次。能够在O(n)的时间复杂度，O(1)的空间复杂度要求下完成么？*/
#include <bits/stdc++.h>
using namespace std;

vector<int> test(const vector<int> &A)
{
    const int n = A.size();
    vector<int> ret(n+1,0);
    for(auto a : A)ret[a]++;
    return ret;
}
void count(vector<int> &A)
{
    cout << "A : ";
    copy(A.begin(),A.end(), ostream_iterator<int>(cout,"\t"));
    cout << endl;
    vector<int> ret = test(A);

    const int  n = A.size();
    A.push_back(0);
    for(int i=0;i<n;++i)
        if(A[i] > n || A[i] <= 0)
            cout << "Illegal input..." << endl;

    for(int i=0;i<n;++i)A[i]*=n;
    for(int i=0;i<n;++i)A[A[i]/n]++;
    for(int i=0;i<n;++i)A[i] = A[i]%n;
    copy(A.begin(),A.end(), ostream_iterator<int>(cout,"\t"));
    cout << endl;

    copy(ret.begin(),ret.end(), ostream_iterator<int>(cout,"\t"));
    cout << endl;

    for(int i=0;i<=n;++i)
        if(ret[i] != A[i])
            cout << "error!!!" << endl;
}   

void count2(vector<int> &A)
{
    cout << "A : ";
    copy(A.begin(),A.end(), ostream_iterator<int>(cout,"\t"));
    cout << endl;

    vector<int> ret = test(A);
    const int n = A.size();
    ret[0] = ret[n];
    A.push_back(0);

    for(int i=0;i<n;++i)
        if(A[i] > n || A[i] <= 0)
            cout << "Illegal input..." << endl;
    for(int i=0;i<n;++i) //comput 0 -- n-1
        A[i]-=1;

    for(int i=0;i<n;++i)
        A[A[i]%n] += n;

    cout << "A = ";
    copy(A.begin(),A.end(), ostream_iterator<int>(cout,"\t"));
    cout << endl;

    for(int i=0;i<n;++i) A[i] = A[i]/n;
    int tmp = A[n];
    for(int i=n;i>0;--i)A[i] = A[i-1]; 
    A[0] = tmp;

    cout << "A = ";
    copy(A.begin(),A.end(), ostream_iterator<int>(cout,"\t"));
    cout << endl;

    cout << "ret = ";
    copy(ret.begin(),ret.end(), ostream_iterator<int>(cout,"\t"));
    cout << endl;

    for(int i=1;i<n;++i)
        if(ret[i] != A[i])
        {
            cout << "error!!!" << endl;
            exit(1);
        }
    if(ret[0] != A[n]) {cout << "error!!!" << endl; exit(1);}
}
int main(void)
{
    int k = 100;
    while(k--)
    {
        srand(time(nullptr));

        const int n = rand()%1000;
        vector<int> A(n,0);
        for(int i=0;i<n;++i)
            A[i] = (rand()%n)+1;
        //vector<int> A = {4,5,6,4,4,3};
        //    count(A);
        count2(A);
    }
    return 0;
}
