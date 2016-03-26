#include <stdio.h>


void f(int a)
{
	switch (a)
	{
		case 1:
		case 2:
		case 7:
		case 10:
			printf ("1, 2, 7, 10\n");
			break;
		case 3:
		case 4:
		case 5:
		case 6:
			printf ("3, 4, 5\n");
			break;
		case 8:
		case 9:
		case 20:
		case 21:
			printf ("8, 9, 21\n");
			break;
		case 22:
			printf ("22\n");
			break;
		default:
			printf ("default\n");
			break;
	};
};
int main()
{
		f(4);
};