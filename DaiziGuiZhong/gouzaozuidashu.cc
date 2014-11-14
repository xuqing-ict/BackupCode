/**
 * @file gouzaozuidashu.cc
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
#include <string.h>

using namespace std;

//compare lhsrhs rhslhs
bool cmp(int lhs, int rhs)
{
    cout << "compare : " << lhs << " " << rhs << endl;
    char tmp1[20],tmp2[20];
    sprintf(tmp1,"%d",lhs);
    sprintf(tmp2,"%d",rhs);
    cout << lhs << " " << tmp1 << endl;
    cout << rhs << " " << tmp2 << endl;

    int len1 = strlen(tmp1),len2=strlen(tmp2);
    if(len1 == len2) return lhs > rhs;

    //len1 != len2
    //add tmpw to tmp1, and add tmp1 to tmp2
    char temp[20] = {0};
    strcat(temp,tmp1);
    strcat(tmp1,tmp2);
    strcat(tmp2,temp);
    
    cout << "compare : " << tmp1 << " " << tmp2 << endl;

    if(strcmp(tmp1,tmp2) > 0) return true;
    return false;
    
}
int partition(int *A, int left, int right)
{
    int pivot = A[right];
    int i=left;
    for(int k=left;k<right;++k)
    {
        if(cmp(A[k],pivot)) swap(A[i++],A[k]);
    }
    swap(A[i],A[right]);
    return i;
}

void quickSort(int *A, int left, int right)
{
    if(left >= right) return;
    int idx = partition(A,left,right);
    quickSort(A,left,idx-1);
    quickSort(A,idx+1,right);
}

void constructMaxNum(int *A, int n)
{
    if(A == nullptr || n <= 0 ) return ;
    quickSort(A,0,n-1);

    cout << "ret : ";
    for(int i=0;i<n;++i)cout<< A[i];
    cout << endl;
}

int main(void)
{
    //int  A[] = {96, 9, 95 ,556 ,56 ,55, 5 ,554 ,54, 3 ,2 ,1};
    int A[] = {94,9,4,14,1};
    int n = sizeof(A)/sizeof(int);
    constructMaxNum(A,n);
    return 0 ;
}
