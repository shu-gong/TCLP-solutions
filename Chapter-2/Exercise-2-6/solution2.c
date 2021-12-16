#include<stdio.h>
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	unsigned msk = ~(~0 << n);
	return (x & ~(msk<< p+1-n)) | ((y & msk)<< p+1-n);
}
main() {
	printf("%d", setbits(27,3,3,6));
}
