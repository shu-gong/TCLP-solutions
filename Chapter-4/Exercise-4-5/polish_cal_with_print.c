#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

/* Add the commands to print the top elements of the stack without popping, to duplicate it, and to swap the top two elements. Add a command to clear the stack.*/

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int getop(char []);
void push (double);
double pop(void);
int getch(void);
void ungetch(int);
char print_top(void);
void duplicate_top(void);
void swap_top_two(void);
void clear_stack(void);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

/* Reverse Pplish calculator*/
main() {
	int type;
	double op2;
	char s[MAXOP];

	while((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
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
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
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
