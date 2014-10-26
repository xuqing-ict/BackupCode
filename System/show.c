#include <stdio.h>

typedef unsigned char * byte_pointer;

void show_bytes(byte_pointer start, int len)
{
	printf("len = %d\n", len);
	int i;
	for( i = 0 ; i < len ; ++i)
	{
		printf("%.2x " , start[i]);
	}
	printf("\n");
}

void show_int(int x)
{
	show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x)
{
	show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
	show_bytes((byte_pointer)&x, sizeof(void *));
}

int main()
{
	int x = 12345;
	show_int(x);
	int *ptr = &x;
	printf("show pointer : %d\n", sizeof(byte_pointer));
	show_pointer(ptr);
	
	char c = 'A';
	show_int(c);
	char *p = &c;
	printf("show pointer : %d\n", sizeof(byte_pointer));
	show_pointer(p);
	return 0;
}

