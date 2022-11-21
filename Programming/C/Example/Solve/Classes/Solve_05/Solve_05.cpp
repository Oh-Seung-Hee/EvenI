#include "Solve_05.h"

//#define S05_01
//#define S05_02
//#define S05_03
#define S05_04

namespace S05 {
	int Solve_05(int argc, char* args[]) {
#if defined S05_01
		int nNumLines = 0;

		printf("라인 수 입력 : ");
		scanf("%d", &nNumLines);

		for(int i = 0; i < nNumLines; ++i) {
			for(int j = 0; j <= i; ++j) {
				printf("*");
			}

			printf("\n");
		}
#elif defined S05_02
		int nNumLines = 0;

		printf("라인 수 입력 : ");
		scanf("%d", &nNumLines);

		for(int i = 0; i < nNumLines; ++i) {
			for(int j = 0; j < nNumLines; ++j) {
				printf("%c", (j <= i) ? '*' : ' ');
			}

			printf("\n");
		}

		printf("\n");

		for(int i = 0; i < nNumLines; ++i) {
			for(int j = nNumLines - 1; j >= 0; --j) {
				printf("%c", (j <= i) ? '*' : ' ');
			}

			printf("\n");
		}

		printf("\n");

		for(int i = nNumLines - 1; i >= 0; --i) {
			for(int j = 0; j < nNumLines; ++j) {
				printf("%c", (j <= i) ? '*' : ' ');
			}

			printf("\n");
		}

		printf("\n");

		for(int i = nNumLines - 1; i >= 0; --i) {
			for(int j = nNumLines - 1; j >= 0; --j) {
				printf("%c", (j <= i) ? '*' : ' ');
			}

			printf("\n");
		}
#elif defined S05_03
		int nNumLines = 0;

		printf("라인 수 입력 : ");
		scanf("%d", &nNumLines);

		int nWidth = (nNumLines * 2) - 1;

		for(int i = 0; i < nNumLines; ++i) {
			int nCenter = nWidth / 2;

			for(int j = 0; j < nWidth; ++j) {
				printf("%c", (j >= nCenter - i && j <= nCenter + i) ? '*' : ' ');
			}

			printf("\n");
		}
#elif defined S05_04
		int nNumLines = 0;

		printf("라인 수 입력 : ");
		scanf("%d", &nNumLines);

		// 홀수 일 경우
		if(nNumLines & 0x01) {
			for(int i = 0; i < nNumLines; ++i) {
				int nCenter = nNumLines / 2;

				for(int j = 0; j < nNumLines; ++j) {
					int nOffset = (i <= nCenter) ? i : nCenter - (i - nCenter);
					printf("%c", (j >= nCenter - nOffset && j <= nCenter + nOffset) ? '*' : ' ');
				}

				printf("\n");
			}
		}
#endif // #if defined S05_01

		return 0;
	}
}
