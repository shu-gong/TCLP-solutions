#include<stdio.h>
/* Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions.*/
unsigned rightrot(unsigned x, int n);

main() {
	int a;
	a = rightrot(45, 2);
	printf("%x", a);
}

unsigned rightrot(unsigned x, int n){
	return x >> n | ((x & (~(~0 << n))) << (8 - n));
}
