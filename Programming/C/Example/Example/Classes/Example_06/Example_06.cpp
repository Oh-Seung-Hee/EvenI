#include "Example_06.h"

//#define E06_SINGLE
#define E06_MULTI

namespace E06 {
	int Example_06(int argc, char* args[]) {
#if defined E06_SINGLE
		int anVals01[5] = {
			1, 2, 3, 4, 5
		};

		int anVals02[5] = {
			1, 2, 3
		};

		int anVals03[] = {
			1, 2, 3
		};

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

		int anVals02[3][3] = {
			{ 1 }, { 2 }, { 3 }
		};

		int anVals03[3][3] = {
			1, 2, 3
		};

		int anVals04[][3] = {
			1, 2, 3
		};

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
