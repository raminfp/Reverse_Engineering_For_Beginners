#include <stdio.h>

int f1(int a,int b)
{
	if (a > b)
	{
		printf("a > b");
	}
	if (a < b)
	{
		printf("a < b");
	}
	else
	{
		printf("a == b");
	}
	return 0;
}

int main()
{
	
	f1(3,4);
	return 0;
}