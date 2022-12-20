#include "Solve_10.h"

//#define S10_01
//#define S10_02
#define S10_03

namespace S10 {
#if defined S10_01

#elif defined S10_02
	/** 위치 */
	struct STPos {
		int m_nX;
		int m_nY;
	};

	/** 크기 */
	struct STSize {
		int m_nWidth;
		int m_nHeight;
	};

	/** 값을 교환한다 */
	void Swap(int* a_pnVal01, int* a_pnVal02) {
		int nTemp = *a_pnVal01;
		*a_pnVal01 = *a_pnVal02;
		*a_pnVal02 = nTemp;
	}

	/** 값을 설정한다 */
	void SetupVals(int* a_pnVals, STSize a_stSize) {
		for(int i = 0; i < a_stSize.m_nWidth * a_stSize.m_nHeight; ++i) {
			a_pnVals[i] = i;
		}
	}

	/** 값을 재배치한다 */
	void ShuffleVals(int* a_pnVals, STSize a_stSize) {
		for(int i = 0; i < a_stSize.m_nWidth * a_stSize.m_nHeight; ++i) {
			Swap(a_pnVals + i, a_pnVals + (rand() % (a_stSize.m_nWidth * a_stSize.m_nHeight)));
		}
	}

	/** 값을 출력한다 */
	void PrintVals(int* a_pnVals, STSize a_stSize) {
		for(int i = 0; i < a_stSize.m_nHeight; ++i) {
			for(int j = 0; j < a_stSize.m_nWidth; ++j) {
				int nIdx = (i * a_stSize.m_nWidth) + j;

				// 공백 일 경우
				if(a_pnVals[nIdx] == 0) {
					printf("%4c", ' ');
				} else {
					printf("%4d", a_pnVals[nIdx]);
				}
			}

			printf("\n");
		}
	}
#elif defined S10_03

#endif // #if defined S10_01

	int Solve_10(int argc, char* args[]) {
#if defined S10_01
		int nVal = 0;
		int nSize = 5;

		int nNumOddVals = 0;
		int nNumEvenVals = 0;

		int* pnVals = (int*)malloc(sizeof(int) * nSize);

		do {
			printf("정수 입력 : ");
			scanf("%d", &nVal);

			// 값이 유효 할 경우
			if(nVal != 0) {
				// 홀수 일 경우
				if(nVal % 2 != 0) {
					pnVals[nNumOddVals] = nVal;
					nNumOddVals += 1;
				} else {
					pnVals[nSize - (nNumEvenVals + 1)] = nVal;
					nNumEvenVals += 1;
				}

				// 배열이 가득 찼을 경우
				if(nNumOddVals + nNumEvenVals >= nSize) {
					int nNewSize = nSize * 2;
					int* pnNewVals = (int*)malloc(sizeof(int) * nNewSize);

					for(int i = 0; i < nNumOddVals; ++i) {
						pnNewVals[i] = pnVals[i];
					}

					for(int i = nNumEvenVals - 1; i >= 0; --i) {
						pnNewVals[nNewSize - (i + 1)] = pnVals[nSize - (i + 1)];
					}

					free(pnVals);

					nSize = nNewSize;
					pnVals = pnNewVals;
				}
			}
		} while(nVal != 0);

		printf("\n=====> 결과 <=====\n");

		for(int i = 0; i < nNumOddVals; ++i) {
			printf("%d, ", pnVals[i]);
		}

		for(int i = nNumEvenVals - 1; i >= 0; --i) {
			printf("%d, ", pnVals[nSize - (i + 1)]);
		}

		printf("\n");
		free(pnVals);
#elif defined S10_02
		STSize stSize = { 0 };

		printf("너비, 높이 입력 : ");
		scanf("%d %d", &stSize.m_nWidth, &stSize.m_nHeight);

		int* pnVals = (int*)malloc(sizeof(int) * (stSize.m_nWidth * stSize.m_nHeight));
		int* pnAnswerVals = (int*)malloc(sizeof(int) * (stSize.m_nWidth * stSize.m_nHeight));

		SetupVals(pnVals, stSize);
		memcpy(pnAnswerVals, pnVals, sizeof(int) * (stSize.m_nWidth * stSize.m_nHeight));

		ShuffleVals(pnVals, stSize);

		while(memcmp(pnVals, pnAnswerVals, sizeof(int) * (stSize.m_nWidth * stSize.m_nHeight)) != 0) {
			STPos stPos = { 0 };
			PrintVals(pnVals, stSize);

			printf("\n위치 입력 : ");
			scanf("%d %d", &stPos.m_nY, &stPos.m_nX);

			STPos astOffsets[] = {
				{ 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
			};

			for(int i = 0; i < sizeof(astOffsets) / sizeof(astOffsets[0]); ++i) {
				STPos stAroundPos = {
					stPos.m_nX + astOffsets[i].m_nX, stPos.m_nY + astOffsets[i].m_nY
				};

				// 범위를 벗어났을 경우
				if(stAroundPos.m_nX < 0 || stAroundPos.m_nX >= stSize.m_nWidth || stAroundPos.m_nY < 0 || stAroundPos.m_nY >= stSize.m_nHeight) {
					continue;
				}

				int nIdx = (stAroundPos.m_nY * stSize.m_nWidth) + stAroundPos.m_nX;

				// 공백이 존재 할 경우
				if(pnVals[nIdx] == 0) {
					Swap(pnVals + nIdx, pnVals + ((stPos.m_nY * stSize.m_nWidth) + stPos.m_nX));
					break;
				}
			}

			printf("\n");
		}

		free(pnVals);
		free(pnAnswerVals);
#elif defined S10_03
		int nNumRows = 0;
		int nNumCols = 0;

		printf("행, 열 개수 입력 : ");
		scanf("%d %d", &nNumRows, &nNumCols);

		int i = 0;
		int j = -1;

		int nVal = 0;
		int nDirection = 1;

		int nOriginNumRows = nNumRows;
		int nOriginNumCols = nNumCols;

		int* pnVals = (int*)malloc(sizeof(int) * (nNumRows * nNumCols));

		while(nVal < nOriginNumRows * nOriginNumCols) {
			for(int k = 0; k < nNumCols; ++k) {
				j += nDirection;
				pnVals[(i * nOriginNumCols) + j] = nVal++;
			}

			nNumRows -= 1;

			for(int k = 0; k < nNumRows; ++k) {
				i += nDirection;
				pnVals[(i * nOriginNumCols) + j] = nVal++;
			}

			nNumCols -= 1;
			nDirection = -nDirection;
		}

		for(int i = 0; i < nOriginNumRows; ++i) {
			for(int j = 0; j < nOriginNumCols; ++j) {
				printf("%4d", pnVals[(i * nOriginNumCols) + j]);
			}

			printf("\n");
		}

		free(pnVals);
#endif // #if defined S10_01

		return 0;
	}
}
