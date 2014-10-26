#include <stdio.h>

int func()
{
    printf("func called...\n");
    return 0;
}

void Test()
{
    static int i = (func(),1);
    printf("Test called...\n");
}

int main(void)
{
    printf("Main\n");
    int  i=0;
    for(;i<3;++i)
        Test();   
    return 0;
}
