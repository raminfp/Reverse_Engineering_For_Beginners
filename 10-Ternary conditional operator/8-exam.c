#include <stdio.h>


const char* f (int a)
{
return a==10 ? "it is ten" : "it is not ten";
};

int main()
{
	f(4);
	return 0;
}