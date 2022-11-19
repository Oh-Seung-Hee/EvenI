#include "Example_07.h"

//#define E07_FUNC_01
//#define E07_FUNC_02
//#define E07_FUNC_03
#define E07_FUNC_04

namespace E07 {
#if defined E07_FUNC_01
	/** 덧셈 결과를 반환한다 */
	int GetSumVal(int a_nLhs, int a_nRhs) {
		return a_nLhs + a_nRhs;
	}

	/** 뺄셈 결과를 반환한다 */
	int GetSubVal(int a_nLhs, int a_nRhs) {
		return a_nLhs - a_nRhs;
	}

	/** 곱셈 결과를 반환한다 */
	int GetMulVal(int a_nLhs, int a_nRhs) {
		return a_nLhs * a_nRhs;
	}

	/** 나눗셈 결과를 반환한다 */
	float GetDivVal(int a_nLhs, int a_nRhs) {
		return a_nLhs / (float)a_nRhs;
	}
#elif defined E07_FUNC_02
	int g_nVal01 = 0;
	static int g_nVal02 = 0;

	/** 값을 증가시킨다 */
	void IncrVal(int a_nVal) {
		int nVal01 = 0;
		static int nVal02 = 0;

		nVal01 += a_nVal;
		nVal02 += a_nVal;

		g_nVal01 += a_nVal;
		g_nVal02 += a_nVal;

		printf("\n=====> 결과 <=====\n");
		printf("지역 변수: %d, %d\n", nVal01, nVal02);
		printf("전역 변수: %d, %d\n\n", g_nVal01, g_nVal02);
	}
#elif defined E07_FUNC_03
	/** 값을 설정한다 */
	void SetupVals(int a_pnVals[], int a_nSize) {
		for(int i = 0; i < a_nSize; ++i) {
			a_pnVals[i] = rand() % 100;
		}
	}
	
	/** 합계를 반환한다 */
	int GetSumVal(int a_pnVals[], int a_nSize) {
		int nSumVal = 0;

		for(int i = 0; i < a_nSize; ++i) {
			nSumVal += a_pnVals[i];
		}

		return nSumVal;
	}
#elif defined E07_FUNC_04
	/** 팩토리얼을 반환한다 */
	int GetFactorial(int a_nVal) {
		// 값이 우효하지 않을 경우
		if(a_nVal <= 1) {
			return 1;
		}

		return a_nVal * GetFactorial(a_nVal - 1);
	}

	/** 하노이 탑을 출력한다 */
	void PrintHanoiTower(int a_nNum, int a_nSrc, int a_nDest) {
		// 숫자가 유효 할 경우
		if(a_nNum > 0) {
			PrintHanoiTower(a_nNum - 1, a_nSrc, 6 - (a_nSrc + a_nDest));

			printf("%d : %d -> %d\n", a_nNum, a_nSrc, a_nDest);
			PrintHanoiTower(a_nNum - 1, 6 - (a_nSrc + a_nDest), a_nDest);
		}
	}
#endif // #if defined E07_FUNC_01

	int Example_07(int argc, char* args[]) {
#if defined E07_FUNC_01
		int nLhs = 0;
		int nRhs = 0;

		printf("정수 (2 개) 입력 : ");
		scanf("%d %d", &nLhs, &nRhs);

		printf("\n=====> 결과 <=====\n");
		printf("%d + %d = %d\n", nLhs, nRhs, GetSumVal(nLhs, nRhs));
		printf("%d - %d = %d\n", nLhs, nRhs, GetSubVal(nLhs, nRhs));
		printf("%d * %d = %d\n", nLhs, nRhs, GetMulVal(nLhs, nRhs));
		printf("%d / %d = %f\n", nLhs, nRhs, GetDivVal(nLhs, nRhs));
#elif defined E07_FUNC_02
		int nVal = 0;

		{
			int nVal = 0;
			nVal = 10;
		}

		printf("지역 변수: %d\n\n", nVal);

		do {
			printf("정수 입력 : ");
			scanf("%d", &nVal);

			// 값이 유효 할 경우
			if(nVal > 0) {
				IncrVal(nVal);
			}
		} while(nVal > 0);
#elif defined E07_FUNC_03
		int anVals[10] = { 0 };
		SetupVals(anVals, sizeof(anVals) / sizeof(anVals[0]));

		printf("=====> 배열 요소 <=====\n");

		for(int i = 0; i < sizeof(anVals) / sizeof(anVals[0]); ++i) {
			printf("%d, ", anVals[i]);
		}

		printf("\n\n합계: %d\n", GetSumVal(anVals, sizeof(anVals) / sizeof(anVals[0])));
#elif defined E07_FUNC_04
		PrintHanoiTower(4, 1, 3);
#endif			// #if defined E07_FUNC_01

		return 0;
	}
}
