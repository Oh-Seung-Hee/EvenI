//#define E04_CONDITION_IF_ELSE
#define E04_CONDITION_SWITCH_CASE

#include "Example_04.h"

namespace E04 {
	int Example_04(int argc, char* args[]) {
#if defined E04_CONDITION_IF_ELSE
		int nScore = 0;

		printf("점수 입력 : ");
		scanf("%d", &nScore);

		if(nScore < 60) {
			printf("F 학점입니다.\n");
		} else {
			if(nScore >= 90) {
				printf("A 학점입니다.\n");
			} else if(nScore >= 80) {
				printf("B 학점입니다.\n");
			} else if(nScore >= 70) {
				printf("C 학점입니다.\n");
			} else {
				printf("D 학점입니다.\n");
			}
		}
#elif defined E04_CONDITION_SWITCH_CASE
		int nScore = 0;

		printf("점수 입력 : ");
		scanf("%d", &nScore);

		/*
		 * switch ~ case 는 if ~ else 조건문과 달리 조건을 만족하는 구문만 실행하는 것이 아니라 조건을 만족하는 구문부터 실행하는
		 * 특징이 존재하기 때문에 특정 조건을 만족하는 구문만 실행하기 위해서는 반드시 break 키워드를 사용해야한다.
		 * 
		 * 또한, switch ~ case 는 if ~ else 조건문과 달리 데이터의 동등 비교만 수행 할 수 있다. 따라서, 특정 조건을 만족하는
		 * 처리 구문이 단순 할 경우 if ~ else 조건문에 비해 빠르게 동작한다는 장점이 존재한다.
		 * 
		 * break 키워드란?
		 * - 제어문 (조건문, 반복문) 내부에서 사용 할 수 있는 키워드이며, 해당 키워드를 사용하면 현재 프로그램 흐름을 생략하고
		 * 해당 흐름을 제어문 밖으로 이동시키는 특징이 존재한다.
		 */
		switch(nScore / 10) {
			case 9: case 10: printf("A 학점입니다.\n"); break;
			case 8: printf("B 학점입니다.\n"); break;
			case 7: printf("C 학점입니다.\n"); break;
			case 6: printf("D 학점입니다.\n"); break;
			default: printf("F 학점입니다.\n"); break;
		}
#endif // #if defined E04_CONDITION_IF_ELSE

		return 0;
	}
}
