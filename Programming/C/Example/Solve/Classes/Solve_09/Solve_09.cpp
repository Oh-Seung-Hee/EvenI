#include "Solve_09.h"

#define S09_01
#define S09_02
#define S09_03

namespace S09 {
#if defined S09_01
	/** 문자열을 출력한다 */
	void PrintDigitStrs(const char* a_pszDigitStr, const char* a_pszStr) {
		for(int i = 0; i < strlen(a_pszStr); ++i) {
			char szStr[10] = "";

			// 숫자 일 경우
			if(isdigit(a_pszStr[i])) {
				int nDigit = a_pszStr[i] - '0';
				strncpy(szStr, a_pszDigitStr + ((nDigit * 5) + nDigit), 5);

				printf("%s ", szStr);
			}
		}

		printf("\n");
	}
#elif defined S09_02
	/** 방향 */
	enum class EDirection {
		NONE = -1,
		LEFT,
		RIGHT,
		MAX_VAL
	};

	/** 값을 설정한다 */
	void SetupVals(int(*a_pnVals)[50], int a_nNumRows, int a_nNumCols) {
		for(int i = 0; i < a_nNumRows; ++i) {
			for(int j = 0; j < a_nNumCols; ++j) {
				a_pnVals[i][j] = (i * a_nNumCols) + j;
			}
		}
	}

	/** 값을 회전한다 */
	void RotateVals(int(*a_pnVals)[50], int a_nNumRows, int a_nNumCols, EDirection a_eDirection) {
		for(int i = 0; i < a_nNumRows / 2; ++i) {
			for(int j = i; j < a_nNumCols - (i + 1); ++j) {
				int nLTRow = i;
				int nLTCol = j;

				int nLBRow = a_nNumRows - (j + 1);
				int nLBCol = i;

				int nRTRow = j;
				int nRTCol = a_nNumRows - (i + 1);

				int nRBRow = a_nNumRows - (i + 1);
				int nRBCol = a_nNumRows - (j + 1);

				// 왼쪽 방향 일 경우
				if(a_eDirection == EDirection::LEFT) {
					int nTemp = a_pnVals[nLTRow][nLTCol];
					a_pnVals[nLTRow][nLTCol] = a_pnVals[nRTRow][nRTCol];
					a_pnVals[nRTRow][nRTCol] = a_pnVals[nRBRow][nRBCol];
					a_pnVals[nRBRow][nRBCol] = a_pnVals[nLBRow][nLBCol];
					a_pnVals[nLBRow][nLBCol] = nTemp;
				} else {
					int nTemp = a_pnVals[nRTRow][nRTCol];
					a_pnVals[nRTRow][nRTCol] = a_pnVals[nLTRow][nLTCol];
					a_pnVals[nLTRow][nLTCol] = a_pnVals[nLBRow][nLBCol];
					a_pnVals[nLBRow][nLBCol] = a_pnVals[nRBRow][nRBCol];
					a_pnVals[nRBRow][nRBCol] = nTemp;
				}
			}
		}
	}

	/** 값을 출력한다 */
	void PrintVals(int(*a_pnVals)[50], int a_nNumRows, int a_nNumCols) {
		for(int i = 0; i < a_nNumRows; ++i) {
			for(int j = 0; j < a_nNumCols; ++j) {
				printf("%4d ", a_pnVals[i][j]);
			}

			printf("\n");
		}
	}
#elif defined S09_03
	/** 값을 설정한다 */
	void SetupVals(char* a_pszStrs[], int a_nSize) {
		for(int i = 0; i < a_nSize; ++i) {
			char szStr[100] = "";
			sprintf(szStr, "%d", rand() % 15);

			a_pszStrs[i] = (char*)malloc(sizeof(char) * (strlen(szStr) + 1));
			strcpy(a_pszStrs[i], szStr);
		}
	}

	/** 값을 치환한다 */
	void ReplaceVals(char* a_pszStrs[], int a_nSize, int a_nIdx) {
		// 치환이 불가능 할 경우
		if(a_nIdx < 0 || a_nIdx >= a_nSize || strcmp(a_pszStrs[a_nIdx], "x") == 0) {
			return;
		}

		int nVal = 0;
		sscanf(a_pszStrs[a_nIdx], "%d", &nVal);

		// 치환 가능 할 경우
		if(nVal < 10) {
			strcpy(a_pszStrs[a_nIdx], "x");

			ReplaceVals(a_pszStrs, a_nSize, a_nIdx - 1);
			ReplaceVals(a_pszStrs, a_nSize, a_nIdx + 1);
		}
	}
#endif // #if defined S09_01

	int Solve_09(int argc, char* args[]) {
#if defined S09_01
		const char* apszDigitStrs[] = {
			"*****     * ***** ***** *   * ***** ***** ***** ***** *****",
			"*   *     *     *     * *   * *     *         * *   * *   *",
			"*   *     *     *     * *   * *     *         * *   * *   *",
			"*   *     * ***** ***** ***** ***** *****     * ***** *****",
			"*   *     * *         *     *     * *   *     * *   *     *",
			"*   *     * *         *     *     * *   *     * *   *     *",
			"*****     * ***** *****     * ***** *****     * ***** *****"
		};

		char szStr[100] = "";

		printf("숫자 입력 : ");
		scanf("%s", szStr);

		for(int i = 0; i < sizeof(apszDigitStrs) / sizeof(apszDigitStrs[0]); ++i) {
			PrintDigitStrs(apszDigitStrs[i], szStr);
		}
#elif defined S09_02
		int nNumRows = 0;
		int nNumCols = 0;

		int anVals[50][50] = { 0 };

		printf("2 차원 배열 크기 입력 : ");
		scanf("%d %d", &nNumRows, &nNumCols);

		SetupVals(anVals, nNumRows, nNumCols);

		printf("=====> 배열 요소 <=====\n");
		PrintVals(anVals, nNumRows, nNumCols);

		EDirection eDirection = EDirection::NONE;

		printf("\n회전 방향 입력 : ");
		scanf("%d", &eDirection);

		RotateVals(anVals, nNumRows, nNumCols, eDirection);

		printf("\n=====> 배열 요소 - 회전 후 <=====\n");
		PrintVals(anVals, nNumRows, nNumCols);
#elif defined S09_03
		char* apszStrs[20];
		const int nSize = sizeof(apszStrs) / sizeof(apszStrs[0]);

		SetupVals(apszStrs, nSize);
		printf("=====> 배열 요소 <=====\n");

		for(int i = 0; i < nSize; ++i) {
			printf("%s, ", apszStrs[i]);
		}

		int nIdx = 0;

		printf("\n\n위치 입력 : ");
		scanf("%d", &nIdx);

		ReplaceVals(apszStrs, nSize, nIdx);
		printf("\n=====> 배열 요소 - 치환 후 <=====\n");

		for(int i = 0; i < nSize; ++i) {
			printf("%s, ", apszStrs[i]);
		}

		for(int i = 0; i < nSize; ++i) {
			free(apszStrs[i]);
		}

		printf("\n");
#endif // #if defined S09_01

		return 0;
	}
}
