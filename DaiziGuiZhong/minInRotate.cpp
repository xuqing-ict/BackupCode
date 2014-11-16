#include <bits/stdc++.h>
using namespace std;

/*
int minVal(int A[], int left, int right)
{
    assert(A!=nullptr && left <= right);

    int index1 = left, index2 = right;
    int ret = index1;
    while(A[index1] >= A[index2])
    {
        if(index1 +1 == index2)
        {
            ret = index2;
            break;
        }
        ret = index1 + (index2-index1)/2;
        if(A[ret] == A[index1] && A[ret] == A[index2])
            return *(min_element(A+index1, A+index2+1));
        if(A[ret] >= A[index1])
        {
            index1 = ret;
        }
        else if (A[ret] <= A[index2])
        {
            index2 = ret;
        }
    }
    cout << ret << "\t" << A[ret] << endl;
    return A[ret];
}
*/
/*
int minVal(int A[], int n)
{
    if(A == nullptr || n <= 0 )
    {
        cout << "Illegal input ..." << endl;
        return -1;
    }
    int left= 0 , right = n-1;
    //left point to the left ascend array.
    //right point to the right ascend array
    int minIndex = left;
    while(A[left] >= A[right])
    {
        if(left + 1 == right)
        {
            minIndex=right;
            break;
        }
        minIndex = left + (right-left)/2;
        if(A[left] == A[minIndex] && A[minIndex] == A[right])
        {
            return *min_element(A+left, A+right+1); // ֻ��˳�������
        }
        if(A[left] <= A[minIndex])
            left=minIndex;
        else if(A[right] >= A[minIndex])
            right=minIndex;
    }
    return A[minIndex];
}
*/
/*
int  minVal(int A[], int n)
{
  if(A == nullptr || n<= 0 ) return -1;
   int left=0, right=n-1;
   int mid=left ; // ���ԭ�Ⱦ�������Ļ�����ô���ǵ�һ��Ԫ��,�������ѭ������
   while(A[left] >= A[right])
  {
    //�����Ѿ��������
    if(left+1 == right) return A[right];
    int mid = left+(right-left)/2;
    //�޷��ж����ı�
    if(A[left] == A[mid] && A[mid] == A[right]) return *min_element(A+left,A+right+1);
    //�����ж����ı�
    if(A[left] <= A[mid]) left=mid;
    else if(A[mid] <= A[right] ) right=mid;
  }
  return A[mid];
}
*/
int A[1000001];

int minVal(int A[], int n)
{
    if(A == NULL || n <= 0 ) return -1;
    int left=0,right=n-1;
    int mid = left; //������������
    //left Ϊ��ߴ�ĵ��������β�ͣ�rightΪ�ұߵ�С�ĵ��������β��ͷ����һֱ�бƣ�����
    while(A[left] >= A[right])
    {
        if(left+1==right) return A[right];
        int mid=left+(right-left)/2;
        if(A[left] == A[mid] && A[mid] == A[right]) return *min_element(A+left,A+right+1); //�޷��жϣ�ֻ�ܱ���
        if(A[left] <= A[mid]) left=mid; //�п�����mid������left=mid
        else if(A[mid] <= A[right]) right=mid;
    }
    return A[mid];
}

int main()
{
    fill_n(A,1000001,0);
    int n;
    while(scanf("%d",&n) != EOF)
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d",A[i]);
        }
        cout << minVal(A, n) << endl;
    }
    return 0;
}
