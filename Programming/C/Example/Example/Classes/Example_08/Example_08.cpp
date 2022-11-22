#include "Example_08.h"

#define E08_PTR_01
#define E08_PTR_02
#define E08_PTR_03
#define E08_PTR_04
#define E08_PTR_05
#define E08_PTR_06

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
#elif defined E08_PTR_04
	/** 주소를 교환한다 */
	void Swap(int** a_pnPtr01, int** a_pnPtr02) {
		int* pnTemp = *a_pnPtr01;
		*a_pnPtr01 = *a_pnPtr02;
		*a_pnPtr02 = pnTemp;
	}
#elif defined E08_PTR_05
	/** 값을 설정한다 */
	void SetupVals(int* a_pnVals, int a_nSize) {
		for(int i = 0; i < a_nSize; ++i) {
			a_pnVals[i] = i;
		}
	}

	/** 값을 설정한다 */
	void SetupVals(int(*a_pnVals)[5], int a_nNumRows) {
		for(int i = 0; i < a_nNumRows; ++i) {
			for(int j = 0; j < 5; ++j) {
				a_pnVals[i][j] = (i * 5) + j;
			}
		}
	}

	/** 값을 설정한다 */
	void SetupVals(int* a_pnVals, int a_nNumRows, int a_nNumCols) {
		for(int i = 0; i < a_nNumRows; ++i) {
			for(int j = 0; j < a_nNumCols; ++j) {
				a_pnVals[(i * a_nNumCols) + j] = (i * a_nNumCols) + j;
			}
		}
	}
#elif defined E08_PTR_06
	typedef int (*CALC_FUNC)(int, int);

	/** 덧셈 결과를 반환한다 */
	int GetSumVal(int a_nLhs, int a_nRhs) {
		return a_nLhs + a_nRhs;
	}

	/** 뺄셈 결과를 반환한다 */
	int GetSubVal(int a_nLhs, int a_nRhs) {
		return a_nLhs - a_nRhs;
	}

	/** 수식 함수를 반환하다 */
	CALC_FUNC GetCalcFunc(char a_chOperator) {
		switch(a_chOperator) {
			case '+': return GetSumVal;
			case '-': return GetSubVal;
		}

		return NULL;
	}

	/** 오름차순으로 비교한다 */
	int CompareByAscending(const void* a_pvPtr01, const void* a_pvPtr02) {
		const int* pnPtr01 = (const int*)a_pvPtr01;
		const int* pnPtr02 = (const int*)a_pvPtr02;

		return *pnPtr01 - *pnPtr02;
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
#elif defined E08_PTR_04
		int nVal01 = 0;
		int nVal02 = 0;

		int* pnPtr01 = &nVal01;
		int* pnPtr02 = &nVal02;

		printf("정수 (2 개) 입력 : ");
		scanf("%d %d", &nVal01, &nVal02);

		printf("\n=====> 교환 전 <=====\n");
		printf("Value: %d, %d\n", nVal01, nVal02);
		printf("Pointer: %d (%p), %d (%p)\n", *pnPtr01, pnPtr01, *pnPtr02, pnPtr02);

		Swap(&pnPtr01, &pnPtr02);

		printf("\n=====> 교환 후 <=====\n");
		printf("Value: %d, %d\n", nVal01, nVal02);
		printf("Pointer: %d (%p), %d (%p)\n", *pnPtr01, pnPtr01, *pnPtr02, pnPtr02);
#elif defined E08_PTR_05
		int anVals01[5] = { 0 };
		int anVals02[5][5] = { 0 };

		SetupVals(anVals01, sizeof(anVals01) / sizeof(anVals01[0]));
		SetupVals(anVals02, sizeof(anVals02) / sizeof(anVals02[0]));

		printf("=====> 배열 요소 - 1 <=====\n");

		for(int i = 0; i < sizeof(anVals01) / sizeof(anVals01[0]); ++i) {
			printf("%d, ", anVals01[i]);
		}

		printf("\n\n=====> 배열 요소 - 2 <=====\n");

		for(int i = 0; i < sizeof(anVals02) / sizeof(anVals02[0][0]); ++i) {
			int nRow = i / (sizeof(anVals02[0]) / sizeof(anVals02[0][0]));
			int nCol = i % (sizeof(anVals02[0]) / sizeof(anVals02[0][0]));

			printf("%2d, ", anVals02[nRow][nCol]);

			// 마지막 열 일 경우
			if(nCol >= (sizeof(anVals02[0]) / sizeof(anVals02[0][0])) - 1) {
				printf("\n");
			}
		}

		printf("\n");
#elif defined E08_PTR_06
		int nVal01 = 0;
		int nVal02 = 0;

		char chOperator = '\0';

		printf("수식 입력 : ");
		scanf("%d %c %d", &nVal01, &chOperator, &nVal02);

		int(*pfnCalcFunc)(int, int) = GetCalcFunc(chOperator);

		// 함수 포인터가 존재 할 경우
		if(pfnCalcFunc != NULL) {
			printf("%d %c %d = %d\n", nVal01, chOperator, nVal02, pfnCalcFunc(nVal01, nVal02));
		}

		int anVals[10] = { 0 };
		const int nSize = sizeof(anVals) / sizeof(anVals[0]);
		
		for(int i = 0; i < nSize; ++i) {
			anVals[i] = rand() % 100;
		}

		printf("\n=====> 배열 요소 - 정렬 전 <=====\n");

		for(int i = 0; i < nSize; ++i) {
			printf("%d, ", anVals[i]);
		}

		qsort(anVals, nSize, sizeof(anVals[0]), CompareByAscending);
		printf("\n\n=====> 배열 요소 - 정렬 후 <=====\n");

		for(int i = 0; i < nSize; ++i) {
			printf("%d, ", anVals[i]);
		}

		printf("\n");
#endif // #if defined E08_PTR_01

		return 0;
	}
}
