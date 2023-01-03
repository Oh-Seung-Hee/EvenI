//#define P04_01
#define P04_02

#include "Solve_04.h"

namespace S04 {
	int Solve_04(int argc, char* args[]) {
#if defined P04_01
		int nScore = 0;

		printf("점수 입력 : ");
		scanf("%d", &nScore);

		if(nScore < 60) {
			printf("F");
		} else {
			if(nScore >= 90) {
				printf("A");
			} else if(nScore >= 80) {
				printf("B");
			} else if(nScore >= 70) {
				printf("C");
			} else {
				printf("D");
			}

			if(nScore >= 100 || nScore % 10 >= 7) {
				printf("+");
			} else if(nScore % 10 <= 3) {
				printf("-");
			} else {
				printf("0");
			}
		}

		printf(" 학점 입니다.\n");
#elif defined P04_02
		int nScore = 0;

		printf("점수 입력 : ");
		scanf("%d", &nScore);

		switch(nScore / 10) {
			case 6: case 7: case 8: case 9: case 10:
			{
				switch(nScore / 10) {
					case 9: case 10: printf("A"); break;
					case 8: printf("B"); break;
					case 7: printf("C"); break;
					default: printf("D"); break;
				}

				switch(nScore % 10) {
					case 1: case 2: case 3: printf("-"); break;
					case 4: case 5: case 6: printf("0"); break;
					case 7: case 8: case 9: printf("+"); break;
					default:
					{
						switch(nScore / 100) {
							case 0: printf("-"); break;
							default: printf("+"); break;
						}

						break;
					}
				}

				break;
			}
			default: printf("F"); break;
		}

		printf(" 학점 입니다.\n");
#endif // #if defined P04_01

		return 0;
	}
}
