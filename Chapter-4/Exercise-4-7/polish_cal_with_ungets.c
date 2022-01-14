#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <math.h>
/* Add commands for handling variables. (It's easy to provide twenty-six varibles with single-letter names.) Add a variable for the most recent printed value.*/

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100
#define VARIABLE 'A'

int getop(char []);
void push (double);
double pop(void);
int getch(void);
void ungetch(int);
char print_top(void);
void duplicate_top(void);
void swap_top_two(void);
void clear_stack(void);
int set_var(char s[]);
int elem(void);

int is_first_input = 0; /* Prevents the solution from being printed firt input*/
double var_array[VARMAX];
int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

char variables[];

/* Reverse Polish calculator*/
main() {
	int type;
	double op2;
	char s[MAXOP];
	double base;
	int op3, i, j;
	char tmp[MAXOP];
	
	for (i=0; i<VARMAX; i++) {
		var_array[i] = 0;
	}


	while((type = getop(s)) != EOF) {
		op3 = elem();
		if (op3 == 0) {
			is_first_input = 1;
		} else if (op3 > 1) {
			is_first_input = 0;
		}
		i = j = 0;
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case VARIABLE:
				for (i=2; s[i]!='\0'; i++) {
					tmp[j++] = s[i];
					tmp[j] = '\0';
				}
				var_array[s[0] - 'A'] = atof(tmp);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else 
					printf("error: zero division\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push((double)((int)pop() % (int)op2));
				else
					printf("error: zero division\n");
				break;
			case 's':
				push(sin(pop()));
				break;
			case 'e':
				push(exp(pop()));
				break;
			case '^':
				op2 = pop();
				base = pop();
				if (base >  0.0) {
					push(pow(base,op2));
				}
				else
					printf("base must larger than  zero");
				break;
			case '!':
				duplicate_top();
				break;	
			case '=':
				swap_top_two();
				break;
			case '|':
				clear_stack();
				break;
			case '\n':
				printf("\t %d \n", print_top());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

/* push: push f onto value stack*/
void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack*/
double pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* getop: get next character or numeric operand*/
int getop(char s[]) {
	int i=0, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t');

	s[1] = '\0';

	if (isalpha(c) && c>= 'A' && c<= 'Z') {
		for (; s[i]!=' '&&s[i]!='\n'; s[++i]=getch());
		s[i] = '\0';
		if (i > 1) {
			return VARIABLE;
		} else {
			return c; /* When '\n' */
		}
	} else if (!isdigit(c) && c!='.' && c!='-') {
		return c; /* Not a number. */
	}
	
	if (c == '-') {
		if ((c = getch()) == ' ') {
			return c;
		} else if (isdigit(c)) {
			s[++i] = c;
		}
	}

	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()));
	if (c == '.')
		while (isdigit(s[++i] = c = getch()));
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void ungets(char *s) {
	int i, len;
	len = strlen(s);
	if (BUFSIZE - bufp >= len) {
		for (i = strlen(s) - 1; i>=0; i--) {
			ungetch(s[i]);
		}
	}
	else {
		printf("error: insufficient space in buffer, can't execute ungets()\n");
	}
}

char print_top(void) {
	if (sp > 0)  {
		/*这里查看的是val而不是buf原因在于：val储存的是stack中处理后的值，而buf储存所有输入的值*/
		char top;
		top =(int) val[sp-1];
		return top; 
	}
	else
		printf("The stack is empty!\n");
}

void duplicate_top(void) {
	double top;
	top = pop();
	push(top);
	push(top);
}

void swap_top_two(void) {
	double top, top2;
	top = pop();
	top2 = pop();
	push(top);
	push(top2);
}

void clear_stack(void) {
	while(sp!=0) {
		pop();
	}
}

int set_var(char s[]) {
	int idx, value;
	idx = s[0] - 'a';
	printf("s: %s\n", s);
	printf("idx: %d\n", idx);

	if(s[1]=='=') {
		variables[idx] = s[2] - '0';
		printf("variables: %d\n", variables[idx]);
		return variables[idx];
	}	
	else{
		printf("variables: %s\n", variables);
		return variables[idx];
	}
}
int elem(void) {
	return sp;
}

