#include "Practice_01.h"

#define P01_01

namespace P01 {
	int Practice_01(int argc, char* args[]) {
#if defined P01_01
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
