#include<stdio.h>
#define MAXLINE 1000

int atoi(char s[]);
int get_line(char s[], lim);

main() {
	int c, len;
	char line[MAXLINE];
	while((len=get_line(line, MAXLINE)) > 0) {
		printf("%d", atoi(line));
	}
}

int atoi(char s[]) {
	int i,n;
	n = 0;
	for (i=0; s[i]>='0' && s[i]<='9'; ++i) {
		n = 10*n + (s[i] - '0');
	}
	return n;
}

int get_line(char s[], lim) {
	int c, i;
	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n';++i) {
		s[i] = c;
	}
	s[i] = '\0';
	return i;
}
	
