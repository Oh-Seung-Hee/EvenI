#include "Practice_01.h"

#define P01_01

namespace P01 {
	int Practice_01(int argc, char* args[]) {
#if defined P01_01
		/*
		* Note.
		* 변수 이름은 가능한 의미 있는 이름으로 작성하는 습관을 들이셔야합니다. for 문과 같은 반복문의 조건문에 사용되는
		* 변수를 제외하고는 변수에 이름에는 항상 의미를 부여하는 습관을 들여야 나중에 고생하지 않습니다.
		*/
		char a = 'A', b = 'B', c = 'C', d = 'D';

		char apb[] = "ABCD";
		int i;

		printf("ABCD\n");   // prinrf에서 바로 출력

		printf("%c%c%c%c\n", 'A', 'B', 'C', 'D');   // 문자 출력 이용

		printf("%c%c%c%c\n", a, b, c, d);   // 대입해서 출력

		printf("%x%x%x%x\n", 10, 11, 12, 13);   // 16진수 이용

		printf("%c%c%c%c\n", 65, 66, 67, 68);   // ASCII 코드 이용

		for(i = 0; i < 4; i++) {    // 배열 이용해서 for문으로 출력
			printf("%c", apb[i]);
		}

#endif // #if defined P01_01

		return 0;
	}
}
