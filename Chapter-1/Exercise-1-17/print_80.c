#include <stdio.h>
#define MAXLINE 1000   /* maximum input line length */
#define OUTPUT_LEN 8
int get_line(char line[], int maxline);
void copy(char to[], char from[]);
/* Write a program to print all input lines that are longer than 80 characters*/

main()
{
	int len;
	int output_len;
	char line[MAXLINE];
	char output_char[MAXLINE]; /* longest line saved here */
	int i;
	i = 0;
	output_len = 0;
	/* current line length */
	/* maximum length seen so far */
	while ((len = get_line(line, MAXLINE)) > 0){
		if (len > OUTPUT_LEN) {
			output_len = len;
			copy(output_char, line);
			if(output_len>0) 
				printf("%s", output_char);
		}
	}
}
/* current input line */
/* getline:  read a line into s, return length  */

int get_line(char s[],int lim)
{
	int c, i;
	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i; }
	s[i] = '\0';
	return i; }
	/* copy:  copy 'from' into 'to'; assume to is big enough */

void copy(char to[], char from[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i; }
