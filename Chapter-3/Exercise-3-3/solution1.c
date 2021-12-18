#include <stdio.h>


void expand(char s1[], char s2[]) {

    char c, d, e;
    int i, j;
    i = j = 0;

    while ('\0' != (c = s1[i++])) {
        if (' ' != c && '-' == s1[i] && '\0' != s1[i + 1]) {
            i++;
            d = s1[i];
            if (d < c) {
                while (c > d) {
                    s2[j++] = c--;
                }
            }
            else {
                while (c < d) {
                    s2[j++] = c++;
                }
            }
        }
        else {
            s2[j++] = c;
        }
    }
    s2[j] = '\0';
}


main() {


    char s1[512] = "-a-z 0-9 a-d-f -0-2 some text 1-1 WITH CAPITALS! 0-0 5-3 -";
    char s2[512];
    expand(s1, s2);
    printf("%s\n", s2);

}
