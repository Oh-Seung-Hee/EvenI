#include "Example_08.h"

//#define E08_PTR_01
//#define E08_PTR_02
#define E08_PTR_03

namespace E08 {
#if defined E08_PTR_01

#elif defined E08_PTR_02
	/** 값을 교환한다 */
	void Swap(int* a_pnVal01, int* a_pnVal02) {
		int nTemp = *a_pnVal01;
		*a_pnVal01 = *a_pnVal02;
		*a_pnVal02 = nTemp;
	}
#elif defined E08_PTR_03
	/** 값을 설정한다 */
	void SetupVals(int* a_pnVals, int a_nSize) {
		for(int i = 0; i < a_nSize; ++i) {
			a_pnVals[i] = rand() % 100;
		}
	}
#endif // #if defined E08_PTR_01

	int Example_08(int argc, char* args[]) {
#if defined E08_PTR_01
		int nVal01 = 0;
		int nVal02 = 0;

		int* pnVal01 = &nVal01;
		int* pnVal02 = &nVal02;

		*pnVal01 = 10;
		*pnVal02 = 20;

		printf("=====> 결과 - 1 <=====\n");
		printf("Value 1: %d, %d, %p, %p\n", nVal01, *pnVal01, &nVal01, pnVal01);
		printf("Value 2: %d, %d, %p, %p\n", nVal02, *pnVal02, &nVal02, pnVal02);

		pnVal01 = &nVal02;
		pnVal02 = &nVal01;

		printf("\n=====> 결과 - 2 <=====\n");
		printf("Value 1: %d, %d, %p, %p\n", nVal01, *pnVal01, &nVal01, pnVal01);
		printf("Value 2: %d, %d, %p, %p\n", nVal02, *pnVal02, &nVal02, pnVal02);
#elif defined E08_PTR_02
		int nVal01 = 0;
		int nVal02 = 0;

		printf("정수 (2 개) 입력 : ");
		scanf("%d %d", &nVal01, &nVal02);

		printf("\n=====> 교환 전 <=====\n");
		printf("%d, %d\n", nVal01, nVal02);

		Swap(&nVal01, &nVal02);

		printf("\n=====> 교환 후 <=====\n");
		printf("%d, %d\n", nVal01, nVal02);
#elif defined E08_PTR_03
		int nVal = 0;
		int anVals[5] = { 0 };

		const int* pnConstVal01 = &nVal;
		int* const pnConstVal02 = &nVal;
		const int* const pnConstVal03 = &nVal;

		SetupVals(anVals, sizeof(anVals) / sizeof(anVals[0]));
		printf("=====> 배열 요소 <=====\n");

		for(int i = 0; i < sizeof(anVals) / sizeof(anVals[0]); ++i) {
			printf("%d, ", *(anVals + i));
		}

		printf("\n");
#endif // #if defined E08_PTR_01

		return 0;
	}
}
