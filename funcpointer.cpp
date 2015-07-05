#include <stdio.h>

void my_init_func(int x)
{
	printf("%d\n",x);
}

int main()
{
 void (*foo)(int);
 foo = &my_init_func;
 foo(2);
 return 0;
}
