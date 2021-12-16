#include<stdio.h>
/* Write a function setbits(s,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.*/
unsigned getbits(unsigned x, int p, int n) {
	return (x >> (p+1-n)) & ~(~0 << n);
}

main() {
	int a;
	a = getbits(5,4,3);
	printf("%d", a);
}


