#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop();
double get(int);

int main() {
	int type;
	double op2, op1;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
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
					push(pop()/op2);
				else
					printf("error: zero divisor\n");
			break;

			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push(fmod(pop(), op2));
				else
					printf("error: zero divisor\n");
			break;

			case 'p':
				printf("\t%.8g \t%.8g\n", get(1), get(2));
			break;

			case 'd':
				op2 = get(2);
				push(op2);
				push(get(2));
			break;

			case '?':
				op2 = pop();
				op1 = pop();
				push(op2);
				push(op1);
			break;

			case 's':
				push(sin(pop()));
			break;

			case '^':
				op2 = pop();
				push(pow(pop(), op2));
			break;

			case '@':
				push(exp(pop()));
			break;

			case '\n':
				printf("\t%.8g\n", pop());
			break;

			default:
				printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}
