#include "Solve_08.h"

//#define S08_01
//#define S08_02
#define S08_03

namespace S08 {
#if defined S08_01
	/** 오름차순으로 비교한다 */
	int CompareByAscending(int a_nLhs, int a_nRhs) {
		return a_nLhs - a_nRhs;
	}

	/** 내림차순으로 비교한다 */
	int CompareByDescending(int a_nLhs, int a_nRhs) {
		return a_nRhs - a_nLhs;
	}

	/** 값을 정렬한다 */
	void SortVals(int a_pnVals[], int a_nSize, int(*a_pfnCompare)(int, int)) {
		for(int i = 1; i < a_nSize; ++i) {
			int j = 0;
			int nCompareVal = a_pnVals[i];

			for(j = i - 1; j >= 0 && a_pfnCompare(a_pnVals[j], nCompareVal) > 0; --j) {
				a_pnVals[j + 1] = a_pnVals[j];
			}

			a_pnVals[j + 1] = nCompareVal;
		}
	}

	/** 값을 출력한다 */
	void PrintVals(int a_pnVals[], int a_nSize) {
		for(int i = 0; i < a_nSize; ++i) {
			printf("%d, ", a_pnVals[i]);
		}

		printf("\n");
	}
#elif defined S08_02
	/** 오름차순으로 비교한다 */
	int CompareByAscending(int a_nLhs, int a_nRhs) {
		return a_nLhs - a_nRhs;
	}

	/** 값을 정렬한다 */
	void SortVals(int a_pnVals[], int a_nSize, int(*a_pfnCompare)(int, int)) {
		for(int i = 1; i < a_nSize; ++i) {
			int j = 0;
			int nCompareVal = a_pnVals[i];

			for(j = i - 1; j >= 0 && a_pfnCompare(a_pnVals[j], nCompareVal) > 0; --j) {
				a_pnVals[j + 1] = a_pnVals[j];
			}

			a_pnVals[j + 1] = nCompareVal;
		}
	}

	/** 값을 탐색한다 */
	int FindVal(int a_pnVals[], int a_nSize, int a_nVal) {
		int nLeft = 0;
		int nRight = a_nSize - 1;

		while(nLeft <= nRight) {
			int nMid = (nLeft + nRight) / 2;

			// 값이 존재 할 경우
			if(a_pnVals[nMid] == a_nVal) {
				return nMid;
			} else {
				// 오른쪽에 값이 존재 할 경우
				if(a_nVal > a_pnVals[nMid]) {
					nLeft = nMid + 1;
				} else {
					nRight = nMid - 1;
				}
			}
		}

		return -1;
	}
#elif defined S08_03
	typedef void (*SWAP_FUNC)(int*, int*, int*);

	/** 값을 왼쪽 방향으로 교환한다 */
	void SwapByLeft(int* a_pnVal01, int* a_pnVal02, int* a_pnVal03) {
		int nTemp = *a_pnVal01;
		*a_pnVal01 = *a_pnVal02;
		*a_pnVal02 = *a_pnVal03;
		*a_pnVal03 = nTemp;
	}

	/** 값을 오른쪽 방향으로 교환한다 */
	void SwapByRight(int* a_pnVal01, int* a_pnVal02, int* a_pnVal03) {
		int nTemp = *a_pnVal03;
		*a_pnVal03 = *a_pnVal02;
		*a_pnVal02 = *a_pnVal01;
		*a_pnVal01 = nTemp;
	}

	/** 교환 함수를 반환한다 */
	SWAP_FUNC GetSwapFunc(int a_nSel) {
		switch(a_nSel) {
			case 0: return SwapByLeft;
			case 1: return SwapByRight;
		}

		return NULL;
	}
#endif // #if defined S08_01

	int Solve_08(int argc, char* args[]) {
#if defined S08_01
		int anVals[10] = { 0 };
		const int nSize = sizeof(anVals) / sizeof(anVals[0]);

		for(int i = 0; i < nSize; ++i) {
			anVals[i] = rand() % 100;
		}

		printf("=====> 배열 요소 <=====\n");
		PrintVals(anVals, nSize);

		SortVals(anVals, nSize, CompareByAscending);

		printf("\n=====> 배열 요소 - 오름차순 정렬 후 <=====\n");
		PrintVals(anVals, nSize);

		SortVals(anVals, nSize, CompareByDescending);

		printf("\n=====> 배열 요소 - 내림차순 정렬 후 <=====\n");
		PrintVals(anVals, nSize);
#elif defined S08_02
		int anVals[10] = { 0 };
		const int nSize = sizeof(anVals) / sizeof(anVals[0]);

		for(int i = 0; i < nSize; ++i) {
			anVals[i] = rand() % 100;
		}

		printf("=====> 배열 요소 <=====\n");

		for(int i = 0; i < nSize; ++i) {
			printf("%d, ", anVals[i]);
		}

		int nVal = 0;

		printf("\n\n정수 입력 : ");
		scanf("%d", &nVal);

		SortVals(anVals, nSize, CompareByAscending);
		printf("결과 : %s\n", (FindVal(anVals, nSize, nVal) >= 0) ? "탐색 성공" : "탐색 실패");
#elif defined S08_03
		int nVal01 = 10;
		int nVal02 = 20;
		int nVal03 = 30;

		int nSel = 0;

		printf("정수 (0 or 1) 입력 : ");
		scanf("%d", &nSel);

		SWAP_FUNC pfnSwapFunc = GetSwapFunc(nSel);

		// 교환 함수가 존재 할 경우
		if(pfnSwapFunc != NULL) {
			printf("=====> 교환 전 <=====\n");
			printf("%d %d %d\n", nVal01, nVal02, nVal03);

			pfnSwapFunc(&nVal01, &nVal02, &nVal03);

			printf("\n=====> 교환 후 <=====\n");
			printf("%d %d %d\n", nVal01, nVal02, nVal03);
		}
#endif // #if defined S08_01

		return 0;
	}
}
