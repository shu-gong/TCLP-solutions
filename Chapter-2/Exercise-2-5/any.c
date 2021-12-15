#include<stdio.h>
/* Write the function any(s1, s2), which returns the first location in a string s1 wjere any character from the string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library function strbrk does the same job but returns a pointer to the location.)*/

int any(char s1[], char s2[]);

main() {
	int c;	

	char test1[] = "123ab1cabc123bcaa";
	char test2[] = "abc";

	c = any(test1, test2);
	printf("%d", c);

}

int any(char s1[], char s2[]) {
	int i,j=0,k;
	for(i=0; s1[i] != '\0'; ++i) {
		if(s1[i] = s2[0]) {
			for(k=i; s1[k] == s2[j]; ++k) {
				++j;	
			}
			if(s2[j] == '\0') {
				return i;
			}
			else {
				continue;
			}
		}
	}
}
