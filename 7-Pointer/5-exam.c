#include <stdio.h>


void f1 (int x, int y, int *sum, int *product)
{
	*sum=x+y;
	*product=x*y;
};
int sum, product;
void main()
{
	f1(123, 456, &sum, &product);
	printf ("sum=%d, product=%d\n", sum, product);
};