#include<stdio.h>
/* Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters.*/
void escape(char s[], char t[]);
void reverse_escape(char s[], char t[]);
#define MAXLINE 1000
main() {
	char test[] = "a b c d	e";
	char new1[MAXLINE]; 
	char test2[] = "a\\tb\\nd";
	char new2[MAXLINE];
	printf("%s", test2);
}

void escape(char s[], char t[]) {
	
}

void reverse_escape(char s[], char t[]) {
	
}
