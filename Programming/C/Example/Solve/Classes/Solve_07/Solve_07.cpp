#include "Solve_07.h"

//#define S07_01
//#define S07_02
#define S07_03

namespace S07 {
#if defined S07_01
	/** 피보나치 값을 반환한다 */
	int GetFibonacci(int a_nVal) {
		if(a_nVal <= 0) {
			return 0;
		}

		return (a_nVal == 1) ? 1 : GetFibonacci(a_nVal - 1) + GetFibonacci(a_nVal - 2);
	}
#elif defined S07_02
	/** 값을 설정한다 */
	void SetupVals(int a_pnVals[], int a_nSize) {
		for(int i = 0; i < a_nSize; ++i) {
			a_pnVals[i] = rand() % 100;
		}
	}

	/** 합계를 반환한다 */
	int GetSumVal(int a_pnVals[], int a_nSize) {
		if(a_nSize <= 1) {
			return a_pnVals[0];
		}

		return a_pnVals[0] + GetSumVal(a_pnVals + 1, a_nSize - 1);
	}
#elif defined S07_03
	/** 경로를 탐색한다 */
	int FindPath(char(*a_pchMap)[9], int a_nNumRows, int a_nNumCols, int a_nPosX, int a_nPosY) {
		// 맵을 벗어났을 경우
		if(a_nPosX < 0 || a_nPosX >= a_nNumCols || a_nPosY < 0 || a_nPosY >= a_nNumRows) {
			return 0;
		}

		// 이동이 불가능 할 경우
		if(a_pchMap[a_nPosY][a_nPosX] == '*' || a_pchMap[a_nPosY][a_nPosX] == '#') {
			return 0;
		}

		// 목적지에 도착했을 경우
		if(a_pchMap[a_nPosY][a_nPosX] == 'E') {
			return 1;
		}

		char chPrevLetter = a_pchMap[a_nPosY][a_nPosX];
		a_pchMap[a_nPosY][a_nPosX] = (chPrevLetter != 'S' && chPrevLetter != '#') ? '*' : chPrevLetter;

		int anXOffsets[] = {
			1, -1, 0, 0
		};

		int anYOffsets[] = {
			0, 0, 1, -1
		};

		const int nSize = sizeof(anXOffsets) / sizeof(anXOffsets[0]);

		for(int i = 0; i < nSize; ++i) {
			// 탐색에 성공했을 경우
			if(FindPath(a_pchMap, a_nNumRows, a_nNumCols, a_nPosX + anXOffsets[i], a_nPosY + anYOffsets[i])) {
				return 1;
			}
		}

		a_pchMap[a_nPosY][a_nPosX] = chPrevLetter;
		return 0;
	}

	/** 맵을 출력한다 */
	void PrintMap(char(*a_pchMap)[9], int a_nNumRows, int a_nNumCols) {
		for(int i = 0; i < a_nNumRows; ++i) {
			for(int j = 0; j < a_nNumCols; ++j) {
				printf("%c", a_pchMap[i][j]);
			}

			printf("\n");
		}
	}
#endif // #if defined S07_01

	int Solve_07(int argc, char* args[]) {
#if defined S07_01
		int nNumVals = 0;

		printf("개수 입력 : ");
		scanf("%d", &nNumVals);

		printf("결과 : ");

		for(int i = 0; i < nNumVals; ++i) {
			printf("%d, ", GetFibonacci(i));
		}

		printf("\n");
#elif defined S07_02
		int nSize = 0;
		int anVals[50] = { 0 };

		printf("개수 입력 : ");
		scanf("%d", &nSize);

		SetupVals(anVals, nSize);
		printf("=====> 배열 요소 <=====\n");

		for(int i = 0; i < nSize; ++i) {
			printf("%d, ", anVals[i]);
		}

		printf("\n\n합계 : %d\n", GetSumVal(anVals, nSize));
#elif defined S07_03
		char achMap[][9] = {
			'#', '#', '#', '#', 'S', '#', '#', '#', '#',
			'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
			'#', '#', '#', ' ', ' ', '#', '#', '#', '#',
			'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#',
			'#', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#',
			'#', '#', ' ', '#', ' ', '#', ' ', ' ', '#',
			'#', '#', 'E', '#', '#', '#', '#', '#', '#'
		};

		const int nNumRows = sizeof(achMap) / sizeof(achMap[0]);
		const int nNumCols = sizeof(achMap[0]) / sizeof(achMap[0][0]);

		printf("=====> 탐색 전 <=====\n");
		PrintMap(achMap, nNumRows, nNumCols);

		FindPath(achMap, nNumRows, nNumCols, 4, 0);

		printf("\n=====> 탐색 후 <=====\n");
		PrintMap(achMap, nNumRows, nNumCols);
#endif // #if defined S07_01

		return 0;
	}
}
