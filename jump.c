#include<stdio.h>
#include<setjmp.h>
jmp_buf buf;

void banana()
{
	printf("int banana\n");
	volatile int tt = 0;
	longjmp(buf,1);
	printf("never to here...\n");
	return;
}
int main()
{
	if (setjmp(buf))
	{
		printf("back in main\n");
	}
	else
	{
		printf("first time through\n");
		banana();
	}
}
