#include "Example_05.h"

//#define E05_LOOP_WHILE
//#define E05_LOOP_FOR
#define E05_LOOP_DO_WHILE

namespace E05 {
	int Example_05(int argc, char* args[]) {
#if defined E05_LOOP_WHILE
		int i = 0;

		/*
		while 반복문 내부에 continue 키워드를 사용 할 경우 해당 반복문이 무한 루프가 되지 않도록 주의해야 될 필요가 있다.
		따라서, 해당 키워드를 사용 할 경우 반드시 반복 조건을 끝내기 위한 구문이 올바르게 처리가 되는지 반드시 확인 할 필요가 있다.

		continue 란?
		- 반복문 내부에서 사용 할 수 있는 키워드이며, 해당 키워드를 사용하면 현재 프로그램 흐름을 생략하고 다음 흐름으로 이동시키는
		특징이 존재한다. (즉, 해당 키워드를 활용하면 특정 조건에 해당하는 구문에 대한 반복을 생략하는 것이 가능하다.)
		*/
		while(i < 10) {
			if(i % 2 == 0) {
				/*
				해당 구문을 생략 할 경우 반복 조건을 거짓으로 만들 수 없기 때문에 결과적으로 무한 루프가 되는 문제점이 발생한다.
				*/
				++i;

				continue;
			}

			printf("%d, ", i);
			++i;
		}
#elif defined E05_LOOP_FOR
		/*
		for 반복문은 while 반복문과 달리 좀더 안전하게 사용하는 것이 가능하다. 해당 반복문 내부에서 continue 를 사용 할 경우
		while 반복문과 달리 반복을 끝내기 위한 별도의 처리를 해주지 않아도 된다. (즉, continue 키워드에 의해 현재 프로그램 흐름이
		생략되더라도 조건을 끝내기 위한 반복절로 해당 흐름이 이동하기 때문이다.)
		*/
		for(int i = 0; i < 10; ++i) {
			if(i % 2 == 0) {
				continue;
			}

			printf("%d, ", i);
		}
#elif defined E05_LOOP_DO_WHILE
		/*
		do ~ while 반복문은 while, for 반복문과 달리 반복을 끝내기 위한 조건절을 반복 처리를 해야 될 구문을 실행한 후에 처리하기
		때문에 처음부터 반복 조건이 거짓이라고 하더라도 반드시 1 번 이상 실행을 보장한다.

		즉, while, for 반복문은 반복 여부를 처리하는 조건절을 먼저 처리 후 반복 구문을 실행하는 사전 판단 반복문이며, do ~ while
		반복문은 조건절을 반복 구문 후에 처리하는 사후 판단 반복문이다.
		*/
		do {
			printf("do ~ while 반복문을 실행합니다.\n");
		} while(0);
#endif // #if defined E05_LOOP_WHILE

		return 0;
	}
}
