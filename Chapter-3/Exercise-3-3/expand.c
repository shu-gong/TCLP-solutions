#include<stdio.h>
/* Write a function expand(s1, s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.*/
#define MAXLINE 1000
void expand(char s1[], char s2[]);

main() {
	char test1[] = "1-7 a-z 9-a z-7 a-b-c a-z0-9 -a-z";
	char test2[MAXLINE];
	expand(test1, test2);
	printf("%s", test2);
}

void expand(char s1[], char s2[]) {
	int i,j,k,m,n;	
	char start, prev;
	start = s1[0];
	prev = s1[1];

	for(i=2; s1[i] != '\0'; ++i) {
		if(s1[i] == '-') {
			if(s1[i-1] >= 'a' && s1[i-1] <= 'z'&& s1[i+1] >= 'a' && s1[i+1] <= 'z') {
				n = s1[i+1] - s1[i-1];
				for(j=i, k=0; j<n; ++j, ++k) {
					s2[j] = n+k;
				}
			}
			else if (s1[i-1] >= 'a' && s1[i-1] <= 'z'&& s1[i+1] >= 'a' && s1[i+1] <= 'z') {
				n = s1[i+1] - s1[i-1];
				for(j=i, k=0; j<n; ++j, ++k) {
					s2[j] = n+k;
				}
			}
			else {
				s2[j] = s1[i];
			}
		}
	}
}
