#include "Practice_05.h"

//#define P05_01
//#define P05_02
//#define P05_03
#define P05_04

namespace P05 {
	int Practice_05(int argc, char* args[]) {
#if defined P05_01
		int line;

		printf("몇 줄을 출력할까요? ");
		scanf("%d", &line);

		for(int i = 0; i < line; i++) {
			for(int j = 0; j <= i; j++) {
				printf("*");
			}
			printf("\n");
		}

#elif defined P05_02
		int line, shape;

		printf("몇 줄을 출력할까요? ");
		scanf("%d", &line);
		printf("어떤 방식으로 출력할까요? (해당 숫자를 입력해주세요.)\n");
		printf("1. 기본\t 2. 좌우반전\t3. 상하반전\t4. 상하+좌우반전\t\n");
		scanf("%d", &shape);

		switch(shape) {
			case 1:	// 1. 기본
				for(int i = 0; i < line; i++) {
					for(int j = 0; j <= i; j++) {
						printf("*");
					}
					printf("\n");
				}
				break;
			case 2:	// 2. 좌우반전
				for(int i = 0; i < line; i++) {
					for(int j = 1; j < line - i; j++) {
						printf(" ");
					}
					for(int j = 0; j <= i; j++) {
						printf("*");
					}
					printf("\n");
				}
				break;
			case 3:	// 3. 상하반전
				for(int i = 0; i < line; i++) {
					for(int j = 0; j < line - i; j++) {
						printf("*");
					}
					printf("\n");
				}
				break;
			case 4:	// 4. 상하+좌우반전
				for(int i = 0; i < line; i++) {
					for(int j = 0; j < i; j++) {
						printf(" ");
					}
					for(int j = 0; j < line - i; j++) {
						printf("*");
					}
					printf("\n");
				}
				break;
		}

#elif defined P05_03
		int line;

		printf("몇 줄을 출력할까요? ");
		scanf("%d", &line);

		for(int i = 0; i < line; i++) {
			for(int j = 1; j < line - i; j++) {
				printf(" ");
			}
			for(int j = 0; j <= 2 * i; j++) {
				printf("*");
			}
			printf("\n");
		}

#elif defined P05_04
		int line;

		printf("몇 줄을 출력할까요? (홀수만 입력하세요.) ");
		scanf("%d", &line);

		if(line % 2 == 1) {
			for(int i = 0; i <= line / 2; i++) {
				for(int j = 1; j <= line / 2 - i; j++) {
					printf(" ");
				}
				for(int j = 0; j <= 2 * i; j++) {
					printf("*");
				}
				printf("\n");
			}
			for(int i = 0; i < line / 2; i++) {
				for(int j = 0; j < i + 1; j++) {
					printf(" ");
				}
				for(int j = 0; j < line - 2 * (i + 1); j++) {
					printf("*");
				}
				printf("\n");
			}
		} else {
			printf("짝수를 입력하셨습니다.");
		}

#endif // #if defined P05_01

		return 0;
	}
}
