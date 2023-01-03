//#define E06_SINGLE
#define E06_MULTI

#include "Example_06.h"

namespace E06 {
	int Example_06(int argc, char* args[]) {
#if defined E06_SINGLE
		int anVals01[5] = {
			1, 2, 3, 4, 5
		};

		/*
		 * 배열 길이보다 초기화 값의 개수가 적을 경우 명시되어 있는 값을 배열의 각 요소에 순서대로 할당한 후 나머지 요소는 해당
		 * 자료형의 기본값으로 할당된다. (Ex. int 일 경우 0 으로 초기화)
		 */
		int anVals02[5] = {
			1, 2, 3
		};

		/*
		 * 배열을 선언 할 때 해당 배열의 길이를 명시하지 않을 경우 반드시 초기화를 통해 컴파일러가 해당 배열의 길이를 계산 할 수
		 * 있도록 해야한다. (즉, 컴파일러는 배열의 길이 명시되어 있지 않을 경우 초기화 값의 개수를 통해 배열 길이를 자동으로
		 * 계산한다.)
		 */
		int anVals03[] = {
			1, 2, 3
		};

		/*
		 * sizeof 키워드를 사용하면 배열 크기를 계산하는 것이 가능하다. 배열의 크기는 배열 요소 크기 * 배열 길이 이기 때문에
		 * 이를 활용하면 배열의 길이를 계산하는 것이 가능하다.
		 * 
		 * Ex)
		 * 배열 크기 = 배열 요소 크기 * 배열 길이
		 * 배열 길이 = 배열 크기 / 배열 요소 크기
		 */
		int nSize01 = sizeof(anVals01) / sizeof(anVals01[0]);
		int nSize02 = sizeof(anVals02) / sizeof(anVals02[0]);
		int nSize03 = sizeof(anVals03) / sizeof(anVals03[0]);

		printf("=====> 배열 - 1 <=====\n");

		for(int i = 0; i < nSize01; ++i) {
			printf("%d, ", anVals01[i]);
		}

		printf("\n\n=====> 배열 - 2 <=====\n");

		for(int i = 0; i < nSize02; ++i) {
			printf("%d, ", anVals02[i]);
		}

		printf("\n\n=====> 배열 - 3 <=====\n");

		for(int i = 0; i < nSize03; ++i) {
			printf("%d, ", anVals03[i]);
		}
#elif defined E06_MULTI
		int anVals01[3][3] = {
			{ 1, 2, 3 },
			{ 4, 5, 6 },
			{ 7, 8, 9 }
		};

		/*
		 * 2 차원 이상의 배열을 초기화 할 경우 { } 기호를 통해 하위 차원을 명시하는 것이 가능하다. 따라서, 특정 차원에 존재하는
		 * 것을 명시적으로 초기화하는 것이 가능하다.
		 */
		int anVals02[3][3] = {
			{ 1 }, { 2 }, { 3 }
		};

		/*
		 * 2 차원 이상의 배열을 초기화 할 때 하위 차원을 명시하지 않을 경우 해당 배열의 기준에 맞춰서 순서대로 값이 할당된다.
		 * (즉, 행 기준 배열 일 경우에는 행 순서로 초기화 값이 할당되며 열 기준 배열 일 경우에는 열 순서로 초기화 값이 할당된다.)
		 */
		int anVals03[3][3] = {
			1, 2, 3, 4
		};

		/*
		 * 2 차원 이상의 배열도 1 차원 배열과 마찬가지로 배열 길이를 생략하는 것이 가능하다. 단, 2 차원 이상 배열에서 배열 길이를
		 * 생략 할 경우 반드시 하위 차원 배열의 길이는 명시해줘야한다. (즉, 컴파일러는 명시 된 초기화 값 개수와 하위 차원 배열
		 * 길이를 통해 해당 차원 배열의 길이를 자동으로 계산한다.)
		 */
		int anVals04[][3] = {
			1, 2, 3
		};

		/*
		 * 다차원 배열은 하위 차원 배열을 요소로 지닌 배열을 의미한다. (즉, 2 차원 배열은 1 차원 배열을 요소로 지닌 배열을 의미
		 * 한다.)
		 * 
		 * 따라서, 해당 배열의 길이는 하위 차원 배열의 크기를 활용해서 계산하는 것이 가능하다.
		 * 
		 * Ex)
		 * 행 개수 = 2 차원 배열 크기 / 1 차원 배열 크기
		 * 열 개수 = 1 차원 배열 크기 / 배열 요소 크기
		 */
		int nNumRows01 = sizeof(anVals01) / sizeof(anVals01[0]);
		int nNumCols01 = sizeof(anVals01[0]) / sizeof(anVals01[0][0]);

		int nNumRows02 = sizeof(anVals02) / sizeof(anVals02[0]);
		int nNumCols02 = sizeof(anVals02[0]) / sizeof(anVals02[0][0]);

		int nNumRows03 = sizeof(anVals03) / sizeof(anVals03[0]);
		int nNumCols03 = sizeof(anVals03[0]) / sizeof(anVals03[0][0]);

		int nNumRows04 = sizeof(anVals04) / sizeof(anVals04[0]);
		int nNumCols04 = sizeof(anVals04[0]) / sizeof(anVals04[0][0]);

		printf("=====> 배열 - 1 <=====\n");

		for(int i = 0; i < nNumRows01; ++i) {
			for(int j = 0; j < nNumCols01; ++j) {
				printf("%d, ", anVals01[i][j]);
			}

			printf("\n");
		}

		printf("\n=====> 배열 - 2 <=====\n");

		for(int i = 0; i < nNumRows02; ++i) {
			for(int j = 0; j < nNumCols02; ++j) {
				printf("%d, ", anVals02[i][j]);
			}

			printf("\n");
		}

		printf("\n=====> 배열 - 3 <=====\n");

		for(int i = 0; i < nNumRows03; ++i) {
			for(int j = 0; j < nNumCols03; ++j) {
				printf("%d, ", anVals03[i][j]);
			}

			printf("\n");
		}

		printf("\n=====> 배열 - 4 <=====\n");

		for(int i = 0; i < nNumRows04; ++i) {
			for(int j = 0; j < nNumCols04; ++j) {
				printf("%d, ", anVals04[i][j]);
			}

			printf("\n");
		}
#endif // #if defined E06_SINGLE

		return 0;
	}
}
