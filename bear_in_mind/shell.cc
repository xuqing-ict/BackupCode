//此版本也能处理元素全相同的情况
#include<iostream>
using namespace std;
/*

void shellSort(int A[], int n)
{
	for(int gap = n/2 ; gap > 0; gap = gap/2)
	{
        //当gap长度确定时，第一个序列的终点位置肯定是从gap开始的。
		for(int k = gap ; k < n ; ++k)
		{
			if (A[k] < A[k-gap])
			{
				int x = A[k];
				int i = k - gap;
				while( i >= 0 && A[i] > x)
				{
					A[i+gap] = A[i];
					i -= gap;
				}
				A[i+gap] = x;
			}
		}
        //each gap 
        for(int i=0;i<n;++i)
            cout << A[i] << "\t";
        cout << endl;
	}
}

*/
void shellSort(int A[], int n)
{
    for(int gap=n/2;gap>0;gap>>=1)
    {
        for(int i=gap;i<n;++i)
        {
            if(A[i] < A[i-gap])
            {
                int tmp=A[i];
                int k=i-gap;
                //insert sort!!!
                while(k>=0 && A[k]>tmp)
                {
                    A[k+gap]=A[k];
                    k-=gap;
                }
                A[k+gap]=tmp;
            }
        }
    }
}
int main()
{
  
    srand(time(NULL));
    int n = rand()%10;
    int *A = new int[n];
    
 //   int A[] = {5,11,2,12,0,9,17,1};
   // int n=sizeof(A)/sizeof(int);

    for(int i=0;i<n;++i)
        A[i]=rand()%20;

	for(int i=0;i<n;++i)
		cout << A[i] << " ";
	cout << endl;
	shellSort(A,n);

	for(int i=0;i<n;++i)
		cout << A[i] << " ";
	cout << endl;
    delete [] A ;
    return 0;
}
