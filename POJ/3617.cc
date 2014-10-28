/**
 * @file minStr.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-27
 */

//Given a string s with length n, we are to construct a string T with length N by tracating a char from head or tail of s each time.
//output the minimal string.
#include <iostream>
#include <string>
using namespace std;

char cow[2001]; 
char ret[2001];

int n;

#define For(i,n) for(int i=0;i<(n);++i)

void minStr()
{
    if(n < 2)
    {
        For(i,n) ret[i]=cow[i];
        return;
    }
    bool left=false; //get left char
    int l=0,r=n-1;
    int k=0;//record ret idx
    while(l<=r)
    {
        left=false;
        for(int i=0;l+i<=r;++i)
        {
            if(cow[l+i] < cow[r-i]) {left=true;break;}
            else if (cow[l+i] > cow[r-i]) {left=false;break;}
        }
        //if equal, choose one randomly
        if(left) ret[k++] = cow[l++];
        else ret[k++] = cow[r--];
    }
    return;
} 
int main(void)
{
    fill_n(cow,2001,0);
    fill_n(ret,2001,0);

    while(scanf("%d",&n) != EOF) 
    {
        For(i,n)
        {
            //scanf("%c",cow+i);
            cin >> cow[i];
        }
        minStr();
        for(int i=0;i<n;++i)
        {
            if(i > 0 && i%80 == 0)
            {
                cout << endl;
            }
            cout << ret[i];
        }
        cout << endl;
    }
    return 0;
}
