#include "Practice_04.h"

#define P04_01
#define P04_02

namespace P04 {
	int Practice_04(int argc, char* args[]) {
#if defined P04_01
		int score;

		printf("당신의 학점을 입력하세요.\n");
		scanf("%d", &score);
		printf("당신의 학점은 ");

		if(score >= 90) {
			printf("A");

			if(score % 10 >= 7) {
				printf("%c입니다.\n", 43);
			} else if(score % 10 >= 4) {
				printf("%d입니다.\n", 0);
			} else {
				printf("%c입니다.\n", 45);
			}
		} else if(score >= 80) {
			printf("B");

			if(score % 10 >= 7) {
				printf("%c입니다.\n", 43);
			} else if(score % 10 >= 4) {
				printf("%d입니다.\n", 0);
			} else {
				printf("%c입니다.\n", 45);
			}
		} else if(score >= 70) {
			printf("C");

			if(score % 10 >= 7) {
				printf("%c입니다.\n", 43);
			} else if(score % 10 >= 4) {
				printf("%d입니다.\n", 0);
			} else {
				printf("%c입니다.\n", 45);
			}
		} else if(score >= 60) {
			printf("D");

			if(score % 10 >= 7) {
				printf("%c입니다.\n", 43);
			} else if(score % 10 >= 4) {
				printf("%d입니다.\n", 0);
			} else {
				printf("%c입니다.\n", 45);
			}
		} else {
			printf("F입니다.\n");
		}

#elif defined P04_02
		int score;

		printf("당신의 학점을 입력하세요.\n");
		scanf("%d", &score);
		printf("당신의 학점은 ");

		switch(score % 100 / 10) {
			case 10:
				printf("A+");
				break;
			case 9:
				printf("A");

				switch(score % 10) {
					case 9:
					case 8:
					case 7:
						printf("%c입니다.\n", 43);
						break;
					case 6:
					case 5:
					case 4:
						printf("%d입니다.\n", 0);
						break;
					case 3:
					case 2:
					case 1:
					case 0:
						printf("%c입니다.\n", 45);
						break;
				}
				break;
			case 8:
				printf("B");

				switch(score % 10) {
					case 9:
					case 8:
					case 7:
						printf("%c입니다.\n", 43);
						break;
					case 6:
					case 5:
					case 4:
						printf("%d입니다.\n", 0);
						break;
					case 3:
					case 2:
					case 1:
					case 0:
						printf("%c입니다.\n", 45);
						break;
				}
				break;
			case 7:
				printf("C");

				switch(score % 10) {
					case 9:
					case 8:
					case 7:
						printf("%c입니다.\n", 43);
						break;
					case 6:
					case 5:
					case 4:
						printf("%d입니다.\n", 0);
						break;
					case 3:
					case 2:
					case 1:
					case 0:
						printf("%c입니다.\n", 45);
						break;
				}
				break;
			case 6:
				printf("D");

				switch(score % 10) {
					case 9:
					case 8:
					case 7:
						printf("%c입니다.\n", 43);
						break;
					case 6:
					case 5:
					case 4:
						printf("%d입니다.\n", 0);
						break;
					case 3:
					case 2:
					case 1:
					case 0:
						printf("%c입니다.\n", 45);
						break;
				}
				break;
			case 5:
			case 4:
			case 3:
			case 2:
			case 1:
			case 0:
				printf("F입니다.");
				break;
		}

#endif // #if defined P04_01

		return 0;
	}
}
