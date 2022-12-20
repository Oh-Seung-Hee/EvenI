#include "Solve_06.h"

//#define S06_01
//#define S06_02
#define S06_03

namespace S06 {
#if defined S06_01
	/** 값을 탐색한다 */
	int FindVal(int a_pnVals[], int a_nSize, int a_nVal) {
		for(int i = 0; i < a_nSize; ++i) {
			// 값이 존재 할 경우
			if(a_pnVals[i] == a_nVal) {
				return i;
			}
		}

		return -1;
	}

	/** 정답을 설정한다 */
	void SetupAnswer(int a_pnAnswer[], int a_nSize) {
		int nNumVals = 0;
		memset(a_pnAnswer, 0, sizeof(int) * a_nSize);

		while(nNumVals < a_nSize) {
			int nVal = rand() % 10;

			// 값이 없을 경우
			if(FindVal(a_pnAnswer, nNumVals, nVal) < 0) {
				a_pnAnswer[nNumVals++] = nVal;
			}
		}
	}

	/** 정답 여부를 검사한다 */
	int IsAnswer(int a_pnVals[], int a_pnAnswer[], int a_nSize) {
		for(int i = 0; i < a_nSize; ++i) {
			// 값이 다를 경우
			if(a_pnVals[i] != a_pnAnswer[i]) {
				return 0;
			}
		}

		return 1;
	}
#elif defined S06_02
	/** 보드를 설정한다 */
	void SetupBoard(int(*a_pnBoard)[50], int a_nNumRows, int a_nNumCols) {
		for(int i = 0; i < a_nNumRows; ++i) {
			for(int j = 0; j < a_nNumCols; ++j) {
				a_pnBoard[i][j] = (i * a_nNumCols) + j;
			}
		}
	}

	/** 보드를 재배치한다 */
	void ShuffleBoard(int(*a_pnBoard)[50], int a_nNumRows, int a_nNumCols) {
		for(int i = 0; i < a_nNumRows; ++i) {
			for(int j = 0; j < a_nNumCols; ++j) {
				int nRow = rand() % a_nNumRows;
				int nCol = rand() % a_nNumCols;

				int nTemp = a_pnBoard[i][j];
				a_pnBoard[i][j] = a_pnBoard[nRow][nCol];
				a_pnBoard[nRow][nCol] = nTemp;
			}
		}
	}

	/** 보드를 출력한다 */
	void PrintBoard(int(*a_pnVals)[50], int a_nNumRows, int a_nNumCols) {
		for(int i = 0; i < a_nNumRows; ++i) {
			for(int j = 0; j < a_nNumCols; ++j) {
				// 공백 일 경우
				if(a_pnVals[i][j] == 0) {
					printf("%4c", ' ');
				} else {
					printf("%4d", a_pnVals[i][j]);
				}
			}

			printf("\n");
		}
	}

	/** 정답 여부를 검사한다 */
	int IsAnswer(int(*a_pnVals)[50], int(*a_pnAnswer)[50], int a_nNumRows, int a_nNumCols) {
		for(int i = 0; i < a_nNumRows; ++i) {
			for(int j = 0; j < a_nNumCols; ++j) {
				// 값이 다를 경우
				if(a_pnVals[i][j] != a_pnAnswer[i][j]) {
					return 0;
				}
			}
		}

		return 1;
	}
#elif defined S06_03

#endif // #if defined S06_01

	int Solve_06(int argc, char* args[]) {
#if defined S06_01
		int anVals[4] = { 0 };
		int anAnswer[4] = { 0 };

		const int nSize = sizeof(anAnswer) / sizeof(anAnswer[0]);

		SetupAnswer(anAnswer, nSize);
		printf("정답 : %d, %d, %d, %d\n\n", anAnswer[0], anAnswer[1], anAnswer[2], anAnswer[3]);

		while(!IsAnswer(anVals, anAnswer, nSize)) {
			printf("숫자 (4 개) 입력 : ");
			scanf("%d %d %d %d", &anVals[0], &anVals[1], &anVals[2], &anVals[3]);

			int nNumBalls = 0;
			int nNumStrikes = 0;

			for(int i = 0; i < nSize; ++i) {
				int nIdx = FindVal(anAnswer, nSize, anVals[i]);

				nNumBalls += nIdx >= 0 && i != nIdx;
				nNumStrikes += nIdx >= 0 && i == nIdx;
			}

			printf("결과 : %d Strike, %d Ball\n\n", nNumStrikes, nNumBalls);
		}
#elif defined S06_02
		int anVals[50][50] = { 0 };
		int anAnswer[50][50] = { 0 };

		int nNumRows = 0;
		int nNumCols = 0;

		printf("너비, 높이 입력 : ");
		scanf("%d %d", &nNumCols, &nNumRows);

		SetupBoard(anVals, nNumRows, nNumCols);

		memcpy(anAnswer, anVals, sizeof(anVals));
		ShuffleBoard(anVals, nNumRows, nNumCols);

		while(!IsAnswer(anVals, anAnswer, nNumRows, nNumCols)) {
			PrintBoard(anVals, nNumRows, nNumCols);

			int nRow = 0;
			int nCol = 0;

			printf("\n위치 입력 : ");
			scanf("%d %d", &nRow, &nCol);

			int anRowOffsets[] = {
				0, 0, 1, -1
			};

			int anColOffsets[] = {
				1, -1, 0, 0
			};

			const int nSize = sizeof(anRowOffsets) / sizeof(anRowOffsets[0]);

			for(int i = 0; i < nSize; ++i) {
				int nNearRow = nRow + anRowOffsets[i];
				int nNearCol = nCol + anColOffsets[i];

				// 범위를 벗어났을 경우
				if(nNearRow < 0 || nNearRow >= nNumRows || nNearCol < 0 || nNearCol >= nNumCols) {
					continue;
				}

				// 공백이 존재 할 경우
				if(anVals[nNearRow][nNearCol] == 0) {
					int nTemp = anVals[nRow][nCol];
					anVals[nRow][nCol] = anVals[nNearRow][nNearCol];
					anVals[nNearRow][nNearCol] = nTemp;

					break;
				}
			}

			printf("\n");
		}
#elif defined S06_03
		int nNumRows = 0;
		int nNumCols = 0;

		int anVals[50][50] = { 0 };

		printf("행, 열 개수 입력 : ");
		scanf("%d %d", &nNumRows, &nNumCols);

		int i = 0;
		int j = -1;

		int nVal = 0;
		int nDirection = 1;

		int nOriginNumRows = nNumRows;
		int nOriginNumCols = nNumCols;

		while(nVal < nOriginNumRows * nOriginNumCols) {
			for(int k = 0; k < nNumCols; ++k) {
				j += nDirection;
				anVals[i][j] = nVal++;
			}

			nNumRows -= 1;

			for(int k = 0; k < nNumRows; ++k) {
				i += nDirection;
				anVals[i][j] = nVal++;
			}

			nNumCols -= 1;
			nDirection = -nDirection;
		}

		for(int i = 0; i < nOriginNumRows; ++i) {
			for(int j = 0; j < nOriginNumCols; ++j) {
				printf("%4d", anVals[i][j]);
			}

			printf("\n");
		}
#endif // #if defined S06_01

		return 0;
	}
}
