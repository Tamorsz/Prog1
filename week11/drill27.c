#include <stdio.h>

void function(const char* p, const int x)
{
	printf("p is \"%s\" and x is %i\n", p, x);
}

int main()
{
	printf("Hello, World!\n");
	char* a = "Hello";
	char* b = "World!\n";
	printf("%s %s",a,b);
	
	function("foo", 7);
	function("aha", 12);
	function("glhf", 9);
}
