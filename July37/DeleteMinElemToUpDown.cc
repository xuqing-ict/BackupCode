/**
 * @file DeleteMinElemToUpDown.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-23
 */
//删除一个数组中的最少的元素使得从左往右看元素是从小到大再从大到小的
//使用LCS来做

#include <bits/stdc++.h>
using namespace std;

//最长递增子数组，只需要记录每一个位置的local解就可以了！！
int deleteMinElem(const vector<int> &A)
{
    const int  n = A.size();
    vector<int> LPrev(n,-1);
    vector<int> RPrev(n,-1);
    vector<int> LCS(n,0);
    vector<int> RCS(n,0);
    //LCS
    for(int i=0;i<n;++i)
    {
        LCS[i]=1;
        for(int k=0;k<i;++k)
        {
            if(A[k]<A[i] && LCS[i] < LCS[k]+1)
            {
                LPrev[i]=k;
                LCS[i]=LCS[k]+1;
            }
        }
    }
    //RCS
    for(int i=n-1;i>=0;--i)
    {
        RCS[i]=1;
        for(int k=n-1;k>i;--k)
        {
            if(A[k] < A[i] && RCS[i] < RCS[k]+1)
            {
               RPrev[i]=k; 
               RCS[i]=RCS[k]+1;
            }
        }
    }
    int ret=0;
    int mid = -1;
    for(int i=0;i<n;++i)
    {
        int tmp=LCS[i]+RCS[i]-1;
        if(tmp > ret)
        {
            ret=tmp;
            mid = i;
        }
    }
   //print the remaid elements
    int idx=mid;
    cout << "Left : ";
    while(LPrev[idx] != -1)
    {
        cout << A[idx] << "\t";
        idx=LPrev[idx];
    }
    cout << A[idx] << endl;
    //print right part
    cout << "right: ";
    idx=mid;
    while(RPrev[idx] != -1)
    {
        cout << A[idx] << "\t";
        idx=RPrev[idx];
    }
    cout << A[idx] << endl;
    return ret;
}

//使用二分查找 + 边计算边保存的方法来记录最终剩下的元素 O(n*logn)
//inc内最后的元素就是要求的递增子数组
int deleteMinElem2(const vector<int> &A)
{
    const int n = A.size();
    vector<int> inc(n,INT_MAX);
    int low,high,mid;
    vector<int> LCS(n,0), RCS(n,0);
    for(int i=0;i<n;++i)
    {
        //此处的二分查找实现的就是lower_bound的功能，
        /*
        low=0;high=i; //[left high)
        while(low < high)
        {
            mid = low+ (high-low)/2;
            if(inc[mid] < A[i]) low=mid+1;
            else high=mid;
        }
        */
        low = lower_bound(inc.begin(),inc.end(),A[i])-inc.begin();
        //low指向的位置就是要插入A[i]的位置
        LCS[i]=low+1;
        inc[low]=A[i];
    }
    for(auto a : inc)
        cout << a << "\t";
    cout << endl;
    return 0;
}
int main(void)
{
    vector<int> A = {1,4,2,3,5};
    cout << deleteMinElem(A) << endl;
    cout << deleteMinElem2(A) << endl;
    return 0;
}

