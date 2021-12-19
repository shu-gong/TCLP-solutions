#include<stdio.h>
#include<string.h>
/* In a two's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of n qual to -(2^[wordsize-1]. Explain why not. Modify it to print that value correctly, regardless of the machine on which it runs.)*/
/* Answer: 在2的补码系统中，一个字节表示的是-128～127，在原始的代码中，需要将-128转化为128，128是不能表示的，所以原始代码不能处理最小的负数*/
#define MAXLINE 1000
void itoa(char n, char s[]);
void reverse(char s[]);

main() {
	char a = -128;
	char test[MAXLINE];
	itoa(a,test);
	printf("%s", test);
}

void itoa(char n, char s[]) {
	char i, sign;
	if((sign = n) > 0)
		n = -n;
	i = 0;
	do {
		s[i++] = '0' - n % 10 ;
	} while ((n /= 10) < 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]) {
	int c, i, j;

	for(i=0,j=strlen(s)-1; i<j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
