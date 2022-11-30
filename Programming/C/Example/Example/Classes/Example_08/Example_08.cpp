#include "Example_08.h"

//#define E08_PTR_01
//#define E08_PTR_02
//#define E08_PTR_03
//#define E08_PTR_04
//#define E08_PTR_05
#define E08_PTR_06

namespace E08 {
#if defined E08_PTR_01

#elif defined E08_PTR_02
	/*
	함수 호출 시 입력 값이 존재 할 경우 해당 값은 명시 된 순서에 따라서 호출 된 함수의 매개 변수에 복사가 이루어진다.
	(즉, 매개 변수는 함수 내부에 선언 된 지역 변수와 동일하기 떄문에 해당 매개 변수의 값을 변경하는 것은 해당 함수의 외부 영역에는
	영향을 미치지 않는다.)
	*/
	/** 값을 교환한다 */
	void Swap(int a_nVal01, int a_nVal02) {
		int nTemp = a_nVal01;
		a_nVal01 = a_nVal02;
		a_nVal02 = nTemp;
	}

	/*
	포인터를 사용하면 외부 영역에 존재하는 지역 변수를 제어하는 것이 가능하다. (즉, 지역 변수가 지니고 있는 한계점을 극복하는
	것이 가능하다.) 따라서, 특정 함수가 외부 지역에 존재하는 변수에 값을 변경하기 위해서는 반드시 포인터를 활용해야한다.
	*/
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

	/*
	배열 포인터를 활용하면 2 차원 이상의 배열을 함수의 입력으로 전달하는 것이 가능하다. (단, 배열 포인터에 명시되는 길이는 반드시
	상수로 지정되어야하기 때문에 다양한 크기의 2 차원 배열을 처리하기 위해서는 해당 방식은 효율성이 떨어진다.)

	C 배열 포인터 선언 방법
	- 자료형 + 배열 포인터 이름 + 배열 길이

	Ex)
	int(*pnArrayPtr)[5]		<- 길이가 5 인 배열을 가리키는 배열 포인터
	int(*pnArrayPtr)[10]	<- 길이가 10 인 배열을 가리키는 배열 포인터
	*/
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
	/*
	typedef 키워드는 특정 자료형에 새로운 이름을 추가로 부여하는 역할을 수행한다. (즉, 해당 키워드를 활용하면 데이터의 
	사용처에 맞게 이름을 부여해서 좀 더 가독성을 향상 시키는 것이 가능하다.)

	Ex)
	typedef int stat_t;		<- int 자료형에 stat_t (스탯) 이라는 이름을 추가로 부여한다.

	stat_t nHP = 0;
	stat_t nATK = 0;
	*/
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

	/*
	void 포인터란?
	- 자료형이 명시하지 않은 포인터를 의미한다. (즉, 해당 포인터를 사용하면 어떠한 자료형의 메모리 주소도 가리키는 것이 
	가능하다.)
	*/
	/** 오름차순으로 비교한다 */
	int CompareByAscending(const void* a_pvPtr01, const void* a_pvPtr02) {
		const int* pnPtr01 = (const int*)a_pvPtr01;
		const int* pnPtr02 = (const int*)a_pvPtr02;

		return *pnPtr01 - *pnPtr02;
	}

	/** 내림차순으로 비교한다 */
	int CompareByDescending(const void* a_pvPtr01, const void* a_pvPtr02) {
		const int* pnPtr01 = (const int*)a_pvPtr01;
		const int* pnPtr02 = (const int*)a_pvPtr02;

		return *pnPtr02 - *pnPtr01;
	}
#endif // #if defined E08_PTR_01

