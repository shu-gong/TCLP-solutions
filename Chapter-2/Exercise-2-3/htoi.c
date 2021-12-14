#include<stdio.h>
/* Write a function htoi(s), which converts a string of hexadecimal digits(including an optional 0x or 0X) into its equibalent integer value. The allowable digits are 0 through 9, a through f, and A through F*/
#define MAXLINE 1000

int htoi(char s[]);
int get_line(char s[], lim);

main() {
	char line[MAXLINE];
	int hex_int;
	int len;
	while((len=get_line(line, MAXLINE)) > 0) {
		hex_int = htoi(line);
		printf("%d", hex_int);
	}
}

int htoi(char s[]) {
	int i;
	if(s[0] == '0' && (s[1]=='x' || s[1]=='X')){
				
	}
}

int get_line(char s[], lim) {
	int c, i;	
	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
		s[i] = c;
	}
	s[i] = '\0';
	return i;
}
