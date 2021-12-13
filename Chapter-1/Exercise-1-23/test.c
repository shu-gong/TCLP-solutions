#include <stdio.h>

/*  author: Daniel Schmidt Silva  */
/* remove comments from C sources */

#define YES 1
#define NO  !YES

int main()
{
	/* c is the current character, c_prev is the previous one and c_pprev the one before c_prev */
	int c, c_prev='\0', c_pprev = '\0', is_comment = NO, is_string = NO, closing_symbol;

	while ((c = getchar()) != EOF)
	{
		if (!is_comment)
		{
			/* fix the slash if it is not a comment */
			if (!is_string && c_prev == '/' && c != '*' && c_pprev != '*')
				putchar('/');
			/* print the char if it is not the begining of a comment */
			if (is_string || (c != '/' && (c != '*' || c_prev != '/')))
				putchar(c);
		}
		/* closing the comment */
		if (is_comment && c == '/' && c_prev == '*')
			is_comment = NO;
		/* begining the comment */
		else if (!is_comment && !is_string && c == '*' && c_prev == '/')
			is_comment = YES;
		/* closing the string or character, handles escape sequences \' and \\' */
		else if (is_string && c == closing_symbol && (c_prev != '\\' || c_pprev == '\\'))
			is_string = NO;
		/* begining the string or character */
		else if (!is_string && !is_comment && (c == '"' || c == '\''))
		{
			is_string = YES;
			closing_symbol = c;
		}
		c_pprev = c_prev;
		c_prev = c;
	}

	return 0;
}
