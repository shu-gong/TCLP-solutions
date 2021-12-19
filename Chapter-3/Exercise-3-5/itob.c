#include<stdio.h>
#include<string.h>
/* Write the function itob(n, s, b) that converts the integer n into a base b character representation in the string s. In particular, itob(n,s,16) formats s as a hexadecimal integer in s*/
#define MAXLINE 1000
void itob(int n, char s[], int b);
void reverse(char s[]);
void hex_conver(char s[]);
main() {

	int n;
	n = 120;
	char test[MAXLINE];
	itob(n, test, 16);
	printf("%s", test);
}

void itob(int n, char s[], int b) {
	int i, sign;
	if((sign = n) < 0) {
		n = -n;
	}
	i = 0;
	do {
		s[i++] = n % b + '0';
	} while ((n /= b) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
	if (b == 16){
		hex_conver(s);
	}
}

void reverse(char s[]) {
	int i,j, temp;
	for(i=0, j=strlen(s)-1; i < j; i++, j--) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

void hex_conver(char s[]) {
	int i;
	for(i=0; s[i] != '\0'; i++) {
		if (s[i] >= '10' && s[i] <= '15') {
			s[i] = s[i] - '10' + 'a';
		}
	}
}

