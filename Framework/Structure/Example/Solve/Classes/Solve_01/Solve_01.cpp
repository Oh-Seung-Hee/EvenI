//#define S01_01
#define S01_02

#include "Solve_01.h"
#include "../Global/Utility/Structure/Stack.h"

#define MAX_NUM_VALS			(15)

namespace S01 {
#if defined S01_01

#elif defined S01_02
	/** 연산자 우선 순위를 반환한다 */
	int GetPriority(char a_chOperator) {
		switch(a_chOperator) {
			case '+': case '-': return 2;
			case '*': case '/': return 1;
		}

		return 3;
	}

	/** 중위 -> 후위 표기법으로 변환한다 */
	void ConvertInToPostfix(char* a_pszSrc, char* a_pszDest) {
		Global::STStack stStack;
		Global::SInit(&stStack);

		for(int i = 0; i < strlen(a_pszSrc); ++i) {
			// 공백 일 경우
			if(isspace(a_pszSrc[i])) {
				continue;
			}

			// 숫자 일 경우
			if(a_pszSrc[i] >= '0' && a_pszSrc[i] <= '9') {
				sprintf(a_pszDest, "%s%c", a_pszDest, a_pszSrc[i]);
			} else {
				// 닫힌 괄호 일 경우
				if(a_pszSrc[i] == ')') {
					while(!Global::SIsEmpty(&stStack)) {
						char chOperator = (char)Global::SPop(&stStack);

						// 열린 괄호 일 경우
						if(chOperator == '(') {
							break;
						}

						sprintf(a_pszDest, "%s%c", a_pszDest, chOperator);
					}
				} else {
					while(!Global::SIsEmpty(&stStack)) {
						int nPriority01 = GetPriority(a_pszSrc[i]);
						int nPriority02 = GetPriority((char)Global::SPeek(&stStack));

						// 현재 연산자 우선 순위가 높을 경우
						if(nPriority01 < nPriority02) {
							break;
						}

						sprintf(a_pszDest, "%s%c", a_pszDest, (char)Global::SPop(&stStack));
					}

					Global::SPush(&stStack, (void*)a_pszSrc[i]);
				}
			}
		}

		while(!Global::SIsEmpty(&stStack)) {
			sprintf(a_pszDest, "%s%c", a_pszDest, (char)Global::SPop(&stStack));
		}

		Global::SDestroy(&stStack);
	}
#endif // #if defined S01_01

	int Solve_01(int argc, char* args[]) {
#if defined S01_01
		Global::STStack stStack;
		Global::SInit(&stStack);

		printf("=====> 데이터 입력 순서 <=====\n");

		for(int i = 0; i < MAX_NUM_VALS; ++i) {
			int nVal = rand() % 100;
			Global::SPush(&stStack, (void*)nVal);

			printf("%d, ", nVal);
		}

		printf("\n\n=====> 데이터 출력 순서 <=====\n");

		while(!Global::SIsEmpty(&stStack)) {
			printf("%d, ", (int)Global::SPop(&stStack));
		}

		printf("\n");
		Global::SDestroy(&stStack);
#elif defined S01_02
		char szStr[100] = "";
		char szResult[100] = "";

		printf("수식 입력 : ");
		fgets(szStr, sizeof(szStr), stdin);

		// 개행 문자가 존재 할 경우
		if(szStr[strlen(szStr) - 1] == '\n') {
			szStr[strlen(szStr) - 1] = '\0';
		}

		ConvertInToPostfix(szStr, szResult);
		printf("결과 : %s\n", szResult);
#endif // #if defined S01_01

		return 0;
	}
}
