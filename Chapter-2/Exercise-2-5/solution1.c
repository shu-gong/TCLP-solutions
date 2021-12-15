
#include<stdio.h>
/* NOTE: This solution is wrong*/

int any(char s1[], char s2[]);
main() {
	
}
int any(char s1[], char s2[])
{
	int i, j;

	for(i = 0; s1[i] != '\0'; i++) {		/* for each s1[i] */
		for(j = 0; s2[j] != '\0'; j++) {	/* for each s2[j] */
			if(s1[i] == s2[j]) 		/* match found? */
				return i;		/* no need for further code */
		}
	}
	return -1;					/* no match */
}
