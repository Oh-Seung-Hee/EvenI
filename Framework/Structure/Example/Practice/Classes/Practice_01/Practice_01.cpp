//#define P01_01
#define P01_02

#include "Practice_01.h"

namespace P01 {
#if defined P01_01
#define STACKSIZE 10

	char stack[STACKSIZE];
	int top = -1;

	void init() {
		top = -1;
	}

	int isEmpty() {
		if(top < 0) {	// 스택이 비어있으면 0을 반환
			return 0;
		} else {
			return 1;	// 스택이 비어있지 않으면 1을 반환
		}
	}

	int isFull() {
		if(top >= STACKSIZE) {	// 스택이 가득 차있으면 0을 반환
			return 0;
		} else {		// 스택이 가득 차있지 않으면 1을 반환
			return 1;
		}
	}

	void push(char num) {
		if(isFull() == 0) {
			printf("스택이 가득 찼습니다.\n");
		} else {
			stack[++top] = num;
		}
	}

	void pop() {
		if(isEmpty() == 0) {
			printf("스택이 비어있습니다.\n");
		} else {
			stack[top--];
		}
	}

#elif defined P01_02
#define STACKSIZE 50

	char stack[STACKSIZE];
	int top = -1;

	void init() {
		top = -1;
	}

	int isEmpty() {
		if(top < 0) {	// 스택이 비어있으면 0을 반환
			return 0;
		} else {
			return 1;	// 스택이 비어있지 않으면 1을 반환
		}
	}

	int isFull() {
		if(top >= STACKSIZE) {	// 스택이 가득 차있으면 0을 반환
			return 0;
		} else {		// 스택이 가득 차있지 않으면 1을 반환
			return 1;
		}
	}

	void push(char num) {
		if(isFull() == 0) {
			printf("스택이 가득 찼습니다.\n");
		} else {
			stack[++top] = num;
		}
	}

	char pop() {
		if(isEmpty() == 0) {
			printf("스택이 비어있습니다.\n");
		} else {
			return stack[top--];
		}
	}

	int oper(char op) {
		switch(op) {
			case '(': case')': return 0;
			case '+': case'-': return 1;
			case '*': case'/': return 2;
		}
	}

	void postfix(char* formula, char* answer) {
		init();

		for(int i = 0; i < STACKSIZE; i++) {
			// 공백 일 경우
			if(isspace(formula[i])) {
				continue;
			}

			// ( 연산자인 경우
			if(formula[i] == '(') {
				push(formula[i]);
			}
			// ) 연산자인 경우
			else if(formula[i] == ')') {
				while(stack[top] != '(') {	// 스택에서 ( 연산자 만날때까지 pop 진행
					*answer++ = pop();
				}
				pop();	// ( 제거
			}
			// 숫자인 경우
			else if(formula[i] >= '0' && formula[i] <= '9') {
				*answer++ = formula[i];
			}
			// +, -, *, / 연산자인 경우
			else if(formula[i] == '+' || formula[i] == '-' || formula[i] == '*' || formula[i] == '/') {
				// 스택이 비어있는 경우
				if(isEmpty() == 0) {
					push(formula[i]);
				}
				// 스택에 뭔가 있는 경우
				else {
					// 스택 안의 연산자보다 지금 연산자가 더 우선순위가 높을 경우
					if(oper(formula[i]) > oper(stack[top])) {
						push(formula[i]);
					}
					// 스택 안의 연산자가 우선순위가 더 높은 경우
					else {
						*answer++ = pop();
						push(formula[i]);
					}
				}
			}
		}
		// 스택에 남아있는 연산자 전부 pop
		while(isEmpty()) {
			*answer++ = pop();
		}
	}

#endif // #if defined P01_01

	int Practice_01(int argc, char* args[]) {
#if defined P01_01
		init();

		printf("=====> 데이터 입력 순서 <=====\n");
		for(int i = 0; i < 10; i++) {
			push(i + 1);
			printf("%d ", stack[i]);
		}
		printf("\n\n");
		printf("=====> 데이터 출력 순서 <=====\n");
		for(int i = top; i > -1; i--) {
			pop();
			printf("%d ", stack[i]);
		}
		printf("\n");

#elif defined P01_02
		char formula[STACKSIZE] = "";
		char answer[STACKSIZE] = "";

		printf("수식 입력 : ");
		//scanf("%s", formula);

		fgets(formula, sizeof(formula), stdin);
		formula[strlen(formula) - 1] = '\0';

		postfix(formula, answer);

		printf("\n결과 : ");
		printf("%s\n", answer);

#endif // #if defined P01_01

		return 0;
	}
}
