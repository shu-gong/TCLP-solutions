#include<stdio.h>
/* Write a funciton setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.*/
int setbits(int x, int p, int n, int y);
main() {
	int a;
	a = setbits(27,3,3,6);
	printf("%d", a);
	
}

int setbits(int x, int p, int n, int y) {
	return (x & (~((~(~0 << n)) << (p-n+1)))) | (y << (p-n+1));
}