	int Example_08(int argc, char* args[]) {
#if defined E08_PTR_01
		int nVal01 = 0;
		int nVal02 = 0;

		/*
		포인터에 특정 변수에 주소를 할당 할 경우 포인터는 해당 변수를 가리키는 상태가 된다.
		*/
		int* pnVal01 = &nVal01;
		int* pnVal02 = &nVal02;

		/*
		* (역참조 연산자) 를 사용하면 특정 메모리 주소에 접근하는 것이 가능하다. (즉, 포인터 변수에는 특정 메모리 주소가
		저장되어있기 때문에 해당 변수에 * (역참조 연산자) 를 사용 할 경우 해당 포인터가 가리키는 메모리에 접근한다는 의미이다.)
		
		PS.
		포인터의 크기는 포인터의 자료형과 무관하게 4 또는 8 바이트이다. (즉, 포인터는 메모리의 주소를 제어하는 기능이기 때문에
		포인터의 크기는 현재 프로그램이 사용하는 주소 체계에 따라 달라진다.)
		*/
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

		/*
		해당 함수는 변수가 지니고 있는 값을 복사해서 함수가 동작하기 때문에 함수를 호출할 때 사용 된 변수에는 전혀 변화가
		발생하지 않는다는 것을 알 수 있다.
		*/
		//Swap(nVal01, nVal02);

		Swap(&nVal01, &nVal02);

		printf("\n=====> 교환 후 <=====\n");
		printf("%d, %d\n", nVal01, nVal02);
#elif defined E08_PTR_03
		int nVal = 0;
		int anVals[5] = { 0 };

		/*
		변수와 마찬가지로 포인터 변수 또한 데이터를 변경 할 수 없는 상수가 존재한다. 단, 포인터 상수는 const 키워드의 위치에
		따라 3 가지 유형이 존재한다.

		포인터 상수 유형
		- const int* pnPtr;				<- 포인터를 통한 데이터의 변경 금지
		- int* const pnPtr;				<- 포인터 자체가 상수 (즉, 포인터가 다른 메모리를 가리키는 것을 금지)
		- const int* const pnPtr;		<- 상수 유형 1 + 상수 유형 2

		PS.
		배열은 상수 포인터 유형 2 번과 유사한 특징이 존재한다. (즉, 배열의 동작 원리는 포인터 연산을 통해 이루어지는 것이기
		때문이다.) 단, 배열과 상수 포인터 유형 2 번은 유사하기는 하지만 동일하지 않다. (즉, 차이점이 존재한다.)

		sizeof 키워드를 통해 배열의 크기를 계산 할 경우 해당 배열의 크기 (배열 요소 크기 * 배열 길이) 가 반환되지만,
		상수 포인터 유형 2 번은 포인터의 크기인 4 또는 8 바이트가 반환된다.
		*/
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

		/*
		포인터는 * (포인터 연산자) 가 명시 된 개수에 따라 차원이 증가하는 특징이 존재한다. (즉, 해당 연산자를 2 개 명시 할 경우
		해당 포인터 변수는 일반적인 포인터 변수가 아니라 포인터를 가리키는 포인터 변수가 된다.)
		*/
		int** pnDPtr01 = &pnPtr01;
		int** pnDPtr02 = &pnPtr02;

		/*
		pnDPtr01 은 포인터를 가리키는 포인터 (즉, 더블 포인터이다.) 이기 때문에 해당 포인터 변수에 역참조를 한번 할 경우
		해당 포인터 변수가 가리키는 포인터에 접근하는 의미가 된다.
		*/
		*pnDPtr01 = pnPtr02;
		*pnDPtr02 = pnPtr01;

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

		/*
		메모리의 주소는 다차원의 개념이 존재하지 않는 1 차원의 형태이기 때문에 다차원 배열은 메모리 주소의 계산을 통해 해당 차원을
		논리적으로 표현하는 것이다. (즉, 다차원 배열의 메모리 주소 계산 방식을 알고 있다면 1 차원 배열을 다차원 배열처럼 활용하는
		것이 가능하다.)
		
		1 차원 주소 => 2 차원 주소로 변환하는 방법
		- 행 : 인덱스 / 열 개수
		- 열 : 인덱스 % 열 개수

		2 치원 주소 => 1 차원 주소로 변환하는 방법
		- 인덱스 : (행 * 열 개수) + 열
		*/
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

		/*
		함수 포인터란?
		- 일반적인 포인터와 달리 함수를 가리키는 포인터를 의미한다. (즉, 함수 포인터를 활용하면 함수의 이름을 통하지 않고 특정
		함수를 호출하는 것이 가능하다.) 따라서, 함수 포인터를 사용하게 되면 특정 함수를 데이터처럼 다른 함수에 입력으로 전달하거나
		반환 받는 것이 가능하다.
		*/
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

		/*
		qsort 함수는 퀵 정렬을 수행하는 C 표준 함수이다. 해당 함수는 어떤 자료형에도 동작하도록 설계 되어있기 때문에 해당 함수를
		활용하면 정렬을 손쉽게 하는 것이 가능하다. 단, qsort 함수 자체는 특정 값의 대/소 여부를 판단하는 것이 불가능하기 떄문에
		해당 연산을 수행해 줄 함수를 입력으로 요구한다. (즉, 특정 함수의 주소를 전달 할 필요가 있다.)
		*/
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
