#include<stdio.h>
/* Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else.*/

#define MAXLINE 1000
void lower(char s[]);
main() {
	char line[] = "ABCED";
	lower(line);
	printf("%s", line);
}

void lower(char s[]) {
	int i;
	for(i=0; s[i] != '\0'; ++i) {
		s[i] = (s[i] >= 'a' && s[i] <= 'z') ? s[i] : s[i] + 'a' - 'A';
	}
} 
