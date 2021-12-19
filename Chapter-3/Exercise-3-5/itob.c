#include<stdio.h>
#include<string.h>
/* Write the function itob(n, s, b) that converts the integer n into a base b character representation in the string s. In particular, itob(n,s,16) formats s as a hexadecimal integer in s*/

void itob(int n, char s[], int b);
void reverse(char s[]);
main() {
	int n;

}

void itob(int n, char s[], int b) {
	int i,j,k, sign;
	if((sign = n) < 0) {
		n = -n;
	}
	i = 0;
	do {
		s[i++] = n % b + '0';
	} while (s / b > 0)
	s[i++] = '\0';
	reverse(s);
}


