#include<stdio.h>
void squeeze(char s[], char t[]);
main() {
	char test1[] = "abacaca123aavas";
	char test2[] = "abc";

	squeeze(test1, test2);
	printf("%s", test1);
}

void squeeze(char s[], char t[]) {
    int i, j, k;
    for (k = 0; t[k] != '\0'; k++) {
        for (i = j = 0; s[i] != '\0'; i++)
            if (s[i] != t[k])
                s[j++] = s[i];
        s[j] = '\0';
    }
}
