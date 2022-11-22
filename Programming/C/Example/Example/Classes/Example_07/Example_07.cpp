#include "Example_07.h"

//#define E07_FUNC_01
//#define E07_FUNC_02
//#define E07_FUNC_03
#define E07_FUNC_04

/*
정적 전역 변수는 해당 변수에 접근 가능한 범위를 해당 변수가 선언 된 파일 내부로 제한하는 특징이 존재한다. (따라서, 정적 전역
변수를 활용하면 일반적인 전역 변수에 비해 좀 더 안전하게 전역 변수를 활용하는 것이 가능하다.)
*/
int g_nVal01 = 0;
static int g_nVal02 = 0;

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
	/** 값을 증가시킨다 */
	void IncrVal(int a_nVal) {
		/*
		정적 지역 변수는 일반적인 지역 변수와 마찬가지로 해당 변수가 선언 된 지역에서만 접근 가능한 특징이 존재한다. 단, 변수가
		선언 된 지역을 벗어났을 경우 메모리 상에서 사라지는 지역 변수와 달리 메모리 상에 사라지지 않고 계속 존재하는 것이 특징이다.
		*/
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
	/*
	C 는 함수를 호출 할 때 특정 배열을 입력으로 전달 할 경우 반드시 해당 배열의 길이를 같이 전달 할 필요가 있다. 이는, 일반적으로
	배열 자체를 함수의 입력으로 전달하는 것이 불가능하기 때문이다. (즉, 구조체를 통해서만 배열 자체를 입력으로 전달하는 것이
	가능하다.)

	특정 함수에 입력으로 배열을 전달 할 경우 해당 배열의 첫 번째 요소를 가리키는 주소가 전달 되며, 이는 곧 배열을 전달 받은 함수 
	내부에서는 배열의 길이를 계산하는 것이 불가능하다는 것을 의미한다.
	*/
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
	/*
	함수 내부에서 해당 함수를 다시 호출하는 것이 가능하며, 이를 재귀 호출이라고 한다. (즉, 특정 함수에서 해당 함수 자신을 다시
	호출하는 것을 의미한다.)

	따라서, 특정 함수 내부에서 재귀 호출이 이뤄질 경우 반드시 해당 함수 호출을 끝낼 수 있는 구문을 작성 할 필요가 있으며 만약,
	해당 구문을 작성하지 않았을 경우 무한 재귀 호출이 발생한다.
	*/
	/** 팩토리얼을 반환한다 */
	int GetFactorial(int a_nVal) {
		// 값이 유효하지 않을 경우
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
		int nVal = 0;

		printf("정수 입력 : ");
		scanf("%d", &nVal);

		printf("\n=====> 재귀 함수 - 1 <=====\n");
		printf("%d! = %d\n", nVal, GetFactorial(nVal));

		printf("\n정수 입력 : ");
		scanf("%d", &nVal);

		printf("\n=====> 재귀 함수 - 2 <=====\n");
		PrintHanoiTower(nVal, 1, 3);
#endif			// #if defined E07_FUNC_01

		return 0;
	}
}
