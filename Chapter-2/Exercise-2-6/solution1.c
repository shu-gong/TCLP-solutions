#include <stdio.h>

int setbits(const int x, const int p, const int n, const int y)
{
	return x & ~(((1U << n) - 1) << p) | (y & ((1U << n) - 1)) << p;
}

int main(void)
{
	printf("%d", setbits(27, 3, 3, 6));

	return 0;
}
