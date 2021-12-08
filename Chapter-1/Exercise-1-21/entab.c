#include<stdio.h>
/* Write a program entab that replaces strings of blanks by teh minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab of a single blank would suffice to reach a tab stop, which should be given preference?*/
#define MAXLINE 1000
int get_line(char s[], lim);
void entab(char to[], char from[]);

main() {
	int len;
	int line[MAXLINE];
	int nline[MAXLINE];

	while((len=get_line(line, MAXLINE)) > 0) {
		entab(nline, line);
		printf("%s", nline);
	}
}

int get_line(char s[], lim) {
	int c,i, n;
	while(i<lim-1 && (c=getchar())!=EOF && c!='\n') {
		s[i] = c;
		if(c == '\n') {
			s[i] = c;
			++n;
		}
		++i;
	}
	s[i] = '\0';
	return n;
}

void entab(char to[], char from[]) {
	int i,j,m,n,b;
	for(m=0; from[m]!='\0';++m);
	for(n=0; 4*n <= m && 4*n+4>m; ++n);
	
	b = m - 4*n;	

	for(i=0; i<n; ++i) {
		putchar('\t');
	}
	for(j=0; j<b; ++j) {
		putchar(' ');
	}
}


