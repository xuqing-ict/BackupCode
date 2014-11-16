#include <bits/stdc++.h>
using namespace std;

bool check(const vector<int> &A, const int result)
{
    int times=0;
    const int n = A.size();
    for(int i=0;i<n; ++i)
    {
        if(A[i] == result)++times;
    }
    return (times>(n/2));
}

int maxTimesNumber(const vector<int> &A)
{
    const int n = A.size();
    if(n == 0)
    {
        cout << "A is empty..." << endl;
        return 0;
    }
    int result=0;
    int times=0;
    for(int i=0; i<n; ++i)
    {
        if(times==0){result=A[i];++times;}
        else if(A[i] == result){++times;}
        else if(A[i]!=result){--times;}
    }
    if(check(A,result))
    {
        return result;
    }
    else
        return -1;
}
int part(vector<int> &A, const int first, const int last)
{
    cout << first << "\t" <<last << endl;
    assert(first <= last);
    int idx = (rand()%(last-first+1))+first;
    //int idx=last;
    swap(A[idx],A[last]);
    int pivot=A[last];
    int i=first;
    for(int k=first; k <last; ++k)
    {
        if(A[k] <= pivot) swap(A[k],A[i++]);
    }
    swap(A[last],A[i]);
    return i;
}
//partition to find the middle number
//partition的方法求中位数
int findMedium(vector<int> &vec)
{
    const int n = vec.size();
    int mid = 7;
    int first=0,last=n-1;
    int index=part(vec,first,last);
    while(index != mid)
    {
        if(index > mid)
        {
            last=index-1;
            index=part(vec,first,last);
        }
        else
        {
            first=index+1;
            index=part(vec,first,last);
        }
    }
    cout << "medium : " << vec[mid] << endl;
    return vec[mid];
}
int main(void)
{
    vector<int> A = {2,8,4,0,3,1,5,9};
    cout << maxTimesNumber(A) << endl;
    cout << findMedium(A) << endl;
    for(int i=0;i<A.size();++i)
        cout << A[i] << "\t";
    cout<< endl;
    return 0;
}
