#include<stdio.h>
/* Write a program entab that replaces strings of blanks by teh minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab of a single blank would suffice to reach a tab stop, which should be given preference?*/
#define MAXLINE 1000
#define TAB2SPACE 4

int get_line(char s[], lim);

main() {
	int i, t;
	int spacecount, len;

	char line[MAXLINE];
	while((len=get_line(line, MAXLINE)) > 0) {
		spacecount = 0;
		for(i=0; i<len; ++i){
			if(line[i] == ' ')
				++spacecount;
			if(line[i] != ' ')
				spacecount = 0;
			if(spacecount == TAB2SPACE) {
				i -= 3;
				len -= 3;
				line[i] = '\t';

				for(t=i+1; t<len; t++) {
					line[t] = line[t+3];
				}
				spacecount = 0;
				line[len] = '\0';
			}
		}
		printf("%s", line);
	}
}

int get_line(char s[], lim) {
	int c,i=0, n;
	while(i<lim-1 && (c=getchar())!=EOF && c!='\n') {
		s[i] = c;
		++i;
	}
	if(c == '\n') {
		s[i] = c;
		++n;
	}
	s[i] = '\0';
	return i;
}
