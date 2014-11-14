/**
 * @file shuzubogu.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-11-14
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

using namespace std;

/*
//for answer
int minValue2(const vector<int> &A)
{
const int n = A.size();
int idx = minValue(A);
if(idx == -1) return -1;
if(A[idx] < A[idx-1] && A[idx] < A[idx+1]) return idx;
return -1;
}

*/
int minValue(const vector<int> &A)
{
    const int n = A.size();
    if(n < 2 || A[0] <= A[1] || A[n-1] <= A[n-2]) 
    {
        return -1;
    }
    int left=0,right=n-1;
    while(left<=right)
    {
        int mid = left+(right-left)/2;
        if(left == mid) return A[left] < A[right] ? left : right;
        if(A[mid-1] >= A[mid] && A[mid] <= A[mid+1]) return mid;

        if(A[mid-1] >= A[mid] && A[mid] >= A[mid+1]) left = mid+1;
        else if(A[mid] >= A[mid-1] && A[mid+1] >= A[mid]) right=mid-1;
        else left=mid+1;
    }

    return -1;
}

int main(void)
{
    srand(time(nullptr));
    int k=100;
    while(--k)
    {
        vector<int> A ;
        int n = rand()%10+100;
        A.resize(n);
        for(int i=0;i<n;++i)
            A[i]=rand()%100;
        A.insert(A.begin(),A[0]+1);
        A.push_back(A.back()+1);

    //    vector<int> A = {9,8,41,84,25,26};

        int idx= minValue(A) ;
        if(idx == -1) cout << -1 << endl;

        if(A[idx-1]>=A[idx] && A[idx] <= A[idx+1]) cout << A[idx] << endl;
        else 
        {
            cout << "error!!!" << endl;
            for(auto a:A) cout << a<< ",";
            cout << endl;
            exit(1);
        }
    }
    return 0 ;
}
