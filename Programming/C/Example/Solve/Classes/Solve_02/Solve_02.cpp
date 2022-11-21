#include "Solve_02.h"

#define S02_01

namespace S02 {
	int Solve_02(int argc, char* args[]) {
#if defined S02_01
		int nVal01 = 0;
		int nVal02 = 0;

		printf("정수 (2 개) 입력 : ");
		scanf("%d %d", &nVal01, &nVal02);

		printf("=====> 교환 전 <=====\n");
		printf("%d, %d\n", nVal01, nVal02);

		int nTemp = nVal01;
		nVal01 = nVal02;
		nVal02 = nTemp;

		printf("\n=====> 교환 후 <=====\n");
		printf("%d, %d\n", nVal01, nVal02);
#endif // #if defined S02_01

		return 0;
	}
}
