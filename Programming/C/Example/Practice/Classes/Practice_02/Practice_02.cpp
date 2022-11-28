#include "Practice_02.h"

#define P02_01

namespace P02 {
	int Practice_02(int argc, char* args[]) {
#if defined P02_01
		int a, b, tmp;

		printf("정수를 입력하세요. \n");
		scanf("%d", &a);
		printf("입력받은 정수 A = %d\n\n", a);
		printf("정수를 입력하세요. \n");
		scanf("%d", &b);
		printf("입력받은 정수 B = %d\n\n", b);

		tmp = a;
		a = b;
		b = tmp;

		printf("두 정수값 교환 결과\n");
		printf("A : %d, B : %d\n", a, b);

#endif // #if defined P02_01

		return 0;
	}
}
