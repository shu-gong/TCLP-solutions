#include<stdio.h>
/* Write a function htoi(s), which converts a string of hexadecimal digits(including an optional 0x or 0X) into its equibalent integer value. The allowable digits are 0 through 9, a through f, and A through F*/
#define MAXLINE 1000

int htoi(char s[], int l);
int get_line(char s[], lim);

main() {
	char line[MAXLINE];
	int hex_int;
	int len;
	while((len=get_line(line, MAXLINE)) > 0) {
		hex_int = htoi(line, len);
		printf("%x\n", hex_int);
	}
}

int htoi(char s[], int l) {
	int i, j, hex=0, temp=1;
	for(i=0; s[i]!='\0'; ++i) {
		if(s[i] == '0' && (s[i+1]=='x' || s[i+1]=='X')) {
			++i;
		}
		else if(s[i]>='0' && s[i]<='9') {
			hex = hex * 16 + s[i] - '0';
		}
		else if(s[i]>='a' && s[i]<='f') {
			hex = hex * 16 + s[i] - 'a' + 10;
		}
		else if(s[i]>='A' && s[i]<='F') {
			hex = hex * 16 + s[i] - 'A' + 10;
		}
	}
	return hex;
}

int get_line(char s[], lim) {
	int c, i;	
	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
		s[i] = c;
	}
	s[i] = '\0';
	return i;
}
