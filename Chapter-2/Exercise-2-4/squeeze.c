#include<stdio.h>
/* Write an alternative version of squeeze(s1, s2) that deletes each character in s1 that matches any character in the string s2*/
void squeeze(char s1[], char s2[]);

main() {
	char test1[] = "aaasxkbc123bcbacaab";
	char test2[] = "abc";

	squeeze(test1, test2);
	printf("%s", test1);
}

void squeeze(char s1[], char s2[]) {
	int i=0,j=0, k=0;
	for(j=0; s2[j]!='\0'; ++j) {
		for(i=k=0; s1[i]!='\0'; ++i) {
			if(s1[i] != s2[j]) {
				s1[k++] = s1[i];
			}
		}
	}
	s1[k] = '\0';
}
