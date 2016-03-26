#include <stdio.h>


void f (int a)
{
	switch (a)
	{
		case 0: printf ("Zero\n"); break;
		case 1: printf ("One\n"); break;
		case 2: printf ("Two\n"); break;
		default: printf ("unknown\n"); break;
	};
};
int main()
{
	f (1);
	return 0;	
};