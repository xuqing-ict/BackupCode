/**
 * @file perfectShuffle.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-11-06
 */

#include <bits/stdc++.h>
using namespace std;

void shuffle(char *A, const int R, const int C)
{
    if(A == nullptr || R <= 0 || C <= 0 ) return ;
    if(R == 1 || C == 1 ) return;
    const int size = R*C-1;
    vector<bool> B(size+1,false);
    B[0] = B[size] = true ; //the first and last 
    for(int i=1;i<size;++i)
    {
        if(B[i]) continue;
        int beg = i ;
        char tmp = A[beg];
        int next = i;
        do
        {
            next = (i*R)%size;
            swap(A[next],tmp);
            B[i] = true;
            i = next;
        }while(next != beg);
    }
    return;
}
int main(void)
{
    char a[] = {'1','2','3','4','a','b','c','d'};
    const int n = sizeof(a)/sizeof(char);
    for(int i=0;i<n;++i)
        cout << a[i] << " ";
    cout << endl;
    shuffle(a,2,4);
    for(int i=0;i<n;++i)
        cout << a[i] << " ";
    cout << endl;
}
