#include <stdio.h>

int main() {
	int a[5];

	a[0] = 2;
	a[1] = 3;
	a[2] = 7;

	printf("sizeof(a) = %lu\n", sizeof(a));
	printf("sizeof(a[0]) = %lu\n", sizeof(a[0]));

	printf("a[2] = %d\n", a[2]);
	printf("*a(a+2) = %d\n", *(a+2));
	printf("a = %p\n", a);
	return 0;
}