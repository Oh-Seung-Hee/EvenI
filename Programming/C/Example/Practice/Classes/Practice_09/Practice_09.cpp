//#define P09_01
#define P09_02
#define P09_03

#include "Practice_09.h"

namespace P09 {
#if defined P09_01
	char zero[35] = { '*', '*', '*', '*', '*',
		'*', ' ', ' ', ' ', '*',
		'*', ' ', ' ', ' ', '*',
		'*', ' ', ' ', ' ', '*',
		'*', ' ', ' ', ' ', '*',
		'*', ' ', ' ', ' ', '*',
		'*', '*', '*', '*', '*' };
	char one[35] = {' ', ' ', ' ', ' ', '*',
		' ', ' ', ' ', ' ', '*',
		' ', ' ', ' ', ' ', '*',
		' ', ' ', ' ', ' ', '*',
		' ', ' ', ' ', ' ', '*',
		' ', ' ', ' ', ' ', '*',
		' ', ' ', ' ', ' ', '*' };
	char two[35] = { '*', '*', '*', '*', '*',
		' ', ' ', ' ', ' ', '*',
		' ', ' ', ' ', ' ', '*',
		'*', '*', '*', '*', '*',
		'*', ' ', ' ', ' ', ' ',
		'*', ' ', ' ', ' ', ' ',
		'*', '*', '*', '*', '*' };
	char three[35] = { '*', '*', '*', '*', '*',
		' ', ' ', ' ', ' ', '*',
		' ', ' ', ' ', ' ', '*',
		'*', '*', '*', '*', '*',
		' ', ' ', ' ', ' ', '*',
		' ', ' ', ' ', ' ', '*',
		'*', '*', '*', '*', '*' };
	char four[35] = { '*', ' ', ' ', ' ', '*',
		'*', ' ', ' ', ' ', '*',
		'*', ' ', ' ', ' ', '*',
		'*', '*', '*', '*', '*',
		' ', ' ', ' ', ' ', '*',
		' ', ' ', ' ', ' ', '*',
		' ', ' ', ' ', ' ', '*' };
	char five[35] = { '*', '*', '*', '*', '*',
		'*', ' ', ' ', ' ', ' ',
		'*', ' ', ' ', ' ', ' ',
		'*', '*', '*', '*', '*',
		' ', ' ', ' ', ' ', '*',
		' ', ' ', ' ', ' ', '*',
		'*', '*', '*', '*', '*' };
	char six[35] = { '*', '*', '*', '*', '*',
		'*', ' ', ' ', ' ', ' ',
		'*', ' ', ' ', ' ', ' ',
		'*', '*', '*', '*', '*',
		'*', ' ', ' ', ' ', '*',
		'*', ' ', ' ', ' ', '*',
		'*', '*', '*', '*', '*' };
	char seven[35] = { '*', '*', '*', '*', '*',
		'*', ' ', ' ', ' ', '*',
		'*', ' ', ' ', ' ', '*',
		' ', ' ', ' ', ' ', '*',
		' ', ' ', ' ', ' ', '*',
		' ', ' ', ' ', ' ', '*',
		' ', ' ', ' ', ' ', '*' };
	char eight[35] = { '*', '*', '*', '*', '*',
		'*', ' ', ' ', ' ', '*',
		'*', ' ', ' ', ' ', '*',
		'*', '*', '*', '*', '*',
		'*', ' ', ' ', ' ', '*',
		'*', ' ', ' ', ' ', '*',
		'*', '*', '*', '*', '*' };
	char nine[35] = { '*', '*', '*', '*', '*',
		'*', ' ', ' ', ' ', '*',
		'*', ' ', ' ', ' ', '*',
		'*', '*', '*', '*', '*',
		' ', ' ', ' ', ' ', '*',
		' ', ' ', ' ', ' ', '*',
		'*', '*', '*', '*', '*' };

	void printNum(char num[], int col) {
		for(int i = col*5; i < col*5+5; i++) {
			printf("%c", num[i]);
		}
		printf(" ");
	}

	void checkNum(char num[], int size, int i) {
		for(int idx = 0; idx < size; idx++) {
			switch(num[idx]) {
				case 48: printNum(zero, i); break;
				case 49: printNum(one, i); break;
				case 50: printNum(two, i); break;
				case 51: printNum(three, i); break;
				case 52: printNum(four, i); break;
				case 53: printNum(five, i); break;
				case 54: printNum(six, i); break;
				case 55: printNum(seven, i); break;
				case 56: printNum(eight, i); break;
				case 57: printNum(nine, i); break;
			}
		}
	}

#elif defined P09_02

#elif defined P09_03

#endif // #if defined P09_01

	int Practice_09(int argc, char* args[]) {
#if defined P09_01
		char inputNum[50];

		printf("숫자 입력 : ");
		scanf("%s", inputNum);

		int cnt = 0;
		while(inputNum[cnt] != '\0') {
			cnt++;
		}

		printf("\n=====> 결과 <=====\n");
		
		for(int row = 0; row < 7; row++) {
			checkNum(inputNum, cnt, row);
			printf("\n");
		}

		return 0;
		
#elif defined P09_02

#elif defined P09_03

#endif // #if defined P09_01

		return 0;
	}
}
