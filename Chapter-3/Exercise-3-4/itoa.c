#include<stdio.h>
/* In a two's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of n qual to -(2^[wordsize-1]. Explain why not. Modify it to print that value correctly, regardless of the machine on which it runs.)*/

main() {
	
}

void itoa() {
	int i, sign;
	if((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
