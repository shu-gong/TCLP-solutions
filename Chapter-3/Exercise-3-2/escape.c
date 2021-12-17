#include<stdio.h>
/* Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters.*/
void escape(char s[], char t[]);
void reverse_escape(char s[], char t[]);
#define MAXLINE 1000
main() {
	char test[] = "a b c d	eabc	tdea";
	char new1[MAXLINE]; 
	char test2[] = "a\\tb\\nd";
	char new2[MAXLINE];
	escape(test, new1);
	printf("%s", new1);
}

void escape(char s[], char t[]) {
	int i, j=0;
	for(i=0; s[i] != '\0'; ++i) {
		switch (s[i]) {
			case '\t':
				t[j] = '\\';
				t[j+1] = 't';
				t += 2;	
				break;
			case '\n':
				t[j] = '\\';
				t[j+1] = 'n';
				t += 2;
				break;
			default:
				t[j] = s[i];
				++j;
				break;
		}
	}
	t[j] = '\0';
}

void reverse_escape(char s[], char t[]) {

}
