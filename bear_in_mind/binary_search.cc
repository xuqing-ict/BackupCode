/**
 * @file binary_search.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-24
 */
//二分查找的各个版本
#include <bits/stdc++.h>
using namespace std;

unordered_set<int> answer(const vector<int> &A, const int target)
{
    unordered_set<int> pos;
    const int n  =A.size();
    for(int i=0;i<n;++i)
    {
        if(A[i]==target) {pos.insert(i);break;}
    }
    return pos;
}

//找到元素的位置并且返回即可
int binary_search(const vector<int> &A, const int target)
{
    const int n = A.size();
    int left=0,right=n-1;
    //[left,right]
    while(left <= right)
    {
        int mid = left + (right-left)/2;
        if(A[mid]==target) 
        {
            cout << target << "occur!!!" << endl;
            return mid;
        }
        else if(A[mid] > target)right=mid-1;
        else left=mid+1;
    }
    cout << target << "is not exist ..." << endl;
    return -1;
}
//返回地一个元素的位置，这个其实就是lower_bound的功能
int binary_search2(const vector<int> &A, const int target)
{
    const int n = A.size();
    int left=0,right=n-1;
    while(left <= right)
    {
        int mid = left+(right-left)/2;
        if(A[mid] > target) right=mid-1;
        else if(A[mid] < target) left=mid+1;
        else
        {
            //find its position
            int tmp = mid;
            right=mid-1;
            while(left <= right)
            {
                int mid = left + (right-left)/2;
                if(A[mid]==target){right=mid-1;tmp=mid;}
                else left=mid+1;
            }
            return tmp;
        }
    }
    return -1;
}
int main(void)
{
    int k=10;
    /*srand((unsigned)time(NULL));
    int n = rand()%100;
    vector<int> A;
    A.resize(n);
    for(int i=0;i<n;++i)
        A[i]=rand()%100;
    sort(A.begin(),A.end());
    */
    vector<int> A = {0,1,1,2,2,3,3,3,3,4};
    int target = 3;
    for(auto a: A) cout << a << "\t";
    cout << endl;
    //int target = rand()%100;
    int idx = binary_search2(A,target);
    unordered_set<int> pos = answer(A,target);
    cout <<target << "is at " <<  idx << endl;
    assert(idx == -1 || pos.find(idx)!=pos.end());
    return 0;
}
