#include<stdio.h>
/* Write a function reverse(s) that reverses the character string s. Use it to write a program that reverse its input a line at a time.*/ #define MAXLEN 1000
void reverse(char from[], char to[], int len);
int read_line(char s[], int lim);
main() {
	int c, len;

	char line[MAXLEN];
	char reverse_line[MAXLEN];

	while((len = read_line(line, MAXLEN)) > 0){

		reverse(line, reverse_line, len);
	} 
}

void reverse(char from[], char to[], int idx){

	int  j;
	j = 0;

	while (idx != 0)	{
		if (from[idx] != '\0' && from[idx] != '\n') {
			to[j] = from[idx];
			++j;
		}
		--idx;
	}

	to[j+1] = '\0';
	printf("%s", to);
}

int read_line(char s[], int lim){
	int c, i;
	for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	printf("%s", s);
	return i;
}

