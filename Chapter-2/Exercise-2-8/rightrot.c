#include<stdio.h>
/* Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions.*/
unsigned rightrot(unsigned x, int n);

main() {
	unsigned a;
	a = rightrot(45,3);
	printf("%x", a);
}

unsigned rightrot(unsigned x, int n) {
	return (x >> n) | (x << (8 - n));
}
