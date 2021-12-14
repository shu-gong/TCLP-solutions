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
		printf("%x\n", hex_int);
	}
}

int htoi(char s[]) {
	int i, j, hex=0, temp=1;
	if(s[0] == '0' && (s[1]=='x' || s[1]=='X')){
		for(i=2; s[i]!='\0'; ++i) {
			for(j=0; j<i-2; ++j) {
				temp = temp * 16;
			}
			if(s[i]>='0' && s[i]<='9') {
				s[i] = s[i] - '0';
			}
			else if(s[i]>='a' && s[i]<='z') {
				s[i] = s[i] - 'a' + 10;
			}
			else if(s[i]>='A' && s[i]<='Z') {
				s[i] = s[i] - 'A' + 10;
			}
			hex += temp * s[i];
			temp = 1;
		}
	}
	else {
		for(i=2; s[i]!='\0'; ++i) {
			for(j=0; j<i-2; ++j) {
				temp = temp * 16;
			}
			if(s[i]>='0' && s[i]<='9') {
				s[i] = s[i] - '0';
			}
			else if(s[i]>='a' && s[i]<='z') {
				s[i] = s[i] - 'a' + 10;
			}
			else if(s[i]>='A' && s[i]<='Z') {
				s[i] = s[i] - 'A' + 10;
			}
			hex += temp * s[i];
			temp = 1;
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
