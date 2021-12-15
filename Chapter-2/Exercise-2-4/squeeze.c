#include<stdio.h>
/* Write an alternative version of squeeze(s1, s2) that deletes each character in s1 that matches any character in the string s2*/
void squeeze(char s1[], char s2[]);

main() {
	char test1[] = "aaabc123bcbacaab";
	char test2[] = "abc";

	squeeze(test1, test2);
	printf("%s", test1);
}

void squeeze(char s1[], char s2[]) {
	int i=0,j=0, k=0;
	while(s1[i] != '\0') {
		while(s2[j] != '\0') {
			if(s1[i] == s2[j]) {
				for(k=i; s1[k]!='\0'; ++k) {
					s1[k] = s1[k+1];
				}
				j=0;
			} 
			else {
				++j;
			}
		}
		j=0;
		++i;
	}
}
