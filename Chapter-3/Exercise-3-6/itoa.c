#include<stdio.h>
#include<string.h>
/* Write a version of itoa that accepts three arguments instread of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough.*/
#define MAXLINE 1000
void reverse(char s[]);
void itoa(int n, char s[], int m) ;

main() {
	char test[MAXLINE];
	itoa(-128, test, 10);
	printf("%s", test);
}

void itoa(int n, char s[], int m) {
	int i=0, j, sign;
	if((sign=n) < 0) {
		n = -n;
	}
	do {
		s[i++] = n % 10 + '0';
	} while((n /= 10) > 0);
	if (sign < 0) {
		s[i++] = '-';
	}
	while(i < m) {
		s[i++] = ' ';
	}
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]) {
	int i,j,temp;
	for(i=0,j=strlen(s)-1; i<j; i++,j--) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

