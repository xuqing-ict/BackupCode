#include <stdio.h>

void inplace_swap(int *x, int *y)
{
	*y = *x ^ *y;
	*x = *x ^ *y;
	*y = *x ^ *y;
	return;
}

void reverse(int A[], int l , int r)
{
	while(l < r)
	{
		inplace_swap(A + l, A + r);
		++l;--r;
	}
	return ;
}


int main()
{
	int A[] = {1,2,3,4, 5};
	int n = sizeof(A)/sizeof(int);
	int i = 0 ;
	for(i = 0 ; i < n ; ++i )
	{
		printf("%d\t",A[i]);
	}
	printf("\n");
	reverse(A, 0, n-1);
	for(i = 0 ; i < n ; ++i )
	{
		printf("%d\t",A[i]);
	}
	printf("\n");
	return 0;
}	
