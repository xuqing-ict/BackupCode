
#include <bits/stdc++.h>
using namespace std;

typedef vector<int>::iterator it;
ostream_iterator<int> out(cout,"\t");

void perm(int *s,int *pStart,int n)
{
    if(n<=1)
    {
        while(s!=pStart)
        {
            cout << *s << "\t";
            ++s;
            if(s==pStart)
            {
                cout <<*s <<"\t";
                break;
            }
        }
        cout << endl;
        return;
    }
    for(int i=0;i<n;++i)
    {
        swap(*pStart,*(s+i));
        perm(s,pStart+1,n-1);
        swap(*pStart,*(s+i));
    }
}

//STL

int main(void)
{
    int s[] = {1,2,3,4};
    int n = sizeof(s)/sizeof(int);
    perm(s,s,n);
    vector<int> a = {1,2,3,5};
    it i1=a.begin(), i2=a.begin()+2;
    swap(*i1,*i2);
    copy(a.begin(),a.end(),out);
    cout<< endl;
    return 0;
}
