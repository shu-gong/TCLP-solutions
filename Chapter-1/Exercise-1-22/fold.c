#include<stdio.h>
/* Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. MAke sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column*/

#define MAXLINE 1000
#define FOLDLEN 20
int get_line(char s[], lim);

main() {
	char line[MAXLINE];
	char nline[MAXLINE];
	int len,i;
	while((len=get_line(line, MAXLINE)) > 0)	 {
		if(len <= FOLDLEN) {
			printf("%s", line);
		}
		else {
			for(i = FOLDLEN+1; i<len-1; ++i) {
				line[i+1] = line[i];
			}
			line[FOLDLEN] = '\n';
			printf("%s", line);
		}
	}
}

int get_line(char s[], lim) {
	int c,i;
	while(i<lim-1 && (c=getchar())!=EOF && c!='\n') {
		s[i] = c;
		++i;
	}
	if (c == '\n'){
		s[i] = c;
		++ i;
	}
	s[i] = '\0';
	return i;
}
