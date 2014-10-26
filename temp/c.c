#include<stdio.h>
int main()
{
	int b = 5;
	char *p,*q;
	p = "xyz";
	q=p;
	printf("p = %s\n",p);
	printf("q = %s\n",q);
	int m = 3;
	int n=m++ + ++m;
	printf("m=%d\tn=%d\n",m,n);
	return 0;
}
