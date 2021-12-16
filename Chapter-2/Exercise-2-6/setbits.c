#include<stdio.h>
/* Write a funciton setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.*/
int setbits(x, p, n, y);
main() {
	int a;
	a = setbits(27,3,3,12);
	printf("%d", a);
	
}

int setbits(x,p,n,y) {
	return (x&~((~(~0 << n)) << (p-n+1))) | (y<<(p-n+1));
}
