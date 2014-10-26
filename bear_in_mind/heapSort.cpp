#include<iostream>
using namespace std;
void max_heapify(int A[],int heap_size,int i)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = i;
    if(l<heap_size&&A[l]>A[largest])
    {
        largest = l;
    }
    if(r<heap_size&&A[r]>A[largest])
    {
        largest = r;
    }
    if(largest!=i)
    {
        swap(A[i],A[largest]);
        max_heapify(A,heap_size,largest);
    }
}
void build_max_heap(int A[], int heap_size)
{
    for(int i = heap_size/2-1;i>=0;--i)
    {
        max_heapify(A,heap_size,i);
    }
}
void heapSort(int A[], int len)
{
    build_max_heap(A,len);
    for(int i = len-1;i>=0;i--)
    {
		cout << "A[0] = " << A[0] << endl;
        swap(A[i],A[0]);
        max_heapify(A,i,0);
    }
}
int main()
{
    int A[] = {15,13,9,5,12,8,7,4,0,6,2,1};
    int len = sizeof(A)/sizeof(int);
    cout << len << endl;
    heapSort(A,len);
    for(int i = 0; i < len;++i)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

