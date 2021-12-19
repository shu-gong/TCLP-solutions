#include<stdio.h>
#include<string.h>
/* Write the function itob(n, s, b) that converts the integer n into a base b character representation in the string s. In particular, itob(n,s,16) formats s as a hexadecimal integer in s*/
#define MAXLINE 1000
void itob(int n, char s[], int b);
void reverse(char s[]);
main() {
	int n;
	n = 127;
	char test[MAXLINE];
	itob(n, test, 2);
	printf("%s", test);
}

void itob(int n, char s[], int b) {
	int i,j,k, sign;
	if((sign = n) < 0) {
		n = -n;
	}
	i = 0;
	do {
		s[i++] = n % b + '0';
	} while (n / b > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]) {
	int i,j, temp;
	for(i=0, j=strlen(s)-1; i < j; i++, j--) {
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
	}
}
